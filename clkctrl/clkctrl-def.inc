;***********************************************************************************************************************
;** MCLKCTRLA - Main Clock Control A - Definitions                                                                    **
;***********************************************************************************************************************

; MCLKCTRLA - System Clock Out
.EQU CLKCTRL_MCLKCTRLA_CLKOUT_CLR = 0
.EQU CLKCTRL_MCLKCTRLA_CLKOUT_SET = 1

; System Clock Out Configuration Options
.EQU CLKCTRL_PERIPHERAL_CLOCK_OUT_DISABLED = (CLKCTRL_MCLKCTRLA_CLKOUT_CLR << CLKCTRL_CLKOUT_bp)
.EQU CLKCTRL_PERIPHERAL_CLOCK_OUT_ENABLED  = (CLKCTRL_MCLKCTRLA_CLKOUT_SET << CLKCTRL_CLKOUT_bp)

; MCLKCTRLA - Clock Select
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_OSC20M    = 0 ; 16/20 MHz internal oscillator
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_OSCULP32K = 1 ; 32.768 kHz internal ultra low-power oscillator
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_XOSC32K   = 2 ; 32.768 kHz external crystal oscillator
.EQU CLKCTRL_MCLKCTRLA_CLKSEL_EXTCLK    = 3 ; external clock

; Main Clock Select Configuration Options
.EQU CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_20M = (CLKCTRL_MCLKCTRLA_CLKSEL_OSC20M    << CLKCTRL_CLKSEL_gp)
.EQU CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_32K = (CLKCTRL_MCLKCTRLA_CLKSEL_OSCULP32K << CLKCTRL_CLKSEL_gp)
.EQU CLKCTRL_MAIN_CLOCK_SELECT_EXTERNAL_32K = (CLKCTRL_MCLKCTRLA_CLKSEL_XOSC32K   << CLKCTRL_CLKSEL_gp)
.EQU CLKCTRL_MAIN_CLOCK_SELECT_EXTERNAL     = (CLKCTRL_MCLKCTRLA_CLKSEL_EXTCLK    << CLKCTRL_CLKSEL_gp)

;***********************************************************************************************************************
;** MCLKCTRLB - Main Clock Control B - Definitions                                                                    **
;***********************************************************************************************************************

; MCLKCTRLB - Prescaler Enable
.EQU CLKCTRL_MCLKCTRLB_PEN_CLR = 0
.EQU CLKCTRL_MCLKCTRLB_PEN_SET = 1

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

; Main Clock Prescaler Division Configuration Options
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_1  = (CLKCTRL_MCLKCTRLB_PDIV_2  << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_CLR << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_2  = (CLKCTRL_MCLKCTRLB_PDIV_2  << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_4  = (CLKCTRL_MCLKCTRLB_PDIV_4  << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_6  = (CLKCTRL_MCLKCTRLB_PDIV_6  << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_8  = (CLKCTRL_MCLKCTRLB_PDIV_8  << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_10 = (CLKCTRL_MCLKCTRLB_PDIV_10 << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_12 = (CLKCTRL_MCLKCTRLB_PDIV_12 << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_16 = (CLKCTRL_MCLKCTRLB_PDIV_16 << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_24 = (CLKCTRL_MCLKCTRLB_PDIV_24 << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_32 = (CLKCTRL_MCLKCTRLB_PDIV_32 << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_48 = (CLKCTRL_MCLKCTRLB_PDIV_48 << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_64 = (CLKCTRL_MCLKCTRLB_PDIV_64 << CLKCTRL_PDIV_gp) | (CLKCTRL_MCLKCTRLB_PEN_SET << CLKCTRL_PEN_bp)

;***********************************************************************************************************************
;** MCLKLOCK - Main Clock Lock - Definitions                                                                          **
;***********************************************************************************************************************

; MCLKLOCK - Lock Enable
.EQU CLKCTRL_MCLKLOCK_LOCKEN_CLR = 0
.EQU CLKCTRL_MCLKLOCK_LOCKEN_SET = 1

; Main Clock Lock Configuration Options
.EQU CLKCTRL_MAIN_CLOCK_LOCK_DISABLED = (CLKCTRL_MCLKLOCK_LOCKEN_CLR << CLKCTRL_LOCKEN_bp)
.EQU CLKCTRL_MAIN_CLOCK_LOCK_ENABLED  = (CLKCTRL_MCLKLOCK_LOCKEN_SET << CLKCTRL_LOCKEN_bp)

;***********************************************************************************************************************
;** MCLKSTATUS - Main Clock Status - Definitions                                                                      **
;***********************************************************************************************************************

; MCLKSTATUS - External Clock Status - Bit Number
.EQU CLKCTRL_EXTS_BIT_NUMBER = CLKCTRL_EXTS_bp

.EQU CLKCTRL_STATUS_CLOCK_EXTERNAL_STARTED = (1 << CLKCTRL_EXTS_BIT_NUMBER)

; MCLKSTATUS - 32.768 kHz External Crystal Oscillator Status - Bit Number
.EQU CLKCTRL_XOSC32KS_BIT_NUMBER = CLKCTRL_XOSC32KS_bp

.EQU CLKCTRL_STATUS_CLOCK_EXTERNAL_32K_STARTED = (1 << CLKCTRL_XOSC32KS_BIT_NUMBER)

; MCLKSTATUS - 32.768 kHz Internal Ultra Low-Power Oscillator Status - Bit Number
.EQU CLKCTRL_OSC32KS_BIT_NUMBER = CLKCTRL_OSC32KS_bp

.EQU CLKCTRL_STATUS_CLOCK_INTERNAL_32K_STARTED = (1 << CLKCTRL_OSC32KS_BIT_NUMBER)

; MCLKSTATUS - 16/20 MHz Internal Oscillator Status - Bit Number
.EQU CLKCTRL_OSC20MS_BIT_NUMBER = CLKCTRL_OSC20MS_bp

.EQU CLKCTRL_STATUS_CLOCK_INTERNAL_20M_STARTED = (1 << CLKCTRL_OSC20MS_BIT_NUMBER)
