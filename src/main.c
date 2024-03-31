#include <stdint.h>
#include "peripherals.h"
#include "driver/time.c"
#include "sysint.h"

volatile uint32_t tickcnt;

int main(void) {
    rcc_ahb1_set(AHB1_GPIOI, RCC_PER_CLKEN);
    gpio_set_mode(GPIO_PORT_I, 1, GPIO_MODE_OUT);

    time_init();

    while(1) {
        gpio_toggle(GPIO_PORT_I, 1);
        //for(uint32_t i = 0; i < 400000; i++) __asm__("nop");
        uint32_t start = tickcnt;
        while(tickcnt < start + 1000);
    }

    return 0;
}

void __attribute__((naked, noreturn)) _reset(void) {
    extern uint32_t _sbss, _ebss, _sdata, _edata, _sidata;
    for (uint32_t *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
    for (uint32_t *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;

    main();
    for(;;) (void) 0;
}

extern void _estack(void);  // Defined in link.ld

__attribute__((section(".vectors"))) void (*const tab[16 + 98])(void) = {
    _estack,
    _reset,
    _handle_nmi,
    _handle_hardfault,
    _handle_memmanage_fault,
    _handle_busfault,
    _handle_usagefault,
    0,
    0,
    0,
    0,
    _handle_svcall,
    _handle_debugmonitor,
    0,
    _handle_pendsv,
    _handle_systick,
    _handle_wwdg,
    _handle_pvd,
    _handle_tamp_stamp,
    _handle_rtc_wkup,
    _handle_flash,
    _handle_rcc,
    _handle_exti0,
    _handle_exti1,
    _handle_exti2,
    _handle_exti3,
    _handle_exti4,
    _handle_dma1_stream0,
    _handle_dma1_stream1,
    _handle_dma1_stream2,
    _handle_dma1_stream3,
    _handle_dma1_stream4,
    _handle_dma1_stream5,
    _handle_dma1_stream6,
    _handle_adc,
    _handle_can1_tx,
    _handle_can1_rx0,
    _handle_can1_rx1,
    _handle_can1_sce,
    _handle_exti9_5,
    _handle_tim1_brk_tim9,
    _handle_tim1_up_tim10,
    _handle_tim1_trg_com_tim11,
    _handle_tim1_cc,
    _handle_tim2,
    _handle_tim3,
    _handle_tim4,
    _handle_i2c1_ev,
    _handle_i2c1_er,
    _handle_i2c2_ev,
    _handle_i2c2_er,
    _handle_spi1,
    _handle_spi2,
    _handle_usart1,
    _handle_usart2,
    _handle_usart3,
    _handle_exti15_10,
    _handle_rtc_alarm,
    _handle_otg_fs_wkup,
    _handle_tim8_brk_tim12,
    _handle_tim8_up_tim13,
    _handle_tim8_trg_com_tim14,
    _handle_tim8_cc,
    _handle_dma1_stream7,
    _handle_fsmc,
    _handle_sdmmc1,
    _handle_tim5,
    _handle_spi3,
    _handle_uart4,
    _handle_uart5,
    _handle_tim6_dac,
    _handle_tim7,
    _handle_dma2_stream0,
    _handle_dma2_stream1,
    _handle_dma2_stream2,
    _handle_dma2_stream3,
    _handle_dma2_stream4,
    _handle_eth,
    _handle_eth_wkup,
    _handle_can2_tx,
    _handle_can2_rx0,
    _handle_can2_rx1,
    _handle_can2_sce,
    _handle_otg_fs,
    _handle_dma2_stream5,
    _handle_dma2_stream6,
    _handle_dma2_stream7,
    _handle_usart6,
    _handle_i2c3_ev,
    _handle_i2c3_er,
    _handle_otg_hs_ep1_out,
    _handle_otg_hs_ep1_in,
    _handle_otg_hs_wkup,
    _handle_otg_hs,
    _handle_dcmi,
    _handle_cryp,
    _handle_hash_rng,
    _handle_fpu,
    _handle_uart7,
    _handle_uart8,
    _handle_spi4,
    _handle_spi5,
    _handle_spi6,
    _handle_sai1,
    _handle_lcd_tft,
    _handle_lcd_tft_er,
    _handle_dma2d,
    _handle_sai2,
    _handle_quadspi,
    _handle_lp_timer_1,
    _handle_hdmi_cec,
    _handle_i2c4_ev,
    _handle_i2c4_er,
    _handle_spdifrx
};