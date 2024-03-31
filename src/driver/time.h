#pragma once

#include <stdint.h>
#include "../peripherals.h"


static volatile uint32_t g_time_cnt_ms;

void time_init(void);
uint32_t time_ms(void);
void time_delay(uint32_t ms);