;**********************************************************************************************;
; @description : Two-Wire Interface 0 Header                                                   ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "twi/config/twi0-config.inc"
.INCLUDE "twi/source/twi-typedef.inc"

;**********************************************************************************************;
; @section : Register Configuration                                                            ;
;**********************************************************************************************;

; CTRLA - SDA Setup Time
.EQU CONFIG_TWI0_CTRLA_SDASETUP = CONFIG_TWI0_SDA_SETUP_TIME

; CTRLA - SDA Hold Time
.EQU CONFIG_TWI0_CTRLA_SDAHOLD  = CONFIG_TWI0_SDA_HOLD_TIME

; CTRLA - Fast Mode Plus Enable
.EQU CONFIG_TWI0_CTRLA_FMPEN    = CONFIG_TWI0_FAST_MODE_PLUS

; @brief Control A Register
.EQU CONFIG_TWI0_CTRLA = (CONFIG_TWI0_CTRLA_SDASETUP << TWI_SDASETUP_bp) | \
                         (CONFIG_TWI0_CTRLA_SDAHOLD  << TWI_SDAHOLD_gp ) | \
                         (CONFIG_TWI0_CTRLA_FMPEN    << TWI_FMPEN_bp   )

; MCTRLA - Read Interrupt Enable
.EQU CONFIG_TWI0_MCTRLA_RIEN = CONFIG_TWI0_READ_INTERRUPT

; MCTRLA - Write Interrupt Enable
.EQU CONFIG_TWI0_MCTRLA_WIEN = CONFIG_TWI0_WRITE_INTERRUPT

; MCTRLA - Quick Command Enable
.EQU CONFIG_TWI0_MCTRLA_QCEN = CONFIG_TWI0_QUICK_COMMAND

; MCTRLA - Inactive Bus Time-Out
.EQU CONFIG_TWI0_MCTRLA_TIMEOUT = CONFIG_TWI0_BUS_TIMEOUT

; MCTRLA - Smart Mode Enable
.EQU CONFIG_TWI0_MCTRLA_SMEN = CONFIG_TWI0_SMART_MODE

; MCTRLA - Host Enable
.EQU CONFIG_TWI0_MCTRLA_ENABLE = TWI_MCTRLA_ENABLE_OFF

; @brief Host Control A Register
.EQU CONFIG_TWI0_MCTRLA = (CONFIG_TWI0_MCTRLA_RIEN    << TWI_RIEN_bp   ) | \
                          (CONFIG_TWI0_MCTRLA_WIEN    << TWI_WIEN_bp   ) | \
                          (CONFIG_TWI0_MCTRLA_QCEN    << TWI_QCEN_bp   ) | \
                          (CONFIG_TWI0_MCTRLA_TIMEOUT << TWI_TIMEOUT_gp) | \
                          (CONFIG_TWI0_MCTRLA_SMEN    << TWI_SMEN_bp   ) | \
                          (CONFIG_TWI0_MCTRLA_ENABLE  << TWI_ENABLE_bp )

; comment
.EQU TWI0_TIME_RISE_DIV = (TWI_ONE_SECOND_IN_NS / CONFIG_TWI0_BUS_RISE_TIME)

; @brief Host Baud Rate Register
.EQU CONFIG_TWI0_MBAUD = (PERIPHERAL_CLOCK_FREQUENCY / (2 * CONFIG_TWI0_BAUD_RATE)) - \
                         (5 + ((PERIPHERAL_CLOCK_FREQUENCY / TWI0_TIME_RISE_DIV) / 2))

; @brief Configuration Marker
.EQU TWI0_CONFIG_DEFINE = 1
