.INCLUDE "clkctrl/clkctrl-def.inc"

;**
;** @brief  System Clock Out
;**
;** @value  System Clock Out Configuration Options
;**
.EQU CONFIG_CLKCTRL_PERIPHERAL_CLOCK_OUT = CLKCTRL_PERIPHERAL_CLOCK_OUT_ENABLED

;**
;** @brief  Main Clock Select
;**
;** @value  Main Clock Select Configuration Options
;**
.EQU CONFIG_CLKCTRL_MAIN_CLOCK_SELECT = CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_20M

;**
;** @brief  Main Clock Prescaler Division
;**
;** @value  Main Clock Prescaler Division Configuration Options
;**
.EQU CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER = CLKCTRL_MAIN_CLOCK_DIVIDER_32

;**
;** @brief  Main Clock Lock
;**
;** @value  Main Clock Lock Configuration Options
;**
.EQU CONFIG_CLKCTRL_MAIN_CLOCK_LOCK = CLKCTRL_MAIN_CLOCK_LOCK_ENABLED
