;***********************************************************************************************************************
;** Clock Controller Peripheral Definitions                                                                           **
;***********************************************************************************************************************

;***********************************************************************************************************************
;** Include Files                                                                                                     **
;***********************************************************************************************************************

.INCLUDE "clkctrl/define/clkctrl-register.inc"

;***********************************************************************************************************************
;** Macro Definitions                                                                                                 **
;***********************************************************************************************************************

#define SET_CONFIG_BYTE0(value) ((value) <<  0)
#define SET_CONFIG_BYTE1(value) ((value) <<  8)
#define SET_CONFIG_BYTE2(value) ((value) << 16)
#define SET_CONFIG_BYTE3(value) ((value) << 24)

;***********************************************************************************************************************
;** Configuration Option Definitions                                                                                  **
;***********************************************************************************************************************

; @brief Clock Controller - System Clock Out
.EQU CLKCTRL_PERIPHERAL_CLOCK_OUT_DISABLED = CLKCTRL_MCLKCTRLA_CLKOUT_OFF
.EQU CLKCTRL_PERIPHERAL_CLOCK_OUT_ENABLED  = CLKCTRL_MCLKCTRLA_CLKOUT_ON

; @brief Clock Controller - Main Clock Select
.EQU CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_20M = CLKCTRL_MCLKCTRLA_CLKSEL_OSC20M
.EQU CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_32K = CLKCTRL_MCLKCTRLA_CLKSEL_OSCULP32K
.EQU CLKCTRL_MAIN_CLOCK_SELECT_EXTERNAL_32K = CLKCTRL_MCLKCTRLA_CLKSEL_XOSC32K
.EQU CLKCTRL_MAIN_CLOCK_SELECT_EXTERNAL     = CLKCTRL_MCLKCTRLA_CLKSEL_EXTCLK

; @brief Clock Controller - Main Clock Divider
.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_1  = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_2))  | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_OFF))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_2  = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_2))  | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_4  = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_4))  | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_6  = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_6))  | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_8  = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_8))  | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_10 = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_10)) | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_12 = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_12)) | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_16 = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_16)) | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_24 = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_24)) | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_32 = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_32)) | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_48 = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_48)) | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

.EQU CLKCTRL_MAIN_CLOCK_DIVIDER_64 = (SET_CONFIG_BYTE0(CLKCTRL_MCLKCTRLB_PDIV_64)) | \
                                     (SET_CONFIG_BYTE1(CLKCTRL_MCLKCTRLB_PEN_ON))

; @brief Clock Controller - Main Clock Lock
.EQU CLKCTRL_MAIN_CLOCK_LOCK_DISABLED = CLKCTRL_MCLKLOCK_LOCKEN_OFF
.EQU CLKCTRL_MAIN_CLOCK_LOCK_ENABLED  = CLKCTRL_MCLKLOCK_LOCKEN_ON
