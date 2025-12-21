;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

;**********************************************************************************************;
; @brief    Initializes USART0 Peripheral
;
; @input    : none
; @output   : none
;
; @used     : XH:XL (changed), TEMPL (changed)
;**********************************************************************************************;
usart0_init:    ; get USART0 base address
                ldi     XH, HIGH (USART0_CTRLA)
                ldi     XL, LOW  (USART0_CTRLA)

                ; configure register CTRLA
                ldi     TEMPL, CONFIG_USART0_CTRLA          ; get config constant
                st      X+, TEMPL                           ; write into register

                ; configure register CTRLB
                ldi     TEMPL, CONFIG_USART0_CTRLB          ; get config constant
                st      X+, TEMPL                           ; write into register

                ; configure register CTRLC
                ldi     TEMPL, CONFIG_USART0_CTRLC          ; get config constant
                st      X+, TEMPL                           ; write into register

                ; configure register BAUDL
                ldi     TEMPL, LOW  (CONFIG_USART0_BAUD)    ; get config constant
                st      X+, TEMPL                           ; write into register

                ; configure register BAUDH
                ldi     TEMPL, HIGH (CONFIG_USART0_BAUD)    ; get config constant
                st      X+, TEMPL                           ; write into register

                ret

;**********************************************************************************************;
; @brief    Enables USART0 Transmitter and Receiver
;
; @input    : none
; @output   : none
;
; @used     : TEMPL (changed)
;**********************************************************************************************;
usart0_enable:  ; enable transmitter and receiver
                lds     TEMPL, USART0_CTRLB         ; get Control B
                sbr     TEMPL, USART_RXTX_ENABLE
                sts     USART0_CTRLB, TEMPL         ; set Control B

                ret

;**********************************************************************************************;
; @brief    Sends Data Frames
;
; @input    : XH:XL : 16-bit - data to send start pointer
; @input    : ARG1  :  8-bit - data to send length
;
; @output   : none
;
; @used     : TEMPL (changed)
;**********************************************************************************************;
usart0_write:       ; wait until byte has been sent
                    lds     TEMPL, USART0_STATUS        ; get status
                    sbrs    TEMPL, USART_DREIF_BPOS     ; check data register empty interrupt flag
                    rjmp    usart0_write                ; repeat when data register is not empty

                    ; send byte
                    ld      TEMPL, X+                   ; read data byte from input pointer
                    sts     USART0_TXDATAL, TEMPL       ; write byte and trigger transmission

                    ; check for last byte to send
                    dec     ARG1                        ; decrease number of bytes to send
                    brne    usart0_write                ; repeat when not all bytes has been sent

usart0_write_br1:   ; wait until last byte has been sent
                    lds     TEMPL, USART0_STATUS        ; get status
                    sbrs    TEMPL, USART_TXCIF_BPOS     ; check transmit complete interrupt flag
                    rjmp    usart0_write_br1            ; repeat when transmit is not completed

                    ret

;**********************************************************************************************;
; @brief    Receives Data Frames
;
; @input    : XH:XL : 16-bit - data to receive start pointer
; @input    : ARG1  :  8-bit - data to receive length
;
; @output   : memory from X pointer is written
;
; @used     : TEMPL (changed)
;**********************************************************************************************;
usart0_read:    ; wait until byte has been received
                lds     TEMPL, USART0_STATUS        ; get status
                sbrs    TEMPL, USART_RXCIF_BPOS     ; check receive complete interrupt flag
                rjmp    usart0_read                 ; repeat when byte is not received

                ; read received byte
                lds     TEMPL, USART0_RXDATAL       ; get data byte
                st      X+, TEMPL                   ; store byte at output pointer

                ; check for last byte to receive
                dec     ARG1                        ; decrease number of bytes to receive
                brne    usart0_read                 ; repeat when not all bytes has been received

                ret
