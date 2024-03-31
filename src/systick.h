#pragma once

#include <stdint.h>
#include "util.h"


typedef struct systick_t {
    volatile uint32_t CSR, RVR, CVR, CALIB;
} systick_t;

typedef enum systick_clksource_enum {
    SYST_CLKSOURCE_EXT, SYST_CLKSOURCE_CPU
} systick_clksource_t;


static systick_t *SYST = (systick_t*)0xe000e010;


static inline void systick_set_clk_src(systick_clksource_t src) {
    SET_BIT(SYST->CSR, 2, src);
}

static inline void systick_enable_tickint(uint8_t enable) {
    SET_BIT(SYST->CSR, 1, enable > 0);
}

static inline void systick_enable(uint8_t enable) {
    SET_BIT(SYST->CSR, 0, enable > 0);
}

static inline void systick_set_reload(uint32_t reload) {
    SYST->RVR = reload & 0xffffff;
}

static inline uint32_t systick_cnt(void) {
    return SYST->CVR;
}

