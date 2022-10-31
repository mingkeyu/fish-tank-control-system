/* -----------------------------------------------------------------------------
 * Copyright (c) 2020 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdio.h>
#include "cmsis_os2.h"
//#include "main.h"
#include "port_common.h"
extern void app_initialize (void);
extern void idle_initialize(void);
extern void st7789_lcd_initialize(void);
extern int32_t socket_startup (void);
extern int32_t demo (void);
extern int st7789_lcd_thread();
static const osThreadAttr_t app_main_attr = {
  .stack_size = 4096U
};
static const osThreadAttr_t app_idle_attr = {
        .stack_size = 128U
};
static const osThreadAttr_t app_st7789_lcd_attr = {
        .stack_size = 4096U
};

/*-----------------------------------------------------------------------------
 * Application main thread
 *----------------------------------------------------------------------------*/
static void app_main (void *argument) {
  int32_t status;

  printf("TCP Client Demo\r\n");

  status = socket_startup();
  if (status == 0) {
    demo();
  }
}

/*-----------------------------------------------------------------------------
 * Application initialization
 *----------------------------------------------------------------------------*/
void app_initialize (void) {
  osThreadNew(app_main, NULL, &app_main_attr);
}

/*-----------------------------------------------------------------------------
 * Application main thread
 *----------------------------------------------------------------------------*/
static void app_idle (void *argument) {

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (1) {
        gpio_put(LED_PIN, 1);
        osDelay(250);
        gpio_put(LED_PIN, 0);
        osDelay(250);
    }
}

void idle_initialize(void){
    osThreadNew(app_idle, NULL, &app_idle_attr);
}
static void app_st7789_lcd (void *argument) {
    st7789_lcd_thread();
}
void st7789_lcd_initialize(void){
    osThreadNew(app_st7789_lcd, NULL, &app_st7789_lcd_attr);
}


