;**********************************************************************************************;
; @description : Input and Output Pin Configuration Source                                     ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Constant Data [FLASH]                                                             ;
;**********************************************************************************************;

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

;**********************************************************************************************;
; @brief    : Initializes Input and Output Pins Peripheral (PORT)
;
; @param    : ARG1  :  2-bit - [PORTA, PORTB, PORTC]
; @return   : none
;
; @use      : ZH:ZL XH:XL TEMPH:TEMPL r1 r0
;**********************************************************************************************;
port_init:      ; get I/O ports base address
                ldi     XH, HIGH (PORTA_base)
                ldi     XL, LOW  (PORTA_base)

                ; calculate selected PORT address offset
                ldi     TEMPL, PORT_OFFSET
                mul     ARG1, TEMPL

                ; calculate selected PORT address base
                add     XL, r0
                adc     XH, r1

                ; configure register PINnCTRL
                ldi     ZH, HIGH (PORT_CONFIG_ADDRESS)
                ldi     ZL, LOW  (PORT_CONFIG_ADDRESS)

                ; calculate selected PORT config flash address offset
                ldi     TEMPL, PORT_CONFIG_OFFSET
                mul     ARG1, TEMPL

                ; calculate selected PORT config flash address base
                add     ZL, r0
                adc     ZH, r1

                ; configure register DIR
                lpm     TEMPL, Z+                       ; load configuration from flash
                st      X, TEMPL                        ; write into register

                ; move to next register
                adiw    XL, 4                           ; move pointer forward

                ; configure register OUT
                lpm     TEMPL, Z+                       ; load configuration from flash
                st      X, TEMPL                        ; write into register

                ; move to next register
                adiw    XL, 12                          ; move pointer forward

                ; prepare for registers configuration
                ldi     TEMPL, 8                        ; set number of PINnCTRL registers

port_init_br1:  ; configure register PINnCTRL
                lpm     TEMPH, Z+                       ; read config from flash
                st      X+, TEMPH                       ; write into PINCTRL

                ; check for last register to write
                dec     TEMPL                           ; decrease number of registers
                brne    port_init_br1                   ; repeat when not all registers has been set

                ret
