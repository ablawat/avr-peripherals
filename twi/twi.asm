;***************************************************************************************************
;**     Include Files                                                                             **
;***************************************************************************************************

.INCLUDE "twi/twi0.inc"

;***************************************************************************************************
;**     Code Section [FLASH]                                                                      **
;***************************************************************************************************

;***************************************************************************************************
; @brief    Initializes TWI0 Peripheral
;
; @input    : none
; @output   : none
;
; @used     : XH:XL (changed), r16 (changed)
;***************************************************************************************************
twi0_init:  ; get TWI0 base address
            ldi     XH, HIGH (TWI0_base)
            ldi     XL, LOW  (TWI0_base)

            ; configure register TWI0 CTRLA
            ldi     r16, CONFIG_TWI0_CTRLA      ; get CTRLA config
            st      X, r16                      ; set Control A

            ; skip three registers
            adiw    XL, 3                       ; move pointer forward

            ; configure register TWI0 MCTRLA
            ldi     r16, CONFIG_TWI0_MCTRLA     ; get MCTRLA config
            st      X, r16                      ; set Host Control A

            ; skip three registers
            adiw    XL, 3                       ; move pointer forward

            ; configure register TWI0 MBAUD
            ldi     r16, CONFIG_TWI0_MBAUD      ; get MBAUD config
            st      X, r16                      ; set Host Baud Rate

            ; enable host
            lds     r16, TWI0_MCTRLA            ; get Host Control A
            sbr     r16, TWI_HOST_ENABLED       ; enable host
            sts     TWI0_MCTRLA, r16            ; set Host Control A

            ; set bus state to idle
            ldi     r16, TWI_STATUS_IDLE        ; set idle state
            sts     TWI0_MSTATUS, r16           ; set host status

            ret

;***************************************************************************************************
; @brief    Writes Data
;
; @input    : XH:XL : 16-bit - data to send start pointer    
; @input    : r20   :  8-bit - data to send length
; @input    : r21   :  7-bit - client device address
; @input    : r22   :  1-bit - stop or repeat
;
; @output   : none
;
; @used     : 
;***************************************************************************************************
twi0_write:         ; send control byte
                    cbr     r21, 0x01                   ; set direction bit to write
                    sts     TWI0_MADDR, r21             ; send start condition + client address + write

twi0_write_br1:     ; wait until byte has been sent
                    lds     r16, TWI0_MSTATUS           ; get host status
                    sbrs    r16, TWI_WIF_BIT_NUMBER     ; check write complete interrupt flag
                    rjmp    twi0_write_br1              ; repeat when write is not completed

                    ; send byte
twi0_write_br2:     ld      r16, X+                     ; read data from input pointer
                    sts     TWI0_MDATA, r16             ; set data byte

twi0_write_br3:     ; wait until byte has been sent
                    lds     r16, TWI0_MSTATUS           ; get host status
                    sbrs    r16, TWI_WIF_BIT_NUMBER     ; check write complete interrupt flag
                    rjmp    twi0_write_br3              ; repeat when write is not completed

                    ; check for last byte to send
                    dec     r20                         ; decrease number of bytes to send
                    brne    twi0_write_br2              ; repeat when not all bytes has been sent

                    ; check for stop condition
                    sbrc    r22, 0                      ; when stop condition is not going to be sent
                    rjmp    twi0_write_br5              ; terminate writing and leave the bus as owned

                    ; send stop condition
                    ldi     r16, 3                      ; set stop condition command
                    sts     TWI0_MCTRLB, r16            ; send stop condition

twi0_write_br4:     ; check for bus state
                    lds     r16, TWI0_MSTATUS           ; get host status
                    cbr     r16, TWI_BUS_STATE_BIT_MASK ; get bus state

                    ; wait until bus state is idle
                    cpi     r16, TWI_STATUS_IDLE        ; check for idle state
                    brne    twi0_write_br4              ; repeat when bus is not idle

twi0_write_br5:     ret

;***************************************************************************************************
; @brief    Reads Data
;
; @input    : XH:XL : 16-bit - data to receive start pointer    
; @input    : r20   :  8-bit - data to receive length
; @input    : r21   :  7-bit - client device address
; @input    : r22   :  1-bit - stop or repeat
;
; @output   : XH:XL : 16-bit - data to receive start pointer    
;
; @used     : r0 (unchanged)
;***************************************************************************************************
twi0_read:          ; send control byte
                    sbr     r21, 0x01                   ; set direction bit to read
                    sts     TWI0_MADDR, r21             ; send start condition + client address + read

twi0_read_br1:      ; wait until byte has been received
                    lds     r16, TWI0_MSTATUS           ; get host status
                    sbrs    r16, TWI_RIF_BIT_NUMBER     ; check read complete interrupt flag
                    rjmp    twi0_read_br1               ; repeat when read is not completed

                    ; read received byte
                    lds     r16, TWI0_MDATA             ; get data byte
                    st      X+, r16                     ; store data at output pointer

                    ; check for last byte to receive
                    dec     r20                         ; decrease number of bytes to receive
                    breq    twi0_read_br2               ; repeat when not all bytes has been received

                    ; receive byte
                    ldi     r16, 2                      ; set byte read command
                    sts     TWI0_MCTRLB, r16            ; send acknowledge + receive next data byte

                    ; wait for next byte
                    rjmp    twi0_read_br1               ; go to receive byte

                    ; check for stop condition
twi0_read_br2:      sbrc    r22, 0                      ; when stop condition is not going to be sent
                    rjmp    twi0_read_br4               ; terminate reading and leave the bus as owned

                    ; send stop condition
                    ldi     r16, 7                      ; set stop condition command
                    sts     TWI0_MCTRLB, r16            ; send not acknowledge + stop condition

twi0_read_br3:      ; check for bus state
                    lds     r16, TWI0_MSTATUS           ; get host status
                    cbr     r16, TWI_BUS_STATE_BIT_MASK ; get bus state

                    ; wait until bus state is idle
                    cpi     r16, TWI_STATUS_IDLE        ; check for idle state
                    brne    twi0_read_br3               ; repeat when bus is not idle

twi0_read_br4:      ret
