#ifndef __ROTARY_ENCODER_H
#define __ROTARY_ENCODER_H
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "task.h"
#include "hardware/gpio.h"
#include "hardware/interp.h"
#include "port_common.h"
void key_scan_init(void);
unsigned char ec11_action_analysis(void);
#endif
