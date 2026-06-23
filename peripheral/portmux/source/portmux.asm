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
; @used     : XH:XL, TEMP0
;**********************************************************************************************;
portmux_init:   ; get port multiplexer base address
                ldi     XH, HIGH (PORTMUX_base)
                ldi     XL, LOW  (PORTMUX_base)

                ; configure register CTRLA
                ldi     TEMP0, CONFIG_PORTMUX_CTRLA     ; get config constant
                st      X+, TEMP0                       ; write into register

                ; configure register CTRLB
                ldi     TEMP0, CONFIG_PORTMUX_CTRLB     ; get config constant
                st      X+, TEMP0                       ; write into register

                ; configure register CTRLC
                ldi     TEMP0, CONFIG_PORTMUX_CTRLC     ; get config constant
                st      X+, TEMP0                       ; write into register

                ; configure register CTRLD
                ldi     TEMP0, CONFIG_PORTMUX_CTRLD     ; get config constant
                st      X+, TEMP0                       ; write into register

                ret
