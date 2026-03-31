.INCLUDE "peripheral/tcb/define/tcb-define.inc"

;**
;** @brief  Timer/Counter B - Run in Standby
;**
;** @value  TCB_RUN_IN_STANDBY_[OPTION]
;**
.EQU CONFIG_TCB0_RUN_IN_STANDBY = TCB_RUN_IN_STANDBY_DISABLED

;**
;** @brief  Timer/Counter B - Synchronize Update with Timer/Counter A
;**
;** @value  TCB_UPDATE_SYNCHRONIZE_[OPTION]
;**
.EQU CONFIG_TCB0_UPDATE_SYNCHRONIZE = TCB_UPDATE_SYNCHRONIZE_DISABLED

;**
;** @brief  Timer/Counter B - Clock Select
;**
;** @value  TCB_CLOCK_[OPTION]
;**
.EQU CONFIG_TCB0_CLOCK = TCB_CLOCK_PERIPHERAL_DIVIDER_1

;**
;** @brief  Timer/Counter B - Output Pin
;**
;** @value  TCB_OUTPUT_[OPTION]
;**
.EQU CONFIG_TCB0_OUTPUT = TCB_OUTPUT_DISABLED

;**
;** @brief  Timer/Counter B - Input Noise Cancellation Filter
;**
;** @value  TCB_INPUT_FILTER_[OPTION]
;**
.EQU CONFIG_TCB0_INPUT_FILTER = TCB_INPUT_FILTER_DISABLED

;**
;** @brief  Timer/Counter B - Count Mode
;**
;** @value  TCB_MODE_[OPTION]
;**
.EQU CONFIG_TCB0_MODE = TCB_MODE_PERIODIC_INTERRUPT

;**
;** @brief  Timer/Counter B - Capture Interrupt Enable
;**
;** @value  TCB_CAPTURE_INTERRUPT_[OPTION]
;**
.EQU CONFIG_TCB0_CAPTURE_INTERRUPT = TCB_CAPTURE_INTERRUPT_DISABLED

;**
;** @brief  Timer/Counter B - Capture Interrupt Service Routine
;**
;** @value  TCB_CAPTURE_ISR_NONE or label
;**
.EQU CONFIG_TCB0_CAPTURE_ISR = TCB_CAPTURE_ISR_NONE
