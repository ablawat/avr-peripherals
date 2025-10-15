;***********************************************************************************************************************
;** Clock Controller Peripheral Register Definitions                                                                  **
;***********************************************************************************************************************

;***********************************************************************************************************************
;** MCLKCTRLA - Main Clock Control A - Definitions                                                                    **
;***********************************************************************************************************************

; MCLKCTRLA - System Clock Out
.EQU CLKCTRL_MCLKCTRLA_CLKOUT_OFF = 0
.EQU CLKCTRL_MCLKCTRLA_CLKOUT_ON  = 1

; MCLKCTRLA - Clock Select
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_OSC20M    = 0 ; 16/20 MHz internal oscillator
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_OSCULP32K = 1 ; 32.768 kHz internal ultra low-power oscillator
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_XOSC32K   = 2 ; 32.768 kHz external crystal oscillator
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_EXTCLK    = 3 ; external clock

;***********************************************************************************************************************
;** MCLKCTRLB - Main Clock Control B - Definitions                                                                    **
;***********************************************************************************************************************

; MCLKCTRLB - Prescaler Division
.EQU CLKCTRL_MCLKCTRLB_PDIV_2  = 0  ; clock division by 2
.EQU CLKCTRL_MCLKCTRLB_PDIV_4  = 1  ; clock division by 4
.EQU CLKCTRL_MCLKCTRLB_PDIV_8  = 2  ; clock division by 8
.EQU CLKCTRL_MCLKCTRLB_PDIV_16 = 3  ; clock division by 16
.EQU CLKCTRL_MCLKCTRLB_PDIV_32 = 4  ; clock division by 32
.EQU CLKCTRL_MCLKCTRLB_PDIV_64 = 5  ; clock division by 64
.EQU CLKCTRL_MCLKCTRLB_PDIV_6  = 8  ; clock division by 6
.EQU CLKCTRL_MCLKCTRLB_PDIV_10 = 9  ; clock division by 10
.EQU CLKCTRL_MCLKCTRLB_PDIV_12 = 10 ; clock division by 12
.EQU CLKCTRL_MCLKCTRLB_PDIV_24 = 11 ; clock division by 24
.EQU CLKCTRL_MCLKCTRLB_PDIV_48 = 12 ; clock division by 48

; MCLKCTRLB - Prescaler Enable
.EQU CLKCTRL_MCLKCTRLB_PEN_OFF = 0
.EQU CLKCTRL_MCLKCTRLB_PEN_ON  = 1

;***********************************************************************************************************************
;** MCLKLOCK - Main Clock Lock - Definitions                                                                          **
;***********************************************************************************************************************

; MCLKLOCK - Lock Enable
.EQU CLKCTRL_MCLKLOCK_LOCKEN_OFF = 0
.EQU CLKCTRL_MCLKLOCK_LOCKEN_ON  = 1

;***********************************************************************************************************************
;** MCLKSTATUS - Main Clock Status - Definitions                                                                      **
;***********************************************************************************************************************

; MCLKSTATUS - External Clock Status - Bit Position
.EQU CLKCTRL_EXTS_BPOS     = CLKCTRL_EXTS_bp

; MCLKSTATUS - 32.768 kHz External Crystal Oscillator Status - Bit Position
.EQU CLKCTRL_XOSC32KS_BPOS = CLKCTRL_XOSC32KS_bp

; MCLKSTATUS - 32.768 kHz Internal Ultra Low-Power Oscillator Status - Bit Position
.EQU CLKCTRL_OSC32KS_BPOS  = CLKCTRL_OSC32KS_bp

; MCLKSTATUS - 16/20 MHz Internal Oscillator Status - Bit Position
.EQU CLKCTRL_OSC20MS_BPOS  = CLKCTRL_OSC20MS_bp
