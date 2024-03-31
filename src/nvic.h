#pragma once

#include <stdint.h>
#include "util.h"


// starting from position 0
typedef enum nvic_interrupt_enum {
    NVIC_NMI = -14,
    NVIC_MEMMANAGE = -12,
    NVIC_BUSFAULT = -11,
    NVIC_USAGEFAULT = -10,
    NVIC_SVCALL = -5,
    NVIC_DEBUGMONITOR = -4,
    NVIC_PENDSV = -2,
    NVIC_SYSTICK = -1,
    NVIC_WWDG = 0, NVIC_PVD, NVIC_TAMP_STAMP, NVIC_RTC_WKUP, NVIC_FLASH, NVIC_RCC, NVIC_EXTI0, NVIC_EXTI1, NVIC_EXTI2, NVIC_EXTI3, NVIC_EXTI4,
    NVIC_DMA1_STREAM0, NVIC_DMA1_STREAM1, NVIC_DMA1_STREAM2, NVIC_DMA1_STREAM3, NVIC_DMA1_STREAM4, NVIC_DMA1_STREAM5, NVIC_DMA1_STREAM6,
    NVIC_ADC, NVIC_CAN1_TX, NVIC_CAN1_RX0, NVIC_CAN1_RX1, NVIC_CAN1_SCE, NVIC_EXTI9_5, NVIC_TIM1_BRK_TIM9, NVIC_TIM1_UP_TIM10, NVIC_TIM1_TRG_COM_TIM11,
    NVIC_TIM1_CC, NVIC_TIM2, NVIC_TIM3, NVIC_TIM4, NVIC_I2C1_EV, NVIC_I2C1_ER, NVIC_I2C2_EV, NVIC_I2C2_ER, NVIC_SPI1, NVIC_SPI2, NVIC_USART1,
    NVIC_USART2, NVIC_USART3, NVIC_EXTI15_10, NVIC_RTC_ALARM, NVIC_OTG_FS_WKUP, NVIC_TIM8_BRK_TIM12, NVIC_TIM8_UP_TIM13, NVIC_TIM8_TRG_COM_TIM14,
    NVIC_TIM8_CC, NVIC_DMA1_STREAM7, NVIC_FSMC, NVIC_SDMMC1, NVIC_TIM5, NVIC_SPI3, NVIC_UART4, NVIC_UART5, NVIC_TIM6_DAC, NVIC_TIM7,
    NVIC_DMA2_STREAM0, NVIC_DMA2_STREAM1, NVIC_DMA2_STREAM2, NVIC_DMA2_STREAM3, NVIC_DMA2_STREAM4, NVIC_ETH, NVIC_ETH_WKUP, NVIC_CAN2_TX,
    NVIC_CAN2_RX0, NVIC_CAN2_RX1, NVIC_CAN2_SCE, NVIC_OTG_FS, NVIC_DMA2_STREAM5, NVIC_DMA2_STREAM6, NVIC_DMA2_STREAM7, NVIC_USART6,
    NVIC_I2C3_EV, NVIC_I2C3_ER, NVIC_OTG_HS_EP1_OUT, NVIC_OTG_HS_EP1_IN, NVIC_OTG_HS_WKUP, NVIC_OTG_HS, NVIC_DCMI, NVIC_CRYP, NVIC_HASH_RNG,
    NVIC_FPU, NVIC_UART7, NVIC_UART8, NVIC_SPI4, NVIC_SPI5, NVIC_SPI6, NVIC_SAI1, NVIC_LCD_TFT, NVIC_LCD_TFT_ER, NVIC_DMA2D, NVIC_SAI2,
    NVIC_QUADSPI, NVIC_LP_TIMER_1, NVIC_HDMI_CEC, NVIC_I2C4_EV, NVIC_I2C4_ER, NVIC_SPDIFRX 
} nvic_interrupt_t;


// set-enable, 8 entries
static volatile uint32_t *NVIC_ISER_BASE = (volatile uint32_t*)0xe000e100;
// clear-enable, 8 entries
static volatile uint32_t *NVIC_ICER_BASE = (volatile uint32_t*)0xe000e180;
// set-pending, 8 entries
static volatile uint32_t *NVIC_ISPR_BASE = (volatile uint32_t*)0xe000e200;
// clear-pending, 8 entries
static volatile uint32_t *NVIC_ICPR_BASE = (volatile uint32_t*)0xe000e280;
// interrupt active, 8 entries
static volatile uint32_t *NVIC_IABR_BASE = (volatile uint32_t*)0xe000e300;
// priority, 60 entries
static volatile uint32_t *NVIC_IPR_BASE = (volatile uint32_t*)0xe000e400;
// software trigger interrupt
static volatile uint32_t *NVIC_STIR = (volatile uint32_t*)0xe000ef00;


static inline void nvic_set_enable_int(nvic_interrupt_t interrupt) {
    if(interrupt >= 0)
        NVIC_ISER_BASE[interrupt >> 5] = 1 << (interrupt & 31);
}

static inline void nvic_clear_enable_int(nvic_interrupt_t interrupt) {
    if(interrupt >= 0)
        NVIC_ICER_BASE[interrupt >> 5] = 1 << (interrupt & 31);
}

static inline void nvic_set_pending_int(nvic_interrupt_t interrupt) {
    if(interrupt >= 0)
        NVIC_ISPR_BASE[interrupt >> 5] = 1 << (interrupt & 31);
}

static inline void nvic_clear_pending_int(nvic_interrupt_t interrupt) {
    if(interrupt >= 0)
        NVIC_ICPR_BASE[interrupt >> 5] = 1 << (interrupt & 31);
}

static inline void nvic_set_priority_int(nvic_interrupt_t interrupt, uint8_t pri) {
    //uint8_t int_num = interrupt + 13;
    if(interrupt >= 0)
        SET_BITS(NVIC_IPR_BASE[interrupt >> 2], 4, 4 * (interrupt & 0b11), pri & 0xf);
}

// TODO NVIC_IABR0-7 wrappers

static inline void nvic_trigger_sw_int(nvic_interrupt_t interrupt) {
    if(interrupt >= 0)
        *NVIC_STIR = interrupt;
}