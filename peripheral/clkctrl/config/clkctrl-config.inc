.INCLUDE "clkctrl/define/clkctrl-define.inc"

;**
;** @brief  Clock Controller - System Clock Out
;**
;** @value  CLKCTRL_PERIPHERAL_CLOCK_OUT_[OPTION]
;**
.EQU CONFIG_CLKCTRL_PERIPHERAL_CLOCK_OUT = CLKCTRL_PERIPHERAL_CLOCK_OUT_DISABLED

;**
;** @brief  Clock Controller - Main Clock Select
;**
;** @value  CLKCTRL_MAIN_CLOCK_SELECT_[OPTION]
;**
.EQU CONFIG_CLKCTRL_MAIN_CLOCK_SELECT = CLKCTRL_MAIN_CLOCK_SELECT_INTERNAL_20M

;**
;** @brief  Clock Controller - Main Clock Prescaler Division
;**
;** @value  CLKCTRL_MAIN_CLOCK_DIVIDER_[OPTION]
;**
.EQU CONFIG_CLKCTRL_MAIN_CLOCK_DIVIDER = CLKCTRL_MAIN_CLOCK_DIVIDER_2

;**
;** @brief  Clock Controller - Main Clock Lock
;**
;** @value  CLKCTRL_MAIN_CLOCK_LOCK_[OPTION]
;**
.EQU CONFIG_CLKCTRL_MAIN_CLOCK_LOCK = CLKCTRL_MAIN_CLOCK_LOCK_ENABLED
