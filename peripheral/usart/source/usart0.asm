;**********************************************************************************************;
; @description : Universal Synchronous and Asynchronous Receiver and Transmitter 0 Source      ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

.CSEG

;**********************************************************************************************;
; @brief    : Initializes Peripheral Registers
;
; @param    : none
; @return   : none
;
; @use      : XH:XL TEMP0
;**********************************************************************************************;
usart0_init:    ; get USART0 base address
                ldi     XH, HIGH (USART0_CTRLA)
                ldi     XL, LOW  (USART0_CTRLA)

                ; configure register CTRLA
                ldi     TEMP0, CONFIG_USART0_CTRLA          ; get config constant
                st      X+, TEMP0                           ; write into register

                ; configure register CTRLB
                ldi     TEMP0, CONFIG_USART0_CTRLB          ; get config constant
                st      X+, TEMP0                           ; write into register

                ; configure register CTRLC
                ldi     TEMP0, CONFIG_USART0_CTRLC          ; get config constant
                st      X+, TEMP0                           ; write into register

                ; configure register BAUDL
                ldi     TEMP0, LOW  (CONFIG_USART0_BAUD)    ; get config constant
                st      X+, TEMP0                           ; write into register

                ; configure register BAUDH
                ldi     TEMP0, HIGH (CONFIG_USART0_BAUD)    ; get config constant
                st      X+, TEMP0                           ; write into register

                ret

;**********************************************************************************************;
; @brief    : Enables Transmitter and Receiver
;
; @param    : none
; @return   : none
;
; @use      : TEMP0
;**********************************************************************************************;
usart0_enable:  ; enable transmitter and receiver
                lds     TEMP0, USART0_CTRLB         ; get Control B
                sbr     TEMP0, USART_RXTX_ENABLE    ; enable
                sts     USART0_CTRLB, TEMP0         ; set Control B

                ret

;**********************************************************************************************;
; @brief    : Sends Data Bytes
;
; @param    : XH:XL : 16-bit - a start pointer of data to send
; @param    : ARG0  :  8-bit - a length of data to send
;
; @return   : none
;
; @use      : TEMP0
;**********************************************************************************************;
usart0_write:       ; wait until byte has been sent
                    lds     TEMP0, USART0_STATUS        ; get status
                    sbrs    TEMP0, USART_DREIF_BPOS     ; check data register empty interrupt flag
                    rjmp    usart0_write                ; repeat when data register is not empty

                    ; send byte
                    ld      TEMP0, X+                   ; read data byte from input pointer
                    sts     USART0_TXDATAL, TEMP0       ; write byte and trigger transmission

                    ; check for last byte to send
                    dec     ARG0                        ; decrease number of bytes to send
                    brne    usart0_write                ; repeat when not all bytes has been sent

usart0_write_br1:   ; wait until last byte has been sent
                    lds     TEMP0, USART0_STATUS        ; get status
                    sbrs    TEMP0, USART_TXCIF_BPOS     ; check transmit complete interrupt flag
                    rjmp    usart0_write_br1            ; repeat when transmit is not completed

                    ret

;**********************************************************************************************;
; @brief    : Receives Data Bytes
;
; @param    : XH:XL : 16-bit - a start pointer of data to receive
; @param    : ARG0  :  8-bit - a length of data to receive
;
; @return   : DS(X) : memory of length ARG1
;
; @use      : TEMP0
;**********************************************************************************************;
usart0_read:    ; wait until byte has been received
                lds     TEMP0, USART0_STATUS        ; get status
                sbrs    TEMP0, USART_RXCIF_BPOS     ; check receive complete interrupt flag
                rjmp    usart0_read                 ; repeat when byte is not received

                ; read received byte
                lds     TEMP0, USART0_RXDATAL       ; get data byte
                st      X+, TEMP0                   ; store byte at output pointer

                ; check for last byte to receive
                dec     ARG0                        ; decrease number of bytes to receive
                brne    usart0_read                 ; repeat when not all bytes has been received

                ret
