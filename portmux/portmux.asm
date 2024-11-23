.INCLUDE "portmux/portmux.inc"

;***************************************************************************************************
; @brief    Initializes Port Multiplexer Peripheral
;
; @input    : none
; @output   : none
;
; @used     : XH:XL (changed), r16 (changed)
;***************************************************************************************************
portmux_init:   ; get port multiplexer base address
                ldi     XH, HIGH (PORTMUX_base)
                ldi     XL, LOW  (PORTMUX_base)

                ; configure register CTRLA
                ldi     r16, CONFIG_PORTMUX_CTRLA       ; get config constant
                st      X+, r16                         ; write into register

                ; configure register CTRLB
                ldi     r16, CONFIG_PORTMUX_CTRLB       ; get config constant
                st      X+, r16                         ; write into register

                ; configure register CTRLC
                ldi     r16, CONFIG_PORTMUX_CTRLC       ; get config constant
                st      X+, r16                         ; write into register

                ; configure register CTRLD
                ldi     r16, CONFIG_PORTMUX_CTRLD       ; get config constant
                st      X+, r16                         ; write into register

                ret
