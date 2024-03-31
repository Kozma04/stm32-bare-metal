#include "time.h"


void time_init(void) {
    systick_set_clk_src(SYST_CLKSOURCE_CPU);
    systick_set_reload(15999);
    systick_enable_tickint(1);
    systick_enable(1);
    rcc_apb2_set(APB2_SYSCFG, RCC_PER_CLKEN);
}

uint32_t time_ms(void) {
    return g_time_cnt_ms;
}

void time_delay(uint32_t ms) {
    uint32_t end = g_time_cnt_ms + ms + 1;
    while(g_time_cnt_ms < end);
}