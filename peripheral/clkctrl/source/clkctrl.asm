;**********************************************************************************************;
; @description : Clock Controller Source                                                       ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

.CSEG

;**********************************************************************************************;
; @brief    : Initializes Clock Controller Peripheral
;
; @input    : none
; @output   : none
;
; @use      : XH:XL, TEMP1, TEMP0
;**********************************************************************************************;
clkctrl_init:   ; get clock controller base address
                ldi     XH, HIGH (CLKCTRL_base)
                ldi     XL, LOW  (CLKCTRL_base)

                ldi     TEMP1, CPU_CCP_IOREG_gc         ; get I/O registers unlock value

                ; unlock protected I/O registers
                out     CPU_CCP, TEMP1                  ; write into configuration change protection

                ; configure register MCLKCTRLA
                ldi     TEMP0, CONFIG_CLKCTRL_MCLKCTRLA ; get config constant
                st      X+, TEMP0                       ; write into register

                ; unlock protected I/O registers
                out     CPU_CCP, TEMP1                  ; write into configuration change protection

                ; configure register MCLKCTRLB
                ldi     TEMP0, CONFIG_CLKCTRL_MCLKCTRLB ; get config constant
                st      X+, TEMP0                       ; write into register

                ; unlock protected I/O registers
                out     CPU_CCP, TEMP1                  ; write into configuration change protection

                ; configure register MCLKLOCK
                ldi     TEMP0, CONFIG_CLKCTRL_MCLKLOCK  ; get config constant
                st      X+, TEMP0                       ; write into register

                ret
