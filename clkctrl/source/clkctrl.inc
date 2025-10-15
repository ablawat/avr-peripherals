;***********************************************************************************************************************
;** Include Files                                                                                                     **
;***********************************************************************************************************************

.INCLUDE "clkctrl/config/clkctrl-config.inc"

;***********************************************************************************************************************
;** Macro Definitions                                                                                                 **
;***********************************************************************************************************************

#define GET_CONFIG_BYTE0(value) (LOW (LWRD(value)))
#define GET_CONFIG_BYTE1(value) (HIGH(LWRD(value)))
#define GET_CONFIG_BYTE2(value) (LOW (HWRD(value)))
#define GET_CONFIG_BYTE3(value) (HIGH(HWRD(value)))

;***********************************************************************************************************************
;** Constant Configuration Registers Definitions                                                                      **
;***********************************************************************************************************************

; MCLKCTRLA - System Clock Out
.EQU CONFIG_CLKCTRL_MCLKCTRLA_CLKOUT = CONFIG_CLKCTRL_PERIPHERAL_CLOCK_OUT

; MCLKCTRLA - Clock Select
.EQU CONFIG_CLKCTRL_MCLKCTRLA_CLKSEL = CONFIG_CLKCTRL_MAIN_CLOCK_SELECT

; @brief CLKCTRL Main Clock Control A Register
.EQU CONFIG_CLKCTRL_MCLKCTRLA = (CONFIG_CLKCTRL_MCLKCTRLA_CLKOUT << CLKCTRL_CLKOUT_bp) | \
                                (CONFIG_CLKCTRL_MCLKCTRLA_CLKSEL << CLKCTRL_CLKSEL_gp)

; MCLKCTRLB - Prescaler Division
.EQU CONFIG_CLKCTRL_MCLKCTRLB_PDIV = GET_CONFIG_BYTE0(CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER)

; MCLKCTRLB - Prescaler Enable
.EQU CONFIG_CLKCTRL_MCLKCTRLB_PEN  = GET_CONFIG_BYTE1(CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER)

; @brief CLKCTRL Main Clock Control B Register
.EQU CONFIG_CLKCTRL_MCLKCTRLB = (CONFIG_CLKCTRL_MCLKCTRLB_PDIV << CLKCTRL_PDIV_gp) | \
                                (CONFIG_CLKCTRL_MCLKCTRLB_PEN  << CLKCTRL_PEN_bp)

; MCLKLOCK - Lock Enable
.EQU CONFIG_CLKCTRL_MCLKLOCK_LOCKEN = CONFIG_CLKCTRL_MAIN_CLOCK_LOCK

; @brief CLKCTRL Main Clock Lock Register
.EQU CONFIG_CLKCTRL_MCLKLOCK = (CONFIG_CLKCTRL_MCLKLOCK_LOCKEN << CLKCTRL_LOCKEN_bp)

; define main clock frequency number
.IF   CONFIG_CLKCTRL_MAIN_CLOCK_SELECT == CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_20M
.EQU MAIN_CLOCK_FREQUENCY = 20000000    ; [20 MHz]
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_SELECT == CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_32K
.EQU MAIN_CLOCK_FREQUENCY = 32768       ; [32.768 kHz]
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_SELECT == CLKCTRL_MAIN_CLOCK_SELECT_EXTERNAL_32K
.EQU MAIN_CLOCK_FREQUENCY = 32768       ; [32.768 kHz]
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_SELECT == CLKCTRL_MAIN_CLOCK_SELECT_EXTERNAL
.EQU MAIN_CLOCK_FREQUENCY = 1           ; []
.ELSE
.EQU MAIN_CLOCK_FREQUENCY = 0
.ENDIF

; define main clock division number
.IF   CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_1
.EQU DIV = 1
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_2
.EQU DIV = 2
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_4
.EQU DIV = 4
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_6
.EQU DIV = 6
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_8
.EQU DIV = 8
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_10
.EQU DIV = 10
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_12
.EQU DIV = 12
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_16
.EQU DIV = 16
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_24
.EQU DIV = 24
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_32
.EQU DIV = 32
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_48
.EQU DIV = 48
.ELIF CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER == CLKCTRL_MAIN_CLOCK_DIVIDER_64
.EQU DIV = 64
.ELSE
.EQU DIV = 1
.ENDIF

;***********************************************************************************************************************
;** Output Definitions                                                                                                **
;***********************************************************************************************************************

;**
;** @brief  Peripheral Clock Frequency
;**
;** @value  @MIN: 0, @MAX: MAIN_CLOCK_FREQUENCY, @Unit: hertz [Hz]
;**
.EQU PERIPHERAL_CLOCK_FREQUENCY = (MAIN_CLOCK_FREQUENCY / DIV)
