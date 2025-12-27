;**********************************************************************************************;
; @description : Port Multiplexer Peripheral Definition                                        ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "portmux/define/portmux-register.inc"

.INCLUDE "macro/registers.inc"
.INCLUDE "macro/config.inc"

;**********************************************************************************************;
; @section : Configuration Option Definition                                                   ;
;**********************************************************************************************;

; @brief Port Multiplexer - CCL LUT 1 Output
.EQU PORTMUX_CCL_LUT1_PIN_DEFAULT     = PORTMUX_CTRLA_LUT1_DEF
.EQU PORTMUX_CCL_LUT1_PIN_ALTERNATIVE = PORTMUX_CTRLA_LUT1_ALT

; @brief Port Multiplexer - CCL LUT 0 Output
.EQU PORTMUX_CCL_LUT0_PIN_DEFAULT     = PORTMUX_CTRLA_LUT0_DEF
.EQU PORTMUX_CCL_LUT0_PIN_ALTERNATIVE = PORTMUX_CTRLA_LUT0_ALT

; @brief Port Multiplexer - Event Output 2
.EQU PORTMUX_EVENT_OUTPUT2_DISABLED = PORTMUX_CTRLA_EVOUT2_OFF
.EQU PORTMUX_EVENT_OUTPUT2_ENABLED  = PORTMUX_CTRLA_EVOUT2_ON

; @brief Port Multiplexer - Event Output 1
.EQU PORTMUX_EVENT_OUTPUT1_DISABLED = PORTMUX_CTRLA_EVOUT1_OFF
.EQU PORTMUX_EVENT_OUTPUT1_ENABLED  = PORTMUX_CTRLA_EVOUT1_ON

; @brief Port Multiplexer - Event Output 0
.EQU PORTMUX_EVENT_OUTPUT0_DISABLED = PORTMUX_CTRLA_EVOUT0_OFF
.EQU PORTMUX_EVENT_OUTPUT0_ENABLED  = PORTMUX_CTRLA_EVOUT0_ON

; @brief Port Multiplexer - TWI0 Communication
.EQU PORTMUX_TWI0_PIN_DEFAULT     = PORTMUX_CTRLB_TWI0_DEF
.EQU PORTMUX_TWI0_PIN_ALTERNATIVE = PORTMUX_CTRLB_TWI0_ALT

; @brief Port Multiplexer - SPI0 Communication
.EQU PORTMUX_SPI0_PIN_DEFAULT     = PORTMUX_CTRLB_SPI0_DEF
.EQU PORTMUX_SPI0_PIN_ALTERNATIVE = PORTMUX_CTRLB_SPI0_ALT

; @brief Port Multiplexer - USART0 Communication
.EQU PORTMUX_USART0_PIN_DEFAULT     = PORTMUX_CTRLB_USART0_DEF
.EQU PORTMUX_USART0_PIN_ALTERNATIVE = PORTMUX_CTRLB_USART0_ALT

; @brief Port Multiplexer - TCA0 Waveform Output 5
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT5_PIN_DEFAULT     = PORTMUX_CTRLC_TCA05_DEF
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT5_PIN_ALTERNATIVE = PORTMUX_CTRLC_TCA05_ALT

; @brief Port Multiplexer - TCA0 Waveform Output 4
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT4_PIN_DEFAULT     = PORTMUX_CTRLC_TCA04_DEF
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT4_PIN_ALTERNATIVE = PORTMUX_CTRLC_TCA04_ALT

; @brief Port Multiplexer - TCA0 Waveform Output 3
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT3_PIN_DEFAULT     = PORTMUX_CTRLC_TCA03_DEF
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT3_PIN_ALTERNATIVE = PORTMUX_CTRLC_TCA03_ALT

; @brief Port Multiplexer - TCA0 Waveform Output 2
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT2_PIN_DEFAULT     = PORTMUX_CTRLC_TCA02_DEF
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT2_PIN_ALTERNATIVE = PORTMUX_CTRLC_TCA02_ALT

; @brief Port Multiplexer - TCA0 Waveform Output 1
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT1_PIN_DEFAULT     = PORTMUX_CTRLC_TCA01_DEF
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT1_PIN_ALTERNATIVE = PORTMUX_CTRLC_TCA01_ALT

; @brief Port Multiplexer - TCA0 Waveform Output 0
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT0_PIN_DEFAULT     = PORTMUX_CTRLC_TCA00_DEF
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT0_PIN_ALTERNATIVE = PORTMUX_CTRLC_TCA00_ALT

; @brief Port Multiplexer - TCB0 Waveform Output
.EQU PORTMUX_TCB0_WAVEFORM_OUTPUT_PIN_DEFAULT     = PORTMUX_CTRLD_TCB0_DEF
.EQU PORTMUX_TCB0_WAVEFORM_OUTPUT_PIN_ALTERNATIVE = PORTMUX_CTRLD_TCB0_ALT
