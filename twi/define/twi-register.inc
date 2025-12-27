;**********************************************************************************************;
; @description : Two-Wire Interface Peripheral                                                 ;
;**********************************************************************************************;

.IFNDEF TWI_REGISTER
.SET    TWI_REGISTER = 1

; TWI Registers Offset
.EQU TWI_OFFSET = 32

;**********************************************************************************************;
; @section : CTRLA - Control A                                                                 ;
;**********************************************************************************************;

; CTRLA - SDA Setup Time
.EQU TWI_CTRLA_SDASETUP_CYC4 = 0    ; 4 cycles
.EQU TWI_CTRLA_SDASETUP_CYC8 = 1    ; 8 cycles

; CTRLA - SDA Hold Time
.EQU TWI_CTRLA_SDAHOLD_OFF  = 0 ; hold time is off
.EQU TWI_CTRLA_SDAHOLD_50N  = 1 ; hold time 50 ns
.EQU TWI_CTRLA_SDAHOLD_300N = 2 ; hold time 300 ns
.EQU TWI_CTRLA_SDAHOLD_500N = 3 ; hold time 500 ns

; CTRLA - Fast Mode Plus Enable
.EQU TWI_CTRLA_FMPEN_OFF = 0
.EQU TWI_CTRLA_FMPEN_ON  = 1

;**********************************************************************************************;
; @section : MCTRLA - Host Control A                                                           ;
;**********************************************************************************************;

; MCTRLA - Read Interrupt Enable
.EQU TWI_MCTRLA_RIEN_OFF = 0
.EQU TWI_MCTRLA_RIEN_ON  = 1

; MCTRLA - Write Interrupt Enable
.EQU TWI_MCTRLA_WIEN_OFF = 0
.EQU TWI_MCTRLA_WIEN_ON  = 1

; MCTRLA - Quick Command Enable
.EQU TWI_MCTRLA_QCEN_OFF = 0
.EQU TWI_MCTRLA_QCEN_ON  = 1

; MCTRLA - Inactive Bus Time-Out
.EQU TWI_MCTRLA_TIMEOUT_OFF  = 0 ; bus time-out is disabled
.EQU TWI_MCTRLA_TIMEOUT_50U  = 1 ; bus time-out 50 us
.EQU TWI_MCTRLA_TIMEOUT_100U = 2 ; bus time-out 100 us
.EQU TWI_MCTRLA_TIMEOUT_200U = 3 ; bus time-out 200 us

; MCTRLA - Smart Mode Enable
.EQU TWI_MCTRLA_SMEN_OFF = 0
.EQU TWI_MCTRLA_SMEN_ON  = 1

; MCTRLA - Host Enable
.EQU TWI_MCTRLA_ENABLE_OFF = 0
.EQU TWI_MCTRLA_ENABLE_ON  = 1

;**********************************************************************************************;
; @section : MCTRLB - Host Control B                                                           ;
;**********************************************************************************************;

; MCTRLB - Flush
.EQU TWI_MCTRLB_FLUSH_OFF = 0
.EQU TWI_MCTRLB_FLUSH_ON  = 1

; MCTRLB - Acknowledge Action
.EQU TWI_MCTRLB_ACKACT_ACK  = 0
.EQU TWI_MCTRLB_ACKACT_NACK = 1

; MCTRLB - Command
.EQU TWI_MCTRLB_MCMD_REPSTART  = 1 ; execute repeated start condition
.EQU TWI_MCTRLB_MCMD_RECVTRANS = 2 ; execute byte write or byte read operation
.EQU TWI_MCTRLB_MCMD_STOP      = 3 ; execute stop condition

;**********************************************************************************************;
; @section : MSTATUS - Host Status                                                             ;
;**********************************************************************************************;

; MSTATUS - Read Interrupt Flag - Bit Position
.EQU TWI_MSTATUS_RIF_BPOS = TWI_RIF_bp

; MSTATUS - Write Interrupt Flag - Bit Position
.EQU TWI_MSTATUS_WIF_BPOS = TWI_WIF_bp

; MSTATUS - Clock Hold - Bit Position
.EQU TWI_MSTATUS_CLKHOLD_BPOS = TWI_CLKHOLD_bp

; MSTATUS - Bus State - Bit Mask
.EQU TWI_MSTATUS_BUSSTATE_BMASK = ~TWI_BUSSTATE_gm

; MSTATUS - Bus State
.EQU TWI_MSTATUS_BUSSTATE_UNKNOWN = 0
.EQU TWI_MSTATUS_BUSSTATE_IDLE    = 1
.EQU TWI_MSTATUS_BUSSTATE_OWNER   = 2
.EQU TWI_MSTATUS_BUSSTATE_BUSY    = 3

.ENDIF
