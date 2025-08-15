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
                ldi     r16, 3                  ; set number of CTRLx registers

usart_init_br1: lpm     r17, Z+                 ; load configuration from flash
                st      X+, r17                 ; set CTRLx

                ; check for last register to write
                dec     r16                     ; decrease number of registers
                brne    usart_init_br1          ; repeat when not all registers has been set

                ; move to next register
                adiw    ZL, 1                   ; move pointer forward

                ; configure register BAUDL
                lpm     r16, Z+                 ; load configuration from flash
                st      X+, r16                 ; set Baud Low

                ; configure register BAUDH
                lpm     r16, Z+                 ; load configuration from flash
                st      X+, r16                 ; set Baud High

                ; enable transmitter and receiver
                lds     r16, USART0_CTRLB                           ; get Control B
                sbr     r16, USART_RX_ENABLED | USART_TX_ENABLED
                sts     USART0_CTRLB, r16                           ; set Control B

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
usart0_write:       ; wait until byte has been sent
                    lds     r16, USART0_STATUS              ; get status
                    sbrs    r16, USART_DREIF_BIT_NUMBER     ; check data register empty interrupt flag
                    rjmp    usart0_write                    ; repeat when data register is not empty

                    ; send byte
                    ld      r16, X+                         ; read data byte from input pointer
                    sts     USART0_TXDATAL, r16             ; write byte and trigger transmission

                    ; check for last byte to send
                    dec     r20                             ; decrease number of bytes to send
                    brne    usart0_write                    ; repeat when not all bytes has been sent

usart0_write_br1:   ; wait until last byte has been sent
                    lds     r16, USART0_STATUS              ; get status
                    sbrs    r16, USART_TXCIF_BIT_NUMBER     ; check transmit complete interrupt flag
                    rjmp    usart0_write_br1                ; repeat when transmit is not completed

                    ret

;***************************************************************************************************
; @brief    Receives Data Frames
;
; @input    : XH:XL : 16-bit - data to receive start pointer
; @input    : r20   :  8-bit - data to receive length
;
; @output   : none
;
; @used     : r16 (changed)
;***************************************************************************************************
usart0_read:        ; wait until byte has been received
                    lds     r16, USART0_STATUS          ; get status
                    sbrs    r16, USART_RXCIF_BIT_NUMBER ; check receive complete interrupt flag
                    rjmp    usart0_read                 ; repeat when byte is not received

                    ; read received byte
                    lds     r16, USART0_RXDATAL         ; get data byte
                    st      X+, r16                     ; store byte at output pointer

                    ; check for last byte to receive
                    dec     r20                         ; decrease number of bytes to receive
                    brne    usart0_read                 ; repeat when not all bytes has been received

                    ret
