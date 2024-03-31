#include "sysint.h"
#include "driver/time.h"



void _handle_dummy(void) {}

void _handle_nmi(void) {}
void _handle_hardfault(void) {}
void _handle_memmanage_fault(void) {}
void _handle_busfault(void) {}
void _handle_usagefault(void) {}
void _handle_svcall(void) {}
void _handle_debugmonitor(void) {}
void _handle_pendsv(void) {}
void _handle_systick(void) {
    g_time_cnt_ms++;
}

void _handle_wwdg(void) {}
void _handle_pvd(void) {}
void _handle_tamp_stamp(void) {}
void _handle_rtc_wkup(void) {}
void _handle_flash(void) {}
void _handle_rcc(void) {}
void _handle_exti0(void) {}
void _handle_exti1(void) {}
void _handle_exti2(void) {}
void _handle_exti3(void) {}
void _handle_exti4(void) {}
void _handle_dma1_stream0(void) {}
void _handle_dma1_stream1(void) {}
void _handle_dma1_stream2(void) {}
void _handle_dma1_stream3(void) {}
void _handle_dma1_stream4(void) {}
void _handle_dma1_stream5(void) {}
void _handle_dma1_stream6(void) {}
void _handle_adc(void) {}
void _handle_can1_tx(void) {}
void _handle_can1_rx0(void) {}
void _handle_can1_rx1(void) {}
void _handle_can1_sce(void) {}
void _handle_exti9_5(void) {}
void _handle_tim1_brk_tim9(void) {}
void _handle_tim1_up_tim10(void) {}
void _handle_tim1_trg_com_tim11(void) {}
void _handle_tim1_cc(void) {}
void _handle_tim2(void) {}
void _handle_tim3(void) {}
void _handle_tim4(void) {}
void _handle_i2c1_ev(void) {}
void _handle_i2c1_er(void) {}
void _handle_i2c2_ev(void) {}
void _handle_i2c2_er(void) {}
void _handle_spi1(void) {}
void _handle_spi2(void) {}
void _handle_usart1(void) {}
void _handle_usart2(void) {}
void _handle_usart3(void) {}
void _handle_exti15_10(void) {}
void _handle_rtc_alarm(void) {}
void _handle_otg_fs_wkup(void) {}
void _handle_tim8_brk_tim12(void) {}
void _handle_tim8_up_tim13(void) {}
void _handle_tim8_trg_com_tim14(void) {}
void _handle_tim8_cc(void) {}
void _handle_dma1_stream7(void) {}
void _handle_fsmc(void) {}
void _handle_sdmmc1(void) {}
void _handle_tim5(void) {}
void _handle_spi3(void) {}
void _handle_uart4(void) {}
void _handle_uart5(void) {}
void _handle_tim6_dac(void) {}
void _handle_tim7(void) {}
void _handle_dma2_stream0(void) {}
void _handle_dma2_stream1(void) {}
void _handle_dma2_stream2(void) {}
void _handle_dma2_stream3(void) {}
void _handle_dma2_stream4(void) {}
void _handle_eth(void) {}
void _handle_eth_wkup(void) {}
void _handle_can2_tx(void) {}
void _handle_can2_rx0(void) {}
void _handle_can2_rx1(void) {}
void _handle_can2_sce(void) {}
void _handle_otg_fs(void) {}
void _handle_dma2_stream5(void) {}
void _handle_dma2_stream6(void) {}
void _handle_dma2_stream7(void) {}
void _handle_usart6(void) {}
void _handle_i2c3_ev(void) {}
void _handle_i2c3_er(void) {}
void _handle_otg_hs_ep1_out(void) {}
void _handle_otg_hs_ep1_in(void) {}
void _handle_otg_hs_wkup(void) {}
void _handle_otg_hs(void) {}
void _handle_dcmi(void) {}
void _handle_cryp(void) {}
void _handle_hash_rng(void) {}
void _handle_fpu(void) {}
void _handle_uart7(void) {}
void _handle_uart8(void) {}
void _handle_spi4(void) {}
void _handle_spi5(void) {}
void _handle_spi6(void) {}
void _handle_sai1(void) {}
void _handle_lcd_tft(void) {}
void _handle_lcd_tft_er(void) {}
void _handle_dma2d(void) {}
void _handle_sai2(void) {}
void _handle_quadspi(void) {}
void _handle_lp_timer_1(void) {}
void _handle_hdmi_cec(void) {}
void _handle_i2c4_ev(void) {}
void _handle_i2c4_er(void) {}
void _handle_spdifrx(void) {}