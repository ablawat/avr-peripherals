;**********************************************************************************************;
; @description : Two-Wire Interface Peripheral Definition                                      ;
;**********************************************************************************************;

.IFNDEF TWI_DEFINE
.SET    TWI_DEFINE = 1

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "twi/define/twi-register.inc"

.INCLUDE "macro/registers.inc"
.INCLUDE "macro/config.inc"

;**********************************************************************************************;
; @section : Configuration Option Definition                                                   ;
;**********************************************************************************************;

; @brief TWI - SDA Setup Time
.EQU TWI_SDA_SETUP_TIME_CYCLES_4 = TWI_CTRLA_SDASETUP_CYC4
.EQU TWI_SDA_SETUP_TIME_CYCLES_8 = TWI_CTRLA_SDASETUP_CYC8

; @brief TWI - SDA Hold Time
.EQU TWI_SDA_HOLD_TIME_OFF  = TWI_CTRLA_SDAHOLD_OFF
.EQU TWI_SDA_HOLD_TIME_50N  = TWI_CTRLA_SDAHOLD_50N
.EQU TWI_SDA_HOLD_TIME_300N = TWI_CTRLA_SDAHOLD_300N
.EQU TWI_SDA_HOLD_TIME_500N = TWI_CTRLA_SDAHOLD_500N

; @brief TWI - Fast Mode Plus
.EQU TWI_FAST_MODE_PLUS_DISABLED = TWI_CTRLA_FMPEN_OFF
.EQU TWI_FAST_MODE_PLUS_ENABLED  = TWI_CTRLA_FMPEN_ON

; @brief TWI - Read Interrupt Enable
.EQU TWI_READ_INTERRUPT_DISABLED = TWI_MCTRLA_RIEN_OFF
.EQU TWI_READ_INTERRUPT_ENABLED  = TWI_MCTRLA_RIEN_ON

; @brief TWI - Write Interrupt Enable
.EQU TWI_WRITE_INTERRUPT_DISABLED = TWI_MCTRLA_WIEN_OFF
.EQU TWI_WRITE_INTERRUPT_ENABLED  = TWI_MCTRLA_WIEN_ON

; @brief TWI - Quick Command Enable
.EQU TWI_QUICK_COMMAND_DISABLED = TWI_MCTRLA_QCEN_OFF
.EQU TWI_QUICK_COMMAND_ENABLED  = TWI_MCTRLA_QCEN_ON

; @brief TWI - Inactive Bus Time-Out
.EQU TWI_BUS_TIMEOUT_DISABLED = TWI_MCTRLA_TIMEOUT_OFF
.EQU TWI_BUS_TIMEOUT_50U      = TWI_MCTRLA_TIMEOUT_50U
.EQU TWI_BUS_TIMEOUT_100U     = TWI_MCTRLA_TIMEOUT_100U
.EQU TWI_BUS_TIMEOUT_200U     = TWI_MCTRLA_TIMEOUT_200U

; @brief TWI - Smart Mode Enable
.EQU TWI_SMART_MODE_DISABLED = TWI_MCTRLA_SMEN_OFF
.EQU TWI_SMART_MODE_ENABLED  = TWI_MCTRLA_SMEN_ON

; @brief TWI - Host Enable
.EQU TWI_HOST_DISABLED = TWI_MCTRLA_ENABLE_OFF
.EQU TWI_HOST_ENABLED  = TWI_MCTRLA_ENABLE_ON

.ENDIF
