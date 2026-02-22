;**********************************************************************************************;
; @description : 16-Bit Timer/Counter Type B Peripheral                                        ;
;**********************************************************************************************;

.IFNDEF TCB_REGISTER
.SET    TCB_REGISTER = 1

; TCB Registers Offset
.EQU TCB_OFFSET = 16

;**********************************************************************************************;
; @section : CTRLA - Control A                                                                 ;
;**********************************************************************************************;

; CTRLA - Run in Standby
.EQU TCB_CTRLA_RUNSTDBY_OFF = 0
.EQU TCB_CTRLA_RUNSTDBY_ON  = 1

; CTRLA - Run in Standby - Bit Position
.EQU TCB_CTRLA_RUNSTDBY_BPOS = TCB_RUNSTDBY_bp

; CTRLA - Synchronize Update
.EQU TCB_CTRLA_SYNCUPD_OFF = 0
.EQU TCB_CTRLA_SYNCUPD_ON  = 1

; CTRLA - Synchronize Update - Bit Position
.EQU TCB_CTRLA_SYNCUPD_BPOS = TCB_SYNCUPD_bp

; CTRLA - Clock Select
.EQU TCB_CTRLA_CLKSEL_CLKDIV1 = 0   ; peripheral clock
.EQU TCB_CTRLA_CLKSEL_CLKDIV2 = 1   ; peripheral clock divided by 2
.EQU TCB_CTRLA_CLKSEL_CLKTCA  = 2   ; TCA0 clock

; CTRLA - Clock Select - Group Position
.EQU TCB_CTRLA_CLKSEL_GPOS = TCB_CLKSEL_gp

; CTRLA - Enable
.EQU TCB_CTRLA_ENABLE_OFF = 0
.EQU TCB_CTRLA_ENABLE_ON  = 1

; CTRLA - Enable - Bit Position
.EQU TCB_CTRLA_ENABLE_BPOS = TCB_ENABLE_bp

;**********************************************************************************************;
; @section : CTRLB - Control B                                                                 ;
;**********************************************************************************************;

; CTRLB - Asynchronous Output Enable
.EQU TCB_CTRLB_ASYNC_OFF = 0
.EQU TCB_CTRLB_ASYNC_ON  = 1

; CTRLB - Asynchronous Output Enable - Bit Position
.EQU TCB_CTRLB_ASYNC_BPOS = TCB_ASYNC_bp

; CTRLB - Compare/Capture Pin Initial Value
.EQU TCB_CTRLB_CCMPINIT_LOW  = 0
.EQU TCB_CTRLB_CCMPINIT_HIGH = 1

; CTRLB - Compare/Capture Pin Initial Value - Bit Position
.EQU TCB_CTRLB_CCMPINIT_BPOS = TCB_CCMPINIT_bp

; CTRLB - Compare/Capture Output Enable
.EQU TCB_CTRLB_CCMPEN_OFF = 0
.EQU TCB_CTRLB_CCMPEN_ON  = 1

; CTRLB - Compare/Capture Output Enable - Bit Position
.EQU TCB_CTRLB_CCMPEN_BPOS = TCB_CCMPEN_bp

; CTRLB - Timer/Counter Mode
.EQU TCB_CTRLB_CNTMODE_INT     = 0  ; mode periodic interrupt 
.EQU TCB_CTRLB_CNTMODE_TIMEOUT = 1  ; mode time-out check
.EQU TCB_CTRLB_CNTMODE_CAPT    = 2  ; mode input capture on event
.EQU TCB_CTRLB_CNTMODE_FRQ     = 3  ; mode input capture frequency measurement
.EQU TCB_CTRLB_CNTMODE_PW      = 4  ; mode input capture pulse width measurement
.EQU TCB_CTRLB_CNTMODE_FRQPW   = 5  ; mode input capture frequency and pulse width measurement
.EQU TCB_CTRLB_CNTMODE_SINGLE  = 6  ; mode single-shot
.EQU TCB_CTRLB_CNTMODE_PWM8    = 7  ; mode 8-bit PWM

; CTRLB - Timer/Counter Mode - Group Position
.EQU TCB_CTRLB_CNTMODE_GPOS = TCB_CNTMODE_gp

;**********************************************************************************************;
; @section : EVCTRL - Event Control                                                            ;
;**********************************************************************************************;

; EVCTRL - Input Capture Noise Cancellation Filter
.EQU TCB_EVCTRL_FILTER_OFF = 0
.EQU TCB_EVCTRL_FILTER_ON  = 1

; EVCTRL - Input Capture Noise Cancellation Filter - Bit Position
.EQU TCB_EVCTRL_FILTER_BPOS = TCB_FILTER_bp

; EVCTRL - Event Edge
.EQU TCB_EVCTRL_EDGE_CLR = 0
.EQU TCB_EVCTRL_EDGE_SET = 1

; EVCTRL - Event Edge - Bit Position
.EQU TCB_EVCTRL_EDGE_BPOS = TCB_EDGE_bp

; EVCTRL - Event Edge - Periodic Interrupt
.EQU TCB_EVCTRL_EDGE_INT_NONE                        = TCB_EVCTRL_EDGE_CLR

; EVCTRL - Event Edge - Time-Out Check
.EQU TCB_EVCTRL_EDGE_TIMEOUT_START_RISING            = TCB_EVCTRL_EDGE_CLR
.EQU TCB_EVCTRL_EDGE_TIMEOUT_START_FALLING           = TCB_EVCTRL_EDGE_SET

; EVCTRL - Event Edge - Input Capture on Event
.EQU TCB_EVCTRL_EDGE_CAPT_CAPTURE_RISING             = TCB_EVCTRL_EDGE_CLR
.EQU TCB_EVCTRL_EDGE_CAPT_CAPTURE_FALLING            = TCB_EVCTRL_EDGE_SET

; EVCTRL - Event Edge - Input Capture Frequency Measurement
.EQU TCB_EVCTRL_EDGE_FRQ_CAPTURE_RISING              = TCB_EVCTRL_EDGE_CLR
.EQU TCB_EVCTRL_EDGE_FRQ_CAPTURE_FALLING             = TCB_EVCTRL_EDGE_SET

; EVCTRL - Event Edge - Input Capture Pulse Width Measurement
.EQU TCB_EVCTRL_EDGE_PW_LEVEL_HIGH                   = TCB_EVCTRL_EDGE_CLR
.EQU TCB_EVCTRL_EDGE_PW_LEVEL_LOW                    = TCB_EVCTRL_EDGE_SET

; EVCTRL - Event Edge - Input Capture Frequency and Pulse Width Measurement
.EQU TCB_EVCTRL_EDGE_FRQPW_RISING_HIGH = TCB_EVCTRL_EDGE_CLR
.EQU TCB_EVCTRL_EDGE_FRQPW_FALLING_LOW = TCB_EVCTRL_EDGE_SET

; EVCTRL - Event Edge - Single-Shot
.EQU TCB_EVCTRL_EDGE_SINGLE_START_RISING             = TCB_EVCTRL_EDGE_CLR
.EQU TCB_EVCTRL_EDGE_SINGLE_START_BOTH               = TCB_EVCTRL_EDGE_SET

; EVCTRL - Event Edge - 8-Bit PWM
.EQU TCB_EVCTRL_EDGE_PWM8_NONE                       = TCB_EVCTRL_EDGE_CLR

; EVCTRL - Capture Event Input Enable
.EQU TCB_EVCTRL_CAPTEI_OFF = 0
.EQU TCB_EVCTRL_CAPTEI_ON  = 1

; EVCTRL - Capture Event Input Enable - Bit Position
.EQU TCB_EVCTRL_CAPTEI_BPOS = TCB_CAPTEI_bp

;**********************************************************************************************;
; @section : INTCTRL - Interrupt Control                                                       ;
;**********************************************************************************************;

; INTCTRL - Capture Interrupt Enable
.EQU TCB_INTCTRL_CAPT_OFF = 0
.EQU TCB_INTCTRL_CAPT_ON  = 1

; INTCTRL - Capture Interrupt Enable - Bit Position
.EQU TCB_INTCTRL_CAPT_BPOS = TCB_CAPT_bp

;**********************************************************************************************;
; @section : INTFLAGS - Interrupt Flags                                                        ;
;**********************************************************************************************;

; INTFLAGS - Capture Interrupt Flag - Bit Position
.EQU TCB_INTFLAGS_CAPT_BPOS = TCB_CAPT_bp

.ENDIF
