;***********************************************************************************************************************
;** Include Files                                                                                                     **
;***********************************************************************************************************************

.INCLUDE "clkctrl/source/clkctrl.inc"

;***********************************************************************************************************************
; @brief    Initializes Clock Controller Peripheral
;
; @input    : none
; @output   : none
;
; @used     : XH:XL (changed), r16 (changed)
;***********************************************************************************************************************
clkctrl_init:   ; get clock controller base address
                ldi     XH, HIGH (CLKCTRL_base)         ;
                ldi     XL, LOW  (CLKCTRL_base)         ;

                ldi     r17, CPU_CCP_IOREG_gc           ; get I/O registers unlock value

                ; unlock protected I/O registers
                out     CPU_CCP, r17                    ; write into configuration change protection

                ; configure register MCLKCTRLA
                ldi     r16, CONFIG_CLKCTRL_MCLKCTRLA   ; get MCLKCTRLA config
                st      X+, r16                         ; write into MCLKCTRLA

                ; unlock protected I/O registers
                out     CPU_CCP, r17                    ; write into configuration change protection

                ; configure register MCLKCTRLB
                ldi     r16, CONFIG_CLKCTRL_MCLKCTRLB   ; get MCLKCTRLB config
                st      X+, r16                         ; write into MCLKCTRLB

                ; unlock protected I/O registers
                out     CPU_CCP, r17                    ; write into configuration change protection

                ; configure register MCLKLOCK
                ldi     r16, CONFIG_CLKCTRL_MCLKLOCK    ; get MCLKLOCK config
                st      X+, r16                         ; write into MCLKLOCK

                ret
