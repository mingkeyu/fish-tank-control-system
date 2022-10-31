/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <math.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/gpio.h"
#include "hardware/interp.h"
#include "cmsis_os2.h"
#include "st7789_lcd.pio.h"
//#include "0_256x256_rgb565.h"
#include "1_256x256_rgb565.h"
#include "2_256x256_rgb565.h"
#include "3_256x256_rgb565.h"
#include "4_256x256_rgb565.h"
#include "5_256x256_rgb565.h"
#include "6_256x256_rgb565.h"
#include "7_256x256_rgb565.h"
#include "8_256x256_rgb565.h"
//#include "9_256x256_rgb565.h"
//#include "10_256x256_rgb565.h"
//#include "11_256x256_rgb565.h"
//#include "12_256x256_rgb565.h"
//#include "13_256x256_rgb565.h"
//#include "14_256x256_rgb565.h"
//#include "15_256x256_rgb565.h"
#include "rotary_encoder.h"
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240
#define IMAGE_SIZE 256
#define LOG_IMAGE_SIZE 8

#define PIN_DIN 19
#define PIN_CLK 18
#define PIN_CS 17
#define PIN_DC 15
#define PIN_RESET 13
#define PIN_BL 21

#define SERIAL_CLK_DIV 1.f

// Format: cmd length (including cmd byte), post delay in units of 5 ms, then cmd payload
// Note the delays have been shortened a little
static const uint8_t st7789_init_seq[] = {
        1, 20, 0x01,                         // Software reset
        1, 10, 0x11,                         // Exit sleep mode
        2, 2, 0x3a, 0x55,                   // Set colour mode to 16 bit
        2, 0, 0x36, 0x00,                   // Set MADCTL: row then column, refresh is bottom to top ????
        5, 0, 0x2a, 0x00, 0x00, 0x00, 0xf0, // CASET: column addresses from 0 to 240 (f0)
        5, 0, 0x2b, 0x00, 0x00, 0x00, 0xf0, // RASET: row addresses from 0 to 240 (f0)
        1, 2, 0x21,                         // Inversion on, then 10 ms delay (supposedly a hack?)
        1, 2, 0x13,                         // Normal display on, then 10 ms delay
        1, 2, 0x29,                         // Main screen turn on, then wait 500 ms
        0                                     // Terminate list
};

static inline void lcd_set_dc_cs(bool dc, bool cs) {
    sleep_us(1);
    gpio_put_masked((1u << PIN_DC) | (1u << PIN_CS), !!dc << PIN_DC | !!cs << PIN_CS);
    sleep_us(1);
}

static inline void lcd_write_cmd(PIO pio, uint sm, const uint8_t *cmd, size_t count) {
    st7789_lcd_wait_idle(pio, sm);
    lcd_set_dc_cs(0, 0);
    st7789_lcd_put(pio, sm, *cmd++);
    if (count >= 2) {
        st7789_lcd_wait_idle(pio, sm);
        lcd_set_dc_cs(1, 0);
        for (size_t i = 0; i < count - 1; ++i)
            st7789_lcd_put(pio, sm, *cmd++);
    }
    st7789_lcd_wait_idle(pio, sm);
    lcd_set_dc_cs(1, 1);
}

static inline void lcd_init(PIO pio, uint sm, const uint8_t *init_seq) {
    const uint8_t *cmd = init_seq;
    while (*cmd) {
        lcd_write_cmd(pio, sm, cmd + 2, *cmd);
        sleep_ms(*(cmd + 1) * 5);
        cmd += *cmd + 2;
    }
}

static inline void st7789_start_pixels(PIO pio, uint sm) {
    uint8_t cmd = 0x2c; // RAMWR
    lcd_write_cmd(pio, sm, &cmd, 1);
    lcd_set_dc_cs(1, 0);
}
u_char number = 1;
int st7789_lcd_thread() {
    stdio_init_all();
u_char key_value = 0;u_char temp_number = 0;
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &st7789_lcd_program);
    st7789_lcd_program_init(pio, sm, offset, PIN_DIN, PIN_CLK, SERIAL_CLK_DIV);

    gpio_init(PIN_CS);
    gpio_init(PIN_DC);
    gpio_init(PIN_RESET);
    gpio_init(PIN_BL);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_set_dir(PIN_DC, GPIO_OUT);
    gpio_set_dir(PIN_RESET, GPIO_OUT);
    gpio_set_dir(PIN_BL, GPIO_OUT);

    gpio_put(PIN_CS, 1);
    gpio_put(PIN_RESET, 1);
    lcd_init(pio, sm, st7789_init_seq);
    gpio_put(PIN_BL, 1);

    // Other SDKs: static image on screen, lame, boring
    // Raspberry Pi Pico SDK: spinning image on screen, bold, exciting

    // Lane 0 will be u coords (bits 8:1 of addr offset), lane 1 will be v
    // coords (bits 16:9 of addr offset), and we'll represent coords with
    // 16.16 fixed point. ACCUM0,1 will contain current coord, BASE0/1 will
    // contain increment vector, and BASE2 will contain image base pointer
#define UNIT_LSB 16
    interp_config lane0_cfg = interp_default_config();
    interp_config_set_shift(&lane0_cfg, UNIT_LSB - 1); // -1 because 2 bytes per pixel
    interp_config_set_mask(&lane0_cfg, 1, 1 + (LOG_IMAGE_SIZE - 1));
    interp_config_set_add_raw(&lane0_cfg, true); // Add full accumulator to base with each POP
    interp_config lane1_cfg = interp_default_config();
    interp_config_set_shift(&lane1_cfg, UNIT_LSB - (1 + LOG_IMAGE_SIZE));
    interp_config_set_mask(&lane1_cfg, 1 + LOG_IMAGE_SIZE, 1 + (2 * LOG_IMAGE_SIZE - 1));
    interp_config_set_add_raw(&lane1_cfg, true);

    interp_set_config(interp0, 0, &lane0_cfg);
    interp_set_config(interp0, 1, &lane1_cfg);
    osDelay(1000);
    key_scan_init();
    while (1) {
#if 1
        key_value = 0;
        key_value = ec11_action_analysis();
        if(2 == key_value){
            if(number<8)
                number++;
            else
                number = 1;
            temp_number = number;
        }else if(3 == key_value){
            if(number>1)
                number--;
            else
                number = 8;
            temp_number = number;
        }
     //   osDelay(10);
#endif
#if 0
        if(number<8)
            number++;
        else
            number = 0;
#endif

        switch (number) {
            //case 0:
            //    interp0->base[2] = (uint32_t) image_0_256x256;
            //    break;
            case 1:
                interp0->base[2] = (uint32_t) image_1_256x256;
                break;
            case 2:
                interp0->base[2] = (uint32_t) image_2_256x256;
                break;
            case 3:
                interp0->base[2] = (uint32_t) image_3_256x256;
                break;
            case 4:
                interp0->base[2] = (uint32_t) image_4_256x256;
                break;
            case 5:
                interp0->base[2] = (uint32_t) image_5_256x256;
                break;
            case 6:
                interp0->base[2] = (uint32_t) image_6_256x256;
                break;
            case 7:
                interp0->base[2] = (uint32_t) image_7_256x256;
                break;
            case 8:
                interp0->base[2] = (uint32_t) image_8_256x256;
                break;
        //    case 9:
        //        interp0->base[2] = (uint32_t) image_9_256x256;
        //        break;
        //    case 10:
        //        interp0->base[2] = (uint32_t) image_10_256x256;
        //        break;
        //    case 11:
        //        interp0->base[2] = (uint32_t) image_11_256x256;
        //        break;
        //    case 12:
        //        interp0->base[2] = (uint32_t) image_12_256x256;
        //        break;
        //    case 13:
        //        interp0->base[2] = (uint32_t) image_13_256x256;
        //        break;
        //    case 14:
        //        interp0->base[2] = (uint32_t) image_14_256x256;
        //        break;
        //    case 15:
        //        interp0->base[2] = (uint32_t) image_15_256x256;
        //        break;
        }
    float theta = 0.f;
    float theta_max = 2.f * (float) M_PI;
   // theta += 0.02f;
   // if (theta > theta_max)
    //    theta -= theta_max;
    int32_t rotate[4] = {
            cosf(theta) * (1 << UNIT_LSB), -sinf(theta) * (1 << UNIT_LSB),
            sinf(theta) * (1 << UNIT_LSB), cosf(theta) * (1 << UNIT_LSB)
    };
        interp0->base[0] = rotate[0];
           interp0->base[1] = rotate[2];
    st7789_start_pixels(pio, sm);
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
            interp0->accum[0] = rotate[1] * y;
            interp0->accum[1] = rotate[3] * y;
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            uint16_t colour = *(uint16_t *) (interp0->pop[2]);
            st7789_lcd_put(pio, sm, colour >> 8);
            st7789_lcd_put(pio, sm, colour & 0xff);
        }
    }

        osDelay(10);
#if 0
        theta += 0.02f;
        if (theta > theta_max)
            theta -= theta_max;
        int32_t rotate[4] = {
                cosf(theta) * (1 << UNIT_LSB), -sinf(theta) * (1 << UNIT_LSB),
                sinf(theta) * (1 << UNIT_LSB), cosf(theta) * (1 << UNIT_LSB)
        };
//        interp0->base[0] = rotate[0];
 //       interp0->base[1] = rotate[2];
        st7789_start_pixels(pio, sm);
        for (int y = 0; y < SCREEN_HEIGHT; ++y) {
//            interp0->accum[0] = rotate[1] * y;
//            interp0->accum[1] = rotate[3] * y;
            for (int x = 0; x < SCREEN_WIDTH; ++x) {
                uint16_t colour = *(uint16_t *) (interp0->pop[2]);
                st7789_lcd_put(pio, sm, colour >> 8);
                st7789_lcd_put(pio, sm, colour & 0xff);
            }
        }
#endif
    }
}
