.INCLUDE "port/porta.inc"
.INCLUDE "port/portb.inc"

                ; PORTA DIR and OUT Configuration
porta_config:   .DB CONFIG_PORTA_DIR, CONFIG_PORTA_OUT
                ; PORTA PINCTRL Configuration
                .DB CONFIG_PORTA_PIN0CTRL, CONFIG_PORTA_PIN1CTRL
                .DB CONFIG_PORTA_PIN2CTRL, CONFIG_PORTA_PIN3CTRL
                .DB CONFIG_PORTA_PIN4CTRL, CONFIG_PORTA_PIN5CTRL
                .DB CONFIG_PORTA_PIN6CTRL, CONFIG_PORTA_PIN7CTRL

                ; PORTB DIR and OUT Configuration
portb_config:   .DB CONFIG_PORTB_DIR, CONFIG_PORTB_OUT
                ; PORTB PINCTRL Configuration
                .DB CONFIG_PORTB_PIN0CTRL, CONFIG_PORTB_PIN1CTRL
                .DB CONFIG_PORTB_PIN2CTRL, CONFIG_PORTB_PIN3CTRL
                .DB CONFIG_PORTB_PIN4CTRL, CONFIG_PORTB_PIN5CTRL
                .DB CONFIG_PORTB_PIN6CTRL, CONFIG_PORTB_PIN7CTRL

; PORT Configuration Base Address
.EQU PORT_CONFIG_ADDRESS = (porta_config * 2)

; PORT Configuration Address Offset
.EQU PORT_CONFIG_OFFSET = 10

;***************************************************************************************************
; @brief    Initializes Input and Output Pins Peripheral (PORT)
;
; @input    : r20   :  2-bit - [PORTA, PORTB, PORTC]
; @output   : none
;
; @used     : ZH:ZL (changed), XH:XL (changed), r17 (changed), r16 (changed)
; @used     : r1 (changed), r0 (changed)
;***************************************************************************************************
port_init:      ; get I/O ports base address
                ldi     XH, HIGH (PORTA_base)
                ldi     XL, LOW  (PORTA_base)

                ; calculate selected PORT address offset
                ldi     r16, PORT_OFFSET
                mul     r20, r16

                ; calculate selected PORT address base
                add     XL, r0
                adc     XH, r1

                ; configure register PINnCTRL
                ldi     ZH, HIGH (PORT_CONFIG_ADDRESS)
                ldi     ZL, LOW  (PORT_CONFIG_ADDRESS)

                ; calculate selected PORT config flash address offset
                ldi     r16, PORT_CONFIG_OFFSET
                mul     r20, r16

                ; calculate selected PORT config flash address base
                add     ZL, r0
                adc     ZH, r1

                ; configure register DIR
                lpm     r16, Z+                         ; read config from flash
                st      X, r16                          ; write into DIR

                ; move address pointer to next register
                adiw    XL, 4

                ; configure register OUT
                lpm     r16, Z+                         ; read config from flash
                st      X, r16                          ; write into OUT

                ; move address pointer to next register
                adiw    XL, 12

                ; configure registers PINnCTRL
                ldi     r16, 8                          ; set number of PINnCTRL registers

port_init_br1:  lpm     r17, Z+                         ; read config from flash
                st      X+, r17                         ; write into PINCTRL

                dec     r16                             ; decrease number of registers
                brne    port_init_br1                   ; repeat until last register

                ret
