#pragma once

#include "util.h"
#include <stdint.h>


typedef struct rcc_t {
    volatile uint32_t CR, PLLCFGR, CFGR, CIR, AHB1RSTR, AHB2RSTR, AHB3RSTR, RESERVED0, APB1RSTR, APB2RSTR, RESERVED1[2],
    AHB1ENR, AHB2ENR, AHB3ENR, RESERVED2, APB1ENR, APB2ENR, RESERVED3[2], AHB1LPENR, AHB2LPENR, AHB3LPENR, RESERVED4,
    APB1LPENR, APB2LPENR, RESERVED5[2], BDCR, CSR, RESERVED6[2], SSCGR, PLLI2SCFGR, PLLSAICFGR, DCKCFGR1, DCKCFGR2;
} rcc_t;

typedef enum rcc_apb1_per_enum {
    APB1_TIM2, APB1_TIM3, APB1_TIM4, APB1_TIM5, APB1_TIM6, APB1_TIM7, APB1_TIM12, APB1_TIM13, APB1_TIM14, APB1_LPTIM1, APB1_RESERVED0,
    APB1_WWDG, APB1_RESERVED1, APB1_RESERVED2, APB1_SPI2, APB1_SPI3, APB1_SPDIFRX, APB1_UART2, APB1_UART3, APB1_UART4, APB1_UART5,
    APB1_I2C1, APB1_I2C2, APB1_I2C3, APB1_I2C4, APB1_CAN1, APB1_CAN2, APB1_CEC, APB1_PWR, APB1_DAC, APB1_UART7, APB1_UART8
} rcc_apb1_per_t;

typedef enum rcc_apb2_per_enum {
    APB2_TIM1 = 0, APB2_TIM8 = 1, APB2_USART1 = 4, APB2_USART6 = 5, APB2_ADC = 8, 
    APB2_SDMMC1 = 11, APB2_SPI1 = 12, APB2_SP45 = 13, APB2_SYSCFG = 14, APB2_TIM9 = 16,
    APB2_TIM10 = 17, APB2_TIM11 = 18, APB2_SPI5 = 20, APB2_SPI6 = 21, APB2_SAI1 = 22,
    APB2_SAI2 = 23, APB2_LTDC = 26
} rcc_apb2_per_t;

typedef enum rcc_ahb1_per_enum {
    AHB1_GPIOA = 0, AHB1_GPIOB = 1, AHB1_GPIOC = 2, AHB1_GPIOD = 3, AHB1_GPIOE = 4, AHB1_GPIOF = 5, AHB1_GPIOG = 6, AHB1_GPIOH = 7,
    AHB1_GPIOI = 8, AHB1_GPIOJ = 9, AHB1_GPIOK = 10, AHB1_CRC = 12, AHB1_BKPSRAM = 18, AHB1_DTCMRAM = 20, AHB1_DMA1 = 21, AHB1_DMA2 = 22,
    AHB1_DMA2D = 23, AHB1_ETHMAC = 25, AHB1_ETHMACTX = 26, AHB1_ETHMACRX = 27, AHB1_ETHMACPTP = 28, AHB1_OTGHS = 29, AHB1_OTGHSULP = 30
} rcc_ahb1_per_t;

typedef enum rcc_ahb2_per_enum {
    AHB2_DCMI = 0, AHB2_CRYP = 4, AHB2_HASH = 5, AHB2_RNG = 6, AHB2_OTGFS = 7
} rcc_ahb2_per_t;

typedef enum rcc_ahb3_per_enum {
    AHB3_FMC = 0, AHB3_QSPI = 1
} rcc_ahb3_per_t;


typedef enum rcc_per_action_enum {
    RCC_PER_RESET, RCC_PER_RUN_IN_LOWPOWER, RCC_PER_CLKEN
} rcc_per_action_t;


static rcc_t *RCC = (rcc_t*)0x40023800;


#define RCC_BUF_SET_PROTOTYPE(FUNC_NAME, PER_ENUM_NAME, RSTR, LPENR, ENR) \
    static inline void FUNC_NAME(PER_ENUM_NAME per, rcc_per_action_t action) { \
        switch(action) { \
            case RCC_PER_RESET: RCC->RSTR |= BIT(per); break; \
            case RCC_PER_RUN_IN_LOWPOWER: RCC->LPENR |= BIT(per); break; \
            case RCC_PER_CLKEN: RCC->ENR |= BIT(per); break; \
            default: break; \
        } \
    }

RCC_BUF_SET_PROTOTYPE(rcc_apb1_set, rcc_apb1_per_t, APB1RSTR, APB1LPENR, APB1ENR)
RCC_BUF_SET_PROTOTYPE(rcc_apb2_set, rcc_apb2_per_t, APB2RSTR, APB2LPENR, APB2ENR)
RCC_BUF_SET_PROTOTYPE(rcc_ahb1_set, rcc_ahb1_per_t, AHB1RSTR, AHB1LPENR, AHB1ENR)
RCC_BUF_SET_PROTOTYPE(rcc_ahb2_set, rcc_ahb2_per_t, AHB2RSTR, AHB2LPENR, AHB2ENR)
RCC_BUF_SET_PROTOTYPE(rcc_ahb3_set, rcc_ahb3_per_t, AHB3RSTR, AHB3LPENR, AHB3ENR)

#undef RCC_BUF_SET_PROTOTYPE