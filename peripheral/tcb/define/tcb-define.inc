;******************************************************************************************************************************;
; @description : 16-Bit Timer/Counter Type B Peripheral Definition                                                             ;
;******************************************************************************************************************************;

.IFNDEF TCB_DEFINE
.SET    TCB_DEFINE = 1

;******************************************************************************************************************************;
; @section : Include File                                                                                                      ;
;******************************************************************************************************************************;

.INCLUDE "peripheral/tcb/define/tcb-register.inc"

.INCLUDE "macro/registers.inc"
.INCLUDE "macro/config.inc"

;******************************************************************************************************************************;
; @section : Configuration Option Definition                                                                                   ;
;******************************************************************************************************************************;

; @brief Timer/Counter B - Run in Standby
.EQU TCB_RUN_IN_STANDBY_DISABLED = TCB_CTRLA_RUNSTDBY_OFF
.EQU TCB_RUN_IN_STANDBY_ENABLED  = TCB_CTRLA_RUNSTDBY_ON

; @brief Timer/Counter B - Synchronize Update with Timer/Counter A
.EQU TCB_UPDATE_SYNCHRONIZE_DISABLED = TCB_CTRLA_SYNCUPD_OFF
.EQU TCB_UPDATE_SYNCHRONIZE_ENABLED  = TCB_CTRLA_SYNCUPD_ON

; @brief Timer/Counter B - Clock Select
.EQU TCB_CLOCK_PERIPHERAL_DIVIDER_1 = TCB_CTRLA_CLKSEL_CLKDIV1
.EQU TCB_CLOCK_PERIPHERAL_DIVIDER_2 = TCB_CTRLA_CLKSEL_CLKDIV2
.EQU TCB_CLOCK_TCA                  = TCB_CTRLA_CLKSEL_CLKTCA

; @brief Timer/Counter B - Output Pin
.EQU TCB_OUTPUT_DISABLED                   = (SET_CONFIG_BYTE0(TCB_CTRLB_CCMPEN_OFF))    | \
                                             (SET_CONFIG_BYTE1(TCB_CTRLB_CCMPINIT_LOW))

.EQU TCB_OUTPUT_ENABLED_INITIAL_LEVEL_LOW  = (SET_CONFIG_BYTE0(TCB_CTRLB_CCMPEN_ON))     | \
                                             (SET_CONFIG_BYTE1(TCB_CTRLB_CCMPINIT_LOW))

.EQU TCB_OUTPUT_ENABLED_INITIAL_LEVEL_HIGH = (SET_CONFIG_BYTE0(TCB_CTRLB_CCMPEN_ON))     | \
                                             (SET_CONFIG_BYTE1(TCB_CTRLB_CCMPINIT_HIGH))

; @brief Timer/Counter B - Count Mode
.EQU TCB_MODE_PERIODIC_INTERRUPT                  = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_INT))                 | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_INT_NONE))              | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_OFF))

.EQU TCB_MODE_TIMEOUT_CHECK_START_RISING          = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_TIMEOUT))             | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_TIMEOUT_START_RISING))  | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))

.EQU TCB_MODE_TIMEOUT_CHECK_START_FALLING         = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_TIMEOUT))             | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_TIMEOUT_START_FALLING)) | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))

.EQU TCB_MODE_MEASURE_PULSE_WIDTH_HIGH            = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_PW))                  | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_PW_LEVEL_HIGH))         | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))

.EQU TCB_MODE_MEASURE_PULSE_WIDTH_LOW             = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_PW))                  | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_PW_LEVEL_LOW))          | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))

.EQU TCB_MODE_MEASURE_FREQUENCY_PULSE_WIDTH_HIGH  = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_FRQPW))               | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_FRQPW_RISING_HIGH))     | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))

.EQU TCB_MODE_MEASURE_FREQUENCY_PULSE_WIDTH_LOW   = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_FRQPW))               | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_FRQPW_FALLING_LOW))     | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))

.EQU TCB_MODE_SINGLE_SHOT_START_RISE_OUTPUT_ASYNC = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_SINGLE))              | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_SINGLE_START_RISING))   | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))                  | \
                                                    (SET_CONFIG_BYTE3(TCB_CTRLB_ASYNC_ON))

.EQU TCB_MODE_SINGLE_SHOT_START_RISE_OUTPUT_SYNC  = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_SINGLE))              | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_SINGLE_START_RISING))   | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))                  | \
                                                    (SET_CONFIG_BYTE3(TCB_CTRLB_ASYNC_OFF))

.EQU TCB_MODE_SINGLE_SHOT_START_BOTH_OUTPUT_ASYNC = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_SINGLE))              | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_SINGLE_START_BOTH))     | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))                  | \
                                                    (SET_CONFIG_BYTE3(TCB_CTRLB_ASYNC_ON))

.EQU TCB_MODE_SINGLE_SHOT_START_BOTH_OUTPUT_SYNC  = (SET_CONFIG_BYTE0(TCB_CTRLB_CNTMODE_SINGLE))              | \
                                                    (SET_CONFIG_BYTE1(TCB_EVCTRL_EDGE_SINGLE_START_BOTH))     | \
                                                    (SET_CONFIG_BYTE2(TCB_EVCTRL_CAPTEI_ON))                  | \
                                                    (SET_CONFIG_BYTE3(TCB_CTRLB_ASYNC_OFF))

; @brief Timer/Counter B - Input Noise Cancellation Filter
.EQU TCB_INPUT_FILTER_DISABLED = TCB_EVCTRL_FILTER_OFF
.EQU TCB_INPUT_FILTER_ENABLED  = TCB_EVCTRL_FILTER_ON

; @brief Timer/Counter B - Capture Interrupt Enable
.EQU TCB_CAPTURE_INTERRUPT_DISABLED = TCB_INTCTRL_CAPT_OFF
.EQU TCB_CAPTURE_INTERRUPT_ENABLED  = TCB_INTCTRL_CAPT_ON

; @brief Timer/Counter B - Capture Interrupt Service Routine
.EQU TCB_CAPTURE_ISR_NONE = 0

.ENDIF
