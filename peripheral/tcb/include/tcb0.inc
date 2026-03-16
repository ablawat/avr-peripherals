;**********************************************************************************************;
; @description : 16-Bit Timer/Counter Type B 0 Header                                          ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "tcb/config/tcb0-config.inc"

;**********************************************************************************************;
; @section : Register Configuration                                                            ;
;**********************************************************************************************;

; CTRLA - Run in Standby
.EQU CONFIG_TCB0_CTRLA_RUNSTDBY = CONFIG_TCB0_RUN_IN_STANDBY

; CTRLA - Synchronize Update
.EQU CONFIG_TCB0_CTRLA_SYNCUPD  = CONFIG_TCB0_UPDATE_SYNCHRONIZE

; CTRLA - Clock Select
.EQU CONFIG_TCB0_CTRLA_CLKSEL   = CONFIG_TCB0_CLOCK

; CTRLA - Counter Enable
.EQU CONFIG_TCB0_CTRLA_ENABLE   = TCB_CTRLA_ENABLE_OFF

; @brief Control A Register
.EQU CONFIG_TCB0_CTRLA = (CONFIG_TCB0_CTRLA_RUNSTDBY << TCB_CTRLA_RUNSTDBY_BPOS) | \
                         (CONFIG_TCB0_CTRLA_SYNCUPD  << TCB_CTRLA_SYNCUPD_BPOS ) | \
                         (CONFIG_TCB0_CTRLA_CLKSEL   << TCB_CTRLA_CLKSEL_GPOS  ) | \
                         (CONFIG_TCB0_CTRLA_ENABLE   << TCB_CTRLA_ENABLE_BPOS  )

; CTRLB - Asynchronous Output Enable
.EQU CONFIG_TCB0_CTRLB_ASYNC    = GET_CONFIG_BYTE3(CONFIG_TCB0_MODE)

; CTRLB - Compare/Capture Pin Initial Value
.EQU CONFIG_TCB0_CTRLB_CCMPINIT = GET_CONFIG_BYTE1(CONFIG_TCB0_OUTPUT)

; CTRLB - Compare/Capture Output Enable
.EQU CONFIG_TCB0_CTRLB_CCMPEN   = GET_CONFIG_BYTE0(CONFIG_TCB0_OUTPUT)

; CTRLB - Timer/Counter Mode
.EQU CONFIG_TCB0_CTRLB_CNTMODE  = GET_CONFIG_BYTE0(CONFIG_TCB0_MODE)

; @brief Control B Register
.EQU CONFIG_TCB0_CTRLB = (CONFIG_TCB0_CTRLB_ASYNC    << TCB_CTRLB_ASYNC_BPOS   ) | \
                         (CONFIG_TCB0_CTRLB_CCMPINIT << TCB_CTRLB_CCMPINIT_BPOS) | \
                         (CONFIG_TCB0_CTRLB_CCMPEN   << TCB_CTRLB_CCMPEN_BPOS  ) | \
                         (CONFIG_TCB0_CTRLB_CNTMODE  << TCB_CTRLB_CNTMODE_GPOS )

; EVCTRL - Input Capture Noise Cancellation Filter
.EQU CONFIG_TCB0_EVCTRL_FILTER = CONFIG_TCB0_INPUT_FILTER

; EVCTRL - Event Edge
.EQU CONFIG_TCB0_EVCTRL_EDGE   = GET_CONFIG_BYTE1(CONFIG_TCB0_MODE)

; EVCTRL - Capture Event Input Enable
.EQU CONFIG_TCB0_EVCTRL_CAPTEI = GET_CONFIG_BYTE2(CONFIG_TCB0_MODE)

; @brief Event Control Register
.EQU CONFIG_TCB0_EVCTRL = (CONFIG_TCB0_EVCTRL_FILTER << TCB_EVCTRL_FILTER_BPOS) | \
                          (CONFIG_TCB0_EVCTRL_EDGE   << TCB_EVCTRL_EDGE_BPOS  ) | \
                          (CONFIG_TCB0_EVCTRL_CAPTEI << TCB_EVCTRL_CAPTEI_BPOS)

; INTCTRL - Capture Interrupt Enable
.EQU CONFIG_TCB0_INTCTRL_CAPT = CONFIG_TCB0_CAPTURE_INTERRUPT

; @brief Interrupt Control Register
.EQU CONFIG_TCB0_INTCTRL = (CONFIG_TCB0_INTCTRL_CAPT << TCB_INTCTRL_CAPT_BPOS)

; @brief Configuration Marker
.EQU TCB0_CONFIG_DEFINE = 1
