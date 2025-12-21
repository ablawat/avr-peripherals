;**********************************************************************************************;
; @section : Constant Data [FLASH]                                                             ;
;**********************************************************************************************;

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

; Configuration Instance Map
.EQU USART_CONFIG_MAP = (USART0_CONFIG_PRESENT << USART0_CONFIG_BPOS) | \
                        (USART1_CONFIG_PRESENT << USART1_CONFIG_BPOS)

; Configuration Base Address
.EQU USART_CONFIG_ADDRESS = (usart_config * 2)

; Configuration Address Offset
.EQU USART_CONFIG_OFFSET = 6

; @brief USART0 Enable
.EQU USART_RXTX_ENABLE = (USART_CTRLB_RXEN_ON << USART_RXEN_bp) | \
                         (USART_CTRLB_TXEN_ON << USART_TXEN_bp)

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

;**********************************************************************************************;
; @brief    Initializes Peripheral Registers
;
; @input    : ARG1  :  2-bit - [USART0, USART1]
; @output   : none
;
; @used     : ZH:ZL (changed), XH:XL (changed), TEMPH (changed), TEMPL (changed)
;**********************************************************************************************;
usart_init:     ; get selected instance base address
                rcall   usart_base_addr

                ; set pointer at control A register
                adiw    YL, USART_CTRLA_offset          ; move address forward

                ; get configuration base address
                ldi     ZH, HIGH (USART_CONFIG_ADDRESS)
                ldi     ZL, LOW  (USART_CONFIG_ADDRESS)

                ; get configuration map
                ldi     TEMPL, USART_CONFIG_MAP         ; get instance config flags

                ; check for last configuration
usart_init_br1: cpi     ARG1, 0                         ; check instance number
                breq    usart_init_br3                  ; finish when instance is first

                ; check instance bit inside map
                lsr     TEMPL                           ; shift out bit 0
                brcc    usart_init_br2                  ; when it is cleared

                ; set pointer at next configuration instance
                adiw    ZL, USART_CONFIG_OFFSET         ; move address one instance forward

                ; move to next configuration
usart_init_br2: dec     ARG1                            ; decrease instance number
                rjmp    usart_init_br1                  ; repeat for lower instance

                ; configure registers CTRLx
usart_init_br3: ldi     TEMPL, 3                        ; set number of CTRLx registers

usart_init_br4: lpm     TEMPH, Z+                       ; load configuration from flash
                st      Y+, TEMPH                       ; set CTRLx

                ; check for last register to write
                dec     TEMPL                           ; decrease number of registers
                brne    usart_init_br4                  ; repeat when not all registers has been set

                ; move to next register
                adiw    ZL, 1                           ; move pointer forward

                ; configure register BAUDL
                lpm     TEMPL, Z+                       ; load configuration from flash
                st      Y+, TEMPL                       ; set Baud Low

                ; configure register BAUDH
                lpm     TEMPL, Z+                       ; load configuration from flash
                st      Y+, TEMPL                       ; set Baud High

                ret

;**********************************************************************************************;
; @brief    Enables Transmitter and Receiver
;
; @input    : ARG1  :  2-bit - [USART0, USART1]
; @output   : none
;
; @used     : YH:YL (changed), TEMPL (changed)
;**********************************************************************************************;
usart_enable:   ; get selected instance base address
                rcall   usart_base_addr

                ; set pointer at control B register
                adiw    YL, USART_CTRLB_offset      ; move address forward

                ; enable transmitter and receiver
                ld      TEMPL, Y                    ; get control B register
                sbr     TEMPL, USART_RXTX_ENABLE
                st      Y, TEMPL                    ; set control B register

                ret

;**********************************************************************************************;
; @brief    Sends Data Frames
;
; @input    : ARG1  :  2-bit - [USART0, USART1]
; @input    : ARG2  :  8-bit - data to send length
; @input    : XH:XL : 16-bit - data to send start pointer
;
; @output   : none
;
; @used     : YH:YL (changed), TEMPL (changed)
;**********************************************************************************************;
usart_write:        ; get selected instance base address
                    rcall   usart_base_addr

                    ; set pointer at status register
                    adiw    YL, USART_STATUS_offset     ; move address forward

usart_write_br1:    ; wait until byte has been sent
                    ld      TEMPL, Y                    ; get status
                    sbrs    TEMPL, USART_DREIF_BPOS     ; check data register empty interrupt flag
                    rjmp    usart_write_br1             ; repeat when data register is not empty

                    ; set pointer at transmit data register low
                    sbiw    YL, 2                       ; move address backward

                    ; send byte
                    ld      TEMPL, X+                   ; read data byte from input pointer
                    st      Y, TEMPL                    ; write byte and trigger transmission

                    ; set pointer at status register
                    adiw    YL, 2                       ; move address forward

                    ; check for last byte to send
                    dec     ARG2                        ; decrease number of bytes to send
                    brne    usart_write_br1             ; repeat when not all bytes has been sent

usart_write_br2:    ; wait until last byte has been sent
                    ld      TEMPL, Y                    ; get status
                    sbrs    TEMPL, USART_TXCIF_BPOS     ; check transmit complete interrupt flag
                    rjmp    usart_write_br2             ; repeat when transmit is not completed

                    ret

;**********************************************************************************************;
; @brief    Receives Data Frames
;
; @input    : ARG1  :  2-bit - [USART0, USART1]
; @input    : ARG2  :  8-bit - data to receive length
; @input    : XH:XL : 16-bit - data to receive start pointer
;
; @output   : memory from X pointer is written
;
; @used     : YH:YL (changed), TEMPL (changed)
;**********************************************************************************************;
usart_read:         ; get selected instance base address
                    rcall   usart_base_addr

                    ; set pointer at status register
                    adiw    YL, USART_STATUS_offset     ; move address forward

usart_read_br1:     ; wait until byte has been received
                    ld      TEMPL, Y                    ; get status
                    sbrs    TEMPL, USART_RXCIF_BPOS     ; check receive complete interrupt flag
                    rjmp    usart_read_br1              ; repeat when byte is not received

                    ; set pointer at receiver data register low
                    sbiw    YL, 4                       ; move address backward

                    ; read received byte
                    ld      TEMPL, Y                    ; get data byte
                    st      X+, TEMPL                   ; store byte at output pointer

                    ; set pointer at status register
                    adiw    YL, 4                       ; move address forward

                    ; check for last byte to receive
                    dec     ARG2                        ; decrease number of bytes to receive
                    brne    usart_read_br1              ; repeat when not all bytes has been received

                    ret

;**********************************************************************************************;
; @brief    Calculates Instance Base Address
;
; @input    : ARG1  :  2-bit - [USART0, USART1]
; @output   : YH:YL : 16-bit - USART base address
;
; @used     : TEMPL (changed), r1 (changed), r0 (changed)
;**********************************************************************************************;
usart_base_addr:    ; get first instance base address
                    ldi     YH, HIGH (USART0_RXDATAL)
                    ldi     YL, LOW  (USART0_RXDATAL)

                    ; calculate selected instance address offset
                    ldi     TEMPL, USART_OFFSET
                    mul     ARG1, TEMPL

                    ; calculate selected instance address base
                    add     YL, r0 
                    adc     YH, r1 

                    ret
