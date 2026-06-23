;**********************************************************************************************;
; @description : Universal Synchronous and Asynchronous Receiver and Transmitter Source        ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Constant Data [FLASH]                                                             ;
;**********************************************************************************************;

.CSEG

; clear instance config flags
.SET USART0_CONFIG_PRESENT = 0
.SET USART1_CONFIG_PRESENT = 0

usart_config:   ; Start of USART Config

; when configuration for USART0 is included
.IFDEF USART0_CONFIG_DEFINE
                ; Control Registers Configuration
usart0_config:  .DB CONFIG_USART0_CTRLA, CONFIG_USART0_CTRLB
                .DB CONFIG_USART0_CTRLC, 0x00
                ; Baud Register Configuration
                .DW CONFIG_USART0_BAUD
; set instance config flag
.SET USART0_CONFIG_PRESENT = 1
.ENDIF

; when configuration for USART1 is included
.IFDEF USART1_CONFIG_DEFINE
                ; Control Registers Configuration
usart1_config:  .DB CONFIG_USART1_CTRLA, CONFIG_USART1_CTRLB
                .DB CONFIG_USART1_CTRLC, 0x00
                ; Baud Register Configuration
                .DW CONFIG_USART1_BAUD
; set instance config flag
.SET USART1_CONFIG_PRESENT = 1
.ENDIF

;**********************************************************************************************;
; @section : Local Definition                                                                  ;
;**********************************************************************************************;

.EQU USART0_CONFIG_BPOS = 0
.EQU USART1_CONFIG_BPOS = 1

; @brief Configuration Instance Map
.EQU USART_CONFIG_MAP = (USART0_CONFIG_PRESENT << USART0_CONFIG_BPOS) | \
                        (USART1_CONFIG_PRESENT << USART1_CONFIG_BPOS)

; @brief Configuration Base Address
.EQU USART_CONFIG_ADDRESS = (usart_config * 2)

; @brief Configuration Address Offset
.EQU USART_CONFIG_OFFSET = 6

; @brief Enable Transmitter and Receiver
.EQU USART_RXTX_ENABLE = (USART_CTRLB_RXEN_ON << USART_RXEN_bp) | \
                         (USART_CTRLB_TXEN_ON << USART_TXEN_bp)

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

.CSEG

;**********************************************************************************************;
; @brief    : Initializes Peripheral Registers
;
; @param    : ARG0  :  2-bit - [USART0, USART1]
; @return   : none
;
; @use      : ZH:ZL YH:YL TEMP1:TEMP0
;**********************************************************************************************;
usart_init:     ; get selected instance base address
                rcall   usart_base_addr

                ; set pointer at control A register
                adiw    YL, USART_CTRLA_offset          ; move address forward

                ; get configuration base address
                ldi     ZH, HIGH (USART_CONFIG_ADDRESS)
                ldi     ZL, LOW  (USART_CONFIG_ADDRESS)

                ; get configuration map
                ldi     TEMP0, USART_CONFIG_MAP         ; get instance config flags

usart_init_br1: ; check for last configuration
                cpi     ARG0, 0                         ; check instance number
                breq    usart_init_br3                  ; finish when instance is first

                ; check instance bit inside map
                lsr     TEMP0                           ; shift out bit 0
                brcc    usart_init_br2                  ; when it is cleared

                ; set pointer at next configuration instance
                adiw    ZL, USART_CONFIG_OFFSET         ; move address one instance forward

usart_init_br2: ; move to next configuration
                dec     ARG0                            ; decrease instance number
                rjmp    usart_init_br1                  ; repeat for lower instance

usart_init_br3: ; prepare for registers configuration
                ldi     TEMP0, 3                        ; set number of CTRLx registers

usart_init_br4: ; configure register CTRLx
                lpm     TEMP1, Z+                       ; load configuration from flash
                st      Y+, TEMP1                       ; write into register

                ; check for last register to write
                dec     TEMP0                           ; decrease number of registers
                brne    usart_init_br4                  ; repeat when not all registers has been set

                ; move to next register
                adiw    ZL, 1                           ; move pointer forward

                ; configure register BAUDL
                lpm     TEMP0, Z+                       ; load configuration from flash
                st      Y+, TEMP0                       ; write into register

                ; configure register BAUDH
                lpm     TEMP0, Z+                       ; load configuration from flash
                st      Y+, TEMP0                       ; write into register

                ret

;**********************************************************************************************;
; @brief    : Enables Transmitter and Receiver
;
; @param    : ARG0  :  2-bit - [USART0, USART1]
; @return   : none
;
; @use      : YH:YL TEMP0
;**********************************************************************************************;
usart_enable:   ; get selected instance base address
                rcall   usart_base_addr

                ; set pointer at control B register
                adiw    YL, USART_CTRLB_offset      ; move address forward

                ; enable transmitter and receiver
                ld      TEMP0, Y                    ; get control B register
                sbr     TEMP0, USART_RXTX_ENABLE    ; enable
                st      Y, TEMP0                    ; set control B register

                ret

;**********************************************************************************************;
; @brief    : Sends Data Bytes
;
; @param    : ARG0  :  2-bit - [USART0, USART1]
; @param    : ARG1  :  8-bit - a length of data to send
; @param    : XH:XL : 16-bit - a start pointer of data to send
;
; @return   : none
;
; @use      : YH:YL TEMP0
;**********************************************************************************************;
usart_write:        ; get selected instance base address
                    rcall   usart_base_addr

                    ; set pointer at status register
                    adiw    YL, USART_STATUS_offset     ; move address forward

usart_write_br1:    ; wait until byte has been sent
                    ld      TEMP0, Y                    ; get status
                    sbrs    TEMP0, USART_DREIF_BPOS     ; check data register empty interrupt flag
                    rjmp    usart_write_br1             ; repeat when data register is not empty

                    ; set pointer at transmit data register low
                    sbiw    YL, 2                       ; move address backward

                    ; send byte
                    ld      TEMP0, X+                   ; read data byte from input pointer
                    st      Y, TEMP0                    ; write byte and trigger transmission

                    ; set pointer at status register
                    adiw    YL, 2                       ; move address forward

                    ; check for last byte to send
                    dec     ARG1                        ; decrease number of bytes to send
                    brne    usart_write_br1             ; repeat when not all bytes has been sent

usart_write_br2:    ; wait until last byte has been sent
                    ld      TEMP0, Y                    ; get status
                    sbrs    TEMP0, USART_TXCIF_BPOS     ; check transmit complete interrupt flag
                    rjmp    usart_write_br2             ; repeat when transmit is not completed

                    ret

;**********************************************************************************************;
; @brief    : Receives Data Bytes
;
; @param    : ARG0  :  2-bit - [USART0, USART1]
; @param    : ARG1  :  8-bit - a length of data to receive
; @param    : XH:XL : 16-bit - a start pointer of data to receive
;
; @return   : DS(X) : memory of length ARG1
;
; @use      : YH:YL TEMP0
;**********************************************************************************************;
usart_read:         ; get selected instance base address
                    rcall   usart_base_addr

                    ; set pointer at status register
                    adiw    YL, USART_STATUS_offset     ; move address forward

usart_read_br1:     ; wait until byte has been received
                    ld      TEMP0, Y                    ; get status
                    sbrs    TEMP0, USART_RXCIF_BPOS     ; check receive complete interrupt flag
                    rjmp    usart_read_br1              ; repeat when byte is not received

                    ; set pointer at receiver data register low
                    sbiw    YL, 4                       ; move address backward

                    ; read received byte
                    ld      TEMP0, Y                    ; get data byte
                    st      X+, TEMP0                   ; store byte at output pointer

                    ; set pointer at status register
                    adiw    YL, 4                       ; move address forward

                    ; check for last byte to receive
                    dec     ARG1                        ; decrease number of bytes to receive
                    brne    usart_read_br1              ; repeat when not all bytes has been received

                    ret

;**********************************************************************************************;
; @brief    : Calculates Instance Base Address
;
; @param    : ARG0  :  2-bit - [USART0, USART1]
; @return   : YH:YL : 16-bit - USART base address
;
; @use      : TEMP0 RESH:RESL
;**********************************************************************************************;
usart_base_addr:    ; get first instance base address
                    ldi     YH, HIGH (USART0_RXDATAL)
                    ldi     YL, LOW  (USART0_RXDATAL)

                    ; calculate selected instance address offset
                    ldi     TEMP0, USART_OFFSET
                    mul     ARG0, TEMP0

                    ; calculate selected instance address base
                    add     YL, RESL
                    adc     YH, RESH

                    ret
