;**********************************************************************************************;
; @description : 16-Bit Timer/Counter Type B 0 Source                                          ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

.CSEG

;**********************************************************************************************;
; @brief    : Initializes Timer/Counter B 0 Peripheral
;
; @input    : none
; @output   : none
;
; @use      : XH:XL, TEMPL
;**********************************************************************************************;
tcb0_init:  ; get TCB0 base address
            ldi     XH, HIGH (TCB0_base)
            ldi     XL, LOW  (TCB0_base)

            ; configure register Control A
            ldi     TEMPL, CONFIG_TCB0_CTRLA    ; get config constant
            st      X+, TEMPL                   ; write into register

            ; configure register Control B
            ldi     TEMPL, CONFIG_TCB0_CTRLB    ; get config constant
            st      X+, TEMPL                   ; write into register

            ; skip two registers
            adiw    XL, 2                       ; move pointer forward

            ; configure register Event Control
            ldi     TEMPL, CONFIG_TCB0_EVCTRL   ; get config constant
            st      X+, TEMPL                   ; write into register

            ; configure register Interrupt Control
            ldi     TEMPL, CONFIG_TCB0_INTCTRL  ; get config constant
            st      X+, TEMPL                   ; write into register

            ret

;**********************************************************************************************;
; @brief    : Enables Timer/Counter
;
; @input    : none
; @output   : none
;
; @use      : TEMPL
;**********************************************************************************************;
tcb0_enable:    ; enable timer
                lds     TEMPL, TCB0_CTRLA           ; get Control A
                sbr     TEMPL, TCB_CTRLA_ENABLE_ON  ; enable counter
                sts     TCB0_CTRLA, TEMPL           ; set Control A

                ret

;**********************************************************************************************;
; @brief    : Reads Measured Pulse Widths
;
; @input    : XH:XL : 16-bit - a start pointer of data to receive
; @input    : ARG1  :  8-bit - a length of data to receive
;
; @use      : TEMPL
;**********************************************************************************************;
tcb0_read_width:    ; wait until measurement is completed
                    lds     TEMPL, TCB0_INTFLAGS            ; get interrupt flags
                    sbrs    TEMPL, TCB_INTFLAGS_CAPT_BPOS   ; check capture interrupt flag
                    rjmp    tcb0_read_width                 ; repeat when measurement is not completed

                    ; read measurement result low byte
                    lds     TEMPL, TCB0_CCMPL               ; get data low byte
                    st      X+, TEMPL                       ; store data at output pointer

                    ; read measurement result high byte
                    lds     TEMPL, TCB0_CCMPH               ; get data high byte
                    st      X+, TEMPL                       ; store data at output pointer

                    ; check for last result to read
                    dec     ARG1                            ; decrease number of results to read
                    brne    tcb0_read_width                 ; repeat when not all results have been read

                    ret
