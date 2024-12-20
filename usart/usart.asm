;***************************************************************************************************
;**     Include Files                                                                             **
;***************************************************************************************************

.INCLUDE "usart/usart0.inc"

;***************************************************************************************************
;**     Constant Data Section [FLASH]                                                             **
;***************************************************************************************************

                ; Control Registers Configuration
usart0_config:  .DB CONFIG_USART0_CTRLA, CONFIG_USART0_CTRLB
                .DB CONFIG_USART0_CTRLC, 0x00
                ; Baud Register Configuration
                .DW CONFIG_USART0_BAUD

;***************************************************************************************************
;**     Local Definitions                                                                         **
;***************************************************************************************************

; USART Configuration Base Address
.EQU USART_CONFIG_ADDRESS = (usart0_config * 2)

; USART Configuration Address Offset
.EQU USART_CONFIG_OFFSET = 6

;***************************************************************************************************
;**     Code Section [FLASH]                                                                      **
;***************************************************************************************************

;***************************************************************************************************
; @brief    Initializes USART0 Peripheral
;
; @input    : r20   :  2-bit - [USART0, USART1]
; @output   : none
;
; @used     : ZH:ZL (changed), XH:XL (changed), r17 (changed), r16 (changed)
; @used     : r1 (changed), r0 (changed)
;***************************************************************************************************
usart_init:     ; get USARTs base address
                ldi     XH, HIGH (USART0_CTRLA)
                ldi     XL, LOW  (USART0_CTRLA)

                ; calculate selected USART address offset
                ldi     r16, USART_OFFSET
                mul     r20, r16

                ; calculate selected USART address base
                add     XL, r0
                adc     XH, r1

                ; get USARTs configuration base address
                ldi     ZH, HIGH (USART_CONFIG_ADDRESS)
                ldi     ZL, LOW  (USART_CONFIG_ADDRESS)

                ; calculate selected USART configuration flash address offset
                ldi     r16, USART_CONFIG_OFFSET
                mul     r20, r16

                ; calculate selected USART configuration flash address base
                add     ZL, r0
                adc     ZH, r1

                ; configure registers CTRLx
                ldi     r16, 3                          ; set number of CTRLx registers

usart_init_br1: lpm     r17, Z+                         ; read config from flash
                st      X+, r17                         ; write into CTRLx

                dec     r16                             ; decrease number of registers
                brne    usart_init_br1                  ; repeat until last register

                ; move address pointer to next register
                adiw    ZL, 1

                ; configure register BAUDL
                lpm     r16, Z+                         ; read config from flash
                st      X+, r16                         ; write into BAUDL

                ; configure register BAUDH
                lpm     r16, Z+                         ; read config from flash
                st      X+, r16                         ; write into BAUDH

                ; enable transmitter and receiver
                lds     r16, USART0_CTRLB
                sbr     r16, USART_RX_ENABLED | USART_TX_ENABLED
                sts     USART0_CTRLB, r16

                ret

;***************************************************************************************************
; @brief    Sends Data Frames
;
; @input    : XH:XL : 16-bit - data to send start pointer
; @input    : r20   :  8-bit - data to send length
;
; @output   : none
;
; @used     : r16 (changed)
;***************************************************************************************************
usart0_write:       ; wait until current data has been sent
                    lds     r16, USART0_STATUS              ; read status register
                    sbrs    r16, USART_DREIF_bp             ; check data register empty interrupt
                    rjmp    usart0_write                    ; wait until data is empty

                    ; transmit data
                    ld      r16, X+                         ; read next input byte
                    sts     USART0_TXDATAL, r16             ; load and trigger transmission

                    dec     r20                             ; decrease number of bytes to send
                    brne    usart0_write                    ; repeat until last data to send

usart0_write_br1:   ; wait until last data has been sent
                    lds     r16, USART0_STATUS              ; read status register
                    sbrs    r16, USART_TXCIF_BIT_NUMBER     ; check transmit complete interrupt
                    rjmp    usart0_write_br1                ; wait until data is send

                    ret
