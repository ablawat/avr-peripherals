;**********************************************************************************************;
; @description : Port Multiplexer Source                                                       ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

.CSEG

;**********************************************************************************************;
; @brief    : Initializes Port Multiplexer Peripheral
;
; @input    : none
; @output   : none
;
; @used     : XH:XL, TEMPL
;**********************************************************************************************;
portmux_init:   ; get port multiplexer base address
                ldi     XH, HIGH (PORTMUX_base)
                ldi     XL, LOW  (PORTMUX_base)

                ; configure register CTRLA
                ldi     TEMPL, CONFIG_PORTMUX_CTRLA     ; get config constant
                st      X+, TEMPL                       ; write into register

                ; configure register CTRLB
                ldi     TEMPL, CONFIG_PORTMUX_CTRLB     ; get config constant
                st      X+, TEMPL                       ; write into register

                ; configure register CTRLC
                ldi     TEMPL, CONFIG_PORTMUX_CTRLC     ; get config constant
                st      X+, TEMPL                       ; write into register

                ; configure register CTRLD
                ldi     TEMPL, CONFIG_PORTMUX_CTRLD     ; get config constant
                st      X+, TEMPL                       ; write into register

                ret
