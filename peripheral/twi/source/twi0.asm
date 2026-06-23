;**********************************************************************************************;
; @description : Two-Wire Interface 0 Source                                                   ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Local Definition                                                                  ;
;**********************************************************************************************;

; @brief Host Enable
.EQU TWI_HOST_ENABLE = (TWI_MCTRLA_ENABLE_ON << TWI_ENABLE_bp)

; @brief Host Status Idle
.EQU TWI_STATUS_IDLE = (TWI_MSTATUS_BUSSTATE_IDLE << TWI_BUSSTATE_gp)

; @brief Acknowledge and Stop
.EQU TWI_COMMAND_ACK_STOP = (TWI_MCTRLB_FLUSH_OFF  << TWI_FLUSH_bp ) | \
                            (TWI_MCTRLB_ACKACT_ACK << TWI_ACKACT_bp) | \
                            (TWI_MCTRLB_MCMD_STOP  << TWI_MCMD_gp  )

; @brief Not Acknowledge and Stop
.EQU TWI_COMMAND_NACK_STOP = (TWI_MCTRLB_FLUSH_OFF   << TWI_FLUSH_bp ) | \
                             (TWI_MCTRLB_ACKACT_NACK << TWI_ACKACT_bp) | \
                             (TWI_MCTRLB_MCMD_STOP   << TWI_MCMD_gp  )

; @brief Read
.EQU TWI_COMMAND_READ = (TWI_MCTRLB_FLUSH_OFF      << TWI_FLUSH_bp ) | \
                        (TWI_MCTRLB_ACKACT_ACK     << TWI_ACKACT_bp) | \
                        (TWI_MCTRLB_MCMD_RECVTRANS << TWI_MCMD_gp  )

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

.CSEG

;**********************************************************************************************;
; @brief    : Initializes TWI0 Peripheral
;
; @param    : none
; @return   : none
;
; @use      : XH:XL TEMP0
;**********************************************************************************************;
twi0_init:  ; get TWI0 base address
            ldi     XH, HIGH (TWI0_base)
            ldi     XL, LOW  (TWI0_base)

            ; configure register Control A
            ldi     TEMP0, CONFIG_TWI0_CTRLA    ; get config constant
            st      X, TEMP0                    ; write into register

            ; skip three registers
            adiw    XL, 3                       ; move pointer forward

            ; configure register Host Control A
            ldi     TEMP0, CONFIG_TWI0_MCTRLA   ; get config constant
            st      X, TEMP0                    ; write into register

            ; skip three registers
            adiw    XL, 3                       ; move pointer forward

            ; configure register Host Baud Rate
            ldi     TEMP0, CONFIG_TWI0_MBAUD    ; get config constant
            st      X, TEMP0                    ; write into register

            ret

;**********************************************************************************************;
; @brief    : Enables Host
;
; @param    : none
; @return   : none
;
; @use      : TEMP0
;**********************************************************************************************;
twi0_enable:    ; enable host
                lds     TEMP0, TWI0_MCTRLA      ; get Host Control A
                sbr     TEMP0, TWI_HOST_ENABLE  ; enable host
                sts     TWI0_MCTRLA, TEMP0      ; set Host Control A

                ; set bus state to idle
                ldi     TEMP0, TWI_STATUS_IDLE  ; set idle state
                sts     TWI0_MSTATUS, TEMP0     ; set host status

                ret

;**********************************************************************************************;
; @brief    : Sends Data Bytes
;
; @param    : XH:XL : 16-bit - a start pointer of data to send
; @param    : ARG0  :  8-bit - a length of data to send
; @param    : ARG1  :  7-bit - an address of client device
; @param    : ARG2  :  1-bit - stop or repeat
;
; @return   : none
;
; @use      : TEMP0
;**********************************************************************************************;
twi0_write:     ; send control byte
                cbr     ARG1, 0x01                          ; set direction bit to write
                sts     TWI0_MADDR, ARG1                    ; send start condition + client address + write

twi0_write_br1: ; wait until byte has been sent
                lds     TEMP0, TWI0_MSTATUS                 ; get host status
                sbrs    TEMP0, TWI_MSTATUS_WIF_BPOS         ; check write complete interrupt flag
                rjmp    twi0_write_br1                      ; repeat when write is not completed

twi0_write_br2: ; send byte
                ld      TEMP0, X+                           ; read data from input pointer
                sts     TWI0_MDATA, TEMP0                   ; set data byte

twi0_write_br3: ; wait until byte has been sent
                lds     TEMP0, TWI0_MSTATUS                 ; get host status
                sbrs    TEMP0, TWI_MSTATUS_WIF_BPOS         ; check write complete interrupt flag
                rjmp    twi0_write_br3                      ; repeat when write is not completed

                ; check for last byte to send
                dec     ARG0                                ; decrease number of bytes to send
                brne    twi0_write_br2                      ; repeat when not all bytes has been sent

                ; check for stop condition
                sbrc    ARG2, 0                             ; when stop condition is not going to be sent
                rjmp    twi0_write_br5                      ; terminate writing and leave the bus as owned

                ; send stop condition
                ldi     TEMP0, TWI_COMMAND_ACK_STOP         ; set stop condition command
                sts     TWI0_MCTRLB, TEMP0                  ; send stop condition

twi0_write_br4: ; check for bus state
                lds     TEMP0, TWI0_MSTATUS                 ; get host status
                cbr     TEMP0, TWI_MSTATUS_BUSSTATE_BMASK   ; get bus state

                ; wait until bus state is idle
                cpi     TEMP0, TWI_STATUS_IDLE              ; check for idle state
                brne    twi0_write_br4                      ; repeat when bus is not idle

twi0_write_br5: ret

;**********************************************************************************************;
; @brief    : Receives Data Bytes
;
; @param    : XH:XL : 16-bit - a start pointer of data to receive
; @param    : ARG0  :  8-bit - a length of data to receive
; @param    : ARG1  :  7-bit - an address of client device
; @param    : ARG2  :  1-bit - stop or repeat
;
; @return   : DS(X) : memory of length ARG1
;
; @use      : TEMP0
;**********************************************************************************************;
twi0_read:      ; send control byte
                sbr     ARG1, 0x01                          ; set direction bit to read
                sts     TWI0_MADDR, ARG1                    ; send start condition + client address + read

twi0_read_br1:  ; wait until byte has been received
                lds     TEMP0, TWI0_MSTATUS                 ; get host status
                sbrs    TEMP0, TWI_MSTATUS_RIF_BPOS         ; check read complete interrupt flag
                rjmp    twi0_read_br1                       ; repeat when read is not completed

                ; read received byte
                lds     TEMP0, TWI0_MDATA                   ; get data byte
                st      X+, TEMP0                           ; store data at output pointer

                ; check for last byte to receive
                dec     ARG0                                ; decrease number of bytes to receive
                breq    twi0_read_br2                       ; repeat when not all bytes has been received

                ; receive byte
                ldi     TEMP0, TWI_COMMAND_READ             ; set byte read command
                sts     TWI0_MCTRLB, TEMP0                  ; send acknowledge + receive next data byte

                ; wait for next byte
                rjmp    twi0_read_br1                       ; go to receive byte

twi0_read_br2:  ; check for stop condition
                sbrc    ARG2, 0                             ; when stop condition is not going to be sent
                rjmp    twi0_read_br4                       ; terminate reading and leave the bus as owned

                ; send stop condition
                ldi     TEMP0, TWI_COMMAND_NACK_STOP        ; set stop condition command
                sts     TWI0_MCTRLB, TEMP0                  ; send not acknowledge + stop condition

twi0_read_br3:  ; check for bus state
                lds     TEMP0, TWI0_MSTATUS                 ; get host status
                cbr     TEMP0, TWI_MSTATUS_BUSSTATE_BMASK   ; get bus state

                ; wait until bus state is idle
                cpi     TEMP0, TWI_STATUS_IDLE              ; check for idle state
                brne    twi0_read_br3                       ; repeat when bus is not idle

twi0_read_br4:  ret

;**********************************************************************************************;
; @brief    : Checks Client Device Response
;
; @param    : ARG1 : 7-bit - an address of client device
;
; @return   : TEMP0
;
; @use      : TEMP1
;**********************************************************************************************;
twi0_check:     ; send control byte
                cbr     ARG1, 0x01                          ; set direction bit to write
                sts     TWI0_MADDR, ARG1                    ; send start condition + client address + write

twi0_check_br1: ; wait until byte has been sent
                lds     TEMP0, TWI0_MSTATUS                 ; get host status
                sbrs    TEMP0, TWI_MSTATUS_WIF_BPOS         ; check write complete interrupt flag
                rjmp    twi0_check_br1                      ; repeat when write is not completed

                ; check client device response
                sbrs    TEMP0, TWI_MSTATUS_RXACK_BPOS       ; check received acknowledge flag
                rjmp    twi0_check_br2                      ; when client has acknowledged

                ; not acknowledge was received
                ldi     TEMP0, 0x00                         ; set failure flag
                rjmp    twi0_check_br3                      ; go to end

twi0_check_br2: ; acknowledge was received
                ldi     TEMP0, 0x01                         ; set success flag

twi0_check_br3: ; send stop condition
                ldi     TEMP1, TWI_COMMAND_ACK_STOP         ; set stop condition command
                sts     TWI0_MCTRLB, TEMP1                  ; send stop condition

twi0_check_br4: ; check for bus state
                lds     TEMP1, TWI0_MSTATUS                 ; get host status
                cbr     TEMP1, TWI_MSTATUS_BUSSTATE_BMASK   ; get bus state

                ; wait until bus state is idle
                cpi     TEMP1, TWI_STATUS_IDLE              ; check for idle state
                brne    twi0_check_br4                      ; repeat when bus is not idle

                ret
