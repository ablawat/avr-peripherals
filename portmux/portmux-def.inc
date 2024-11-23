;***********************************************************************************************************************
;** Port Multiplexer - Control A - Definitions                                                                        **
;***********************************************************************************************************************

; CTRLA - CCL LUT 1 Output
.EQU PORTMUX_CTRLA_LUT1_CLR = 0
.EQU PORTMUX_CTRLA_LUT1_SET = 1

; CCL LUT 1 Output Configuration Options
.EQU PORTMUX_CCL_LUT1_PIN_DEFAULT     = (PORTMUX_CTRLA_LUT1_CLR << PORTMUX_LUT1_bp)
.EQU PORTMUX_CCL_LUT1_PIN_ALTERNATIVE = (PORTMUX_CTRLA_LUT1_SET << PORTMUX_LUT1_bp)

; CTRLA - CCL LUT 0 Output
.EQU PORTMUX_CTRLA_LUT0_CLR = 0
.EQU PORTMUX_CTRLA_LUT0_SET = 1

; CCL LUT 0 Output Configuration Options
.EQU PORTMUX_CCL_LUT0_PIN_DEFAULT     = (PORTMUX_CTRLA_LUT0_CLR << PORTMUX_LUT0_bp)
.EQU PORTMUX_CCL_LUT0_PIN_ALTERNATIVE = (PORTMUX_CTRLA_LUT0_SET << PORTMUX_LUT0_bp)

; CTRLA - Event Output 2
.EQU PORTMUX_CTRLA_EVOUT2_CLR = 0
.EQU PORTMUX_CTRLA_EVOUT2_SET = 1

; Event Output 2 Configuration Options
.EQU PORTMUX_EVENT_OUTPUT2_DISABLED = (PORTMUX_CTRLA_EVOUT2_CLR << PORTMUX_EVOUT2_bp)
.EQU PORTMUX_EVENT_OUTPUT2_ENABLED  = (PORTMUX_CTRLA_EVOUT2_SET << PORTMUX_EVOUT2_bp)

; CTRLA - Event Output 1
.EQU PORTMUX_CTRLA_EVOUT1_CLR = 0
.EQU PORTMUX_CTRLA_EVOUT1_SET = 1

; Event Output 1 Configuration Options
.EQU PORTMUX_EVENT_OUTPUT1_DISABLED = (PORTMUX_CTRLA_EVOUT1_CLR << PORTMUX_EVOUT1_bp)
.EQU PORTMUX_EVENT_OUTPUT1_ENABLED  = (PORTMUX_CTRLA_EVOUT1_SET << PORTMUX_EVOUT1_bp)

; CTRLA - Event Output 0
.EQU PORTMUX_CTRLA_EVOUT0_CLR = 0
.EQU PORTMUX_CTRLA_EVOUT0_SET = 1

; Event Output 0 Configuration Options
.EQU PORTMUX_EVENT_OUTPUT0_DISABLED = (PORTMUX_CTRLA_EVOUT0_CLR << PORTMUX_EVOUT0_bp)
.EQU PORTMUX_EVENT_OUTPUT0_ENABLED  = (PORTMUX_CTRLA_EVOUT0_SET << PORTMUX_EVOUT0_bp)

;***********************************************************************************************************************
;** Port Multiplexer - Control B - Definitions                                                                        **
;***********************************************************************************************************************

; CTRLB - TWI0 Communication
.EQU PORTMUX_CTRLB_TWI0_CLR = 0
.EQU PORTMUX_CTRLB_TWI0_SET = 1

; TWI0 Communication Configuration Options
.EQU PORTMUX_TWI0_PIN_DEFAULT     = (PORTMUX_CTRLB_TWI0_CLR << PORTMUX_TWI0_bp)
.EQU PORTMUX_TWI0_PIN_ALTERNATIVE = (PORTMUX_CTRLB_TWI0_SET << PORTMUX_TWI0_bp)

; CTRLB - SPI0 Communication
.EQU PORTMUX_CTRLB_SPI0_CLR = 0
.EQU PORTMUX_CTRLB_SPI0_SET = 1

; SPI0 Communication Configuration Options
.EQU PORTMUX_SPI0_PIN_DEFAULT     = (PORTMUX_CTRLB_SPI0_CLR << PORTMUX_SPI0_bp)
.EQU PORTMUX_SPI0_PIN_ALTERNATIVE = (PORTMUX_CTRLB_SPI0_SET << PORTMUX_SPI0_bp)

; CTRLB - USART0 Communication
.EQU PORTMUX_CTRLB_USART0_CLR = 0
.EQU PORTMUX_CTRLB_USART0_SET = 1

; USART0 Communication Configuration Options
.EQU PORTMUX_USART0_PIN_DEFAULT     = (PORTMUX_CTRLB_USART0_CLR << PORTMUX_USART0_bp)
.EQU PORTMUX_USART0_PIN_ALTERNATIVE = (PORTMUX_CTRLB_USART0_SET << PORTMUX_USART0_bp)

;***********************************************************************************************************************
;** Port Multiplexer - Control C - Definitions                                                                        **
;***********************************************************************************************************************

; CTRLC - TCA0 Waveform Output 5
.EQU PORTMUX_CTRLC_TCA05_CLR = 0
.EQU PORTMUX_CTRLC_TCA05_SET = 1

; TCA0 Waveform Output 5 Configuration Options
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT5_PIN_DEFAULT     = (PORTMUX_CTRLC_TCA05_CLR << PORTMUX_TCA05_bp)
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT5_PIN_ALTERNATIVE = (PORTMUX_CTRLC_TCA05_SET << PORTMUX_TCA05_bp)

; CTRLC - TCA0 Waveform Output 4
.EQU PORTMUX_CTRLC_TCA04_CLR = 0
.EQU PORTMUX_CTRLC_TCA04_SET = 1

; TCA0 Waveform Output 4 Configuration Options
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT4_PIN_DEFAULT     = (PORTMUX_CTRLC_TCA04_CLR << PORTMUX_TCA04_bp)
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT4_PIN_ALTERNATIVE = (PORTMUX_CTRLC_TCA04_SET << PORTMUX_TCA04_bp)

; CTRLC - TCA0 Waveform Output 3
.EQU PORTMUX_CTRLC_TCA03_CLR = 0
.EQU PORTMUX_CTRLC_TCA03_SET = 1

; TCA0 Waveform Output 3 Configuration Options
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT3_PIN_DEFAULT     = (PORTMUX_CTRLC_TCA03_CLR << PORTMUX_TCA03_bp)
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT3_PIN_ALTERNATIVE = (PORTMUX_CTRLC_TCA03_SET << PORTMUX_TCA03_bp)

; CTRLC - TCA0 Waveform Output 2
.EQU PORTMUX_CTRLC_TCA02_CLR = 0
.EQU PORTMUX_CTRLC_TCA02_SET = 1

; TCA0 Waveform Output 2 Configuration Options
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT2_PIN_DEFAULT     = (PORTMUX_CTRLC_TCA02_CLR << PORTMUX_TCA02_bp)
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT2_PIN_ALTERNATIVE = (PORTMUX_CTRLC_TCA02_SET << PORTMUX_TCA02_bp)

; CTRLC - TCA0 Waveform Output 1
.EQU PORTMUX_CTRLC_TCA01_CLR = 0
.EQU PORTMUX_CTRLC_TCA01_SET = 1

; TCA0 Waveform Output 1 Configuration Options
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT1_PIN_DEFAULT     = (PORTMUX_CTRLC_TCA01_CLR << PORTMUX_TCA01_bp)
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT1_PIN_ALTERNATIVE = (PORTMUX_CTRLC_TCA01_SET << PORTMUX_TCA01_bp)

; CTRLC - TCA0 Waveform Output 0
.EQU PORTMUX_CTRLC_TCA00_CLR = 0
.EQU PORTMUX_CTRLC_TCA00_SET = 1

; TCA0 Waveform Output 0 Configuration Options
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT0_PIN_DEFAULT     = (PORTMUX_CTRLC_TCA00_CLR << PORTMUX_TCA00_bp)
.EQU PORTMUX_TCA0_WAVEFORM_OUTPUT0_PIN_ALTERNATIVE = (PORTMUX_CTRLC_TCA00_SET << PORTMUX_TCA00_bp)

;***********************************************************************************************************************
;** Port Multiplexer - Control D - Definitions                                                                        **
;***********************************************************************************************************************

; CTRLD - TCB0 Waveform Output
.EQU PORTMUX_CTRLD_TCB0_CLR = 0
.EQU PORTMUX_CTRLD_TCB0_SET = 1

; TCB0 Waveform Output Configuration Options
.EQU PORTMUX_TCB0_WAVEFORM_OUTPUT_PIN_DEFAULT     = (PORTMUX_CTRLD_TCB0_CLR << PORTMUX_TCB0_bp)
.EQU PORTMUX_TCB0_WAVEFORM_OUTPUT_PIN_ALTERNATIVE = (PORTMUX_CTRLD_TCB0_SET << PORTMUX_TCB0_bp)
