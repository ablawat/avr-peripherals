;**********************************************************************************************;
; @description : Port Multiplexer Header                                                       ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "portmux/config/portmux-config.inc"

;**********************************************************************************************;
; @section : Register Configuration                                                            ;
;**********************************************************************************************;

; CTRLA - CCL LUT 1 Output
.EQU CONFIG_PORTMUX_CTRLA_LUT1   = CONFIG_PORTMUX_CCL_LUT1_PIN

; CTRLA - CCL LUT 0 Output
.EQU CONFIG_PORTMUX_CTRLA_LUT0   = CONFIG_PORTMUX_CCL_LUT0_PIN

; CTRLA - Event Output 2
.EQU CONFIG_PORTMUX_CTRLA_EVOUT2 = CONFIG_PORTMUX_EVENT_OUTPUT2

; CTRLA - Event Output 1
.EQU CONFIG_PORTMUX_CTRLA_EVOUT1 = CONFIG_PORTMUX_EVENT_OUTPUT1

; CTRLA - Event Output 0
.EQU CONFIG_PORTMUX_CTRLA_EVOUT0 = CONFIG_PORTMUX_EVENT_OUTPUT0

; @brief PORTMUX Control A Register
.EQU CONFIG_PORTMUX_CTRLA = (CONFIG_PORTMUX_CTRLA_LUT1   << PORTMUX_LUT1_bp  ) | \
                            (CONFIG_PORTMUX_CTRLA_LUT0   << PORTMUX_LUT0_bp  ) | \
                            (CONFIG_PORTMUX_CTRLA_EVOUT2 << PORTMUX_EVOUT2_bp) | \
                            (CONFIG_PORTMUX_CTRLA_EVOUT1 << PORTMUX_EVOUT1_bp) | \
                            (CONFIG_PORTMUX_CTRLA_EVOUT0 << PORTMUX_EVOUT0_bp)

; CTRLB - TWI0 Communication
.EQU CONFIG_PORTMUX_CTRLB_TWI0   = CONFIG_PORTMUX_TWI0_PIN

; CTRLB - SPI0 Communication
.EQU CONFIG_PORTMUX_CTRLB_SPI0   = CONFIG_PORTMUX_SPI0_PIN

; CTRLB - USART0 Communication
.EQU CONFIG_PORTMUX_CTRLB_USART0 = CONFIG_PORTMUX_USART0_PIN

; @brief PORTMUX Control B Register
.EQU CONFIG_PORTMUX_CTRLB = (CONFIG_PORTMUX_CTRLB_TWI0   << PORTMUX_TWI0_bp  ) | \
                            (CONFIG_PORTMUX_CTRLB_SPI0   << PORTMUX_SPI0_bp  ) | \
                            (CONFIG_PORTMUX_CTRLB_USART0 << PORTMUX_USART0_bp)

; CTRLC - TCA0 Waveform Output 5
.EQU CONFIG_PORTMUX_CTRLC_TCA05 = CONFIG_PORTMUX_TCA0_WAVEFORM_OUTPUT5_PIN

; CTRLC - TCA0 Waveform Output 4
.EQU CONFIG_PORTMUX_CTRLC_TCA04 = CONFIG_PORTMUX_TCA0_WAVEFORM_OUTPUT4_PIN

; CTRLC - TCA0 Waveform Output 3
.EQU CONFIG_PORTMUX_CTRLC_TCA03 = CONFIG_PORTMUX_TCA0_WAVEFORM_OUTPUT3_PIN

; CTRLC - TCA0 Waveform Output 2
.EQU CONFIG_PORTMUX_CTRLC_TCA02 = CONFIG_PORTMUX_TCA0_WAVEFORM_OUTPUT2_PIN

; CTRLC - TCA0 Waveform Output 1
.EQU CONFIG_PORTMUX_CTRLC_TCA01 = CONFIG_PORTMUX_TCA0_WAVEFORM_OUTPUT1_PIN

; CTRLC - TCA0 Waveform Output 0
.EQU CONFIG_PORTMUX_CTRLC_TCA00 = CONFIG_PORTMUX_TCA0_WAVEFORM_OUTPUT0_PIN

; @brief PORTMUX Control C Register
.EQU CONFIG_PORTMUX_CTRLC = (CONFIG_PORTMUX_CTRLC_TCA05 << PORTMUX_TCA05_bp) | \
                            (CONFIG_PORTMUX_CTRLC_TCA04 << PORTMUX_TCA04_bp) | \
                            (CONFIG_PORTMUX_CTRLC_TCA03 << PORTMUX_TCA03_bp) | \
                            (CONFIG_PORTMUX_CTRLC_TCA02 << PORTMUX_TCA02_bp) | \
                            (CONFIG_PORTMUX_CTRLC_TCA01 << PORTMUX_TCA01_bp) | \
                            (CONFIG_PORTMUX_CTRLC_TCA00 << PORTMUX_TCA00_bp)

; CTRLD - TCB0 Waveform Output
.EQU CONFIG_PORTMUX_CTRLD_TCB0 = CONFIG_PORTMUX_TCB0_WAVEFORM_OUTPUT_PIN

; @brief PORTMUX Control D Register
.EQU CONFIG_PORTMUX_CTRLD = (CONFIG_PORTMUX_CTRLD_TCB0 << PORTMUX_TCB0_bp)
