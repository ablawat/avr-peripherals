;***************************************************************************************************
;**     Include Files                                                                             **
;***************************************************************************************************

.INCLUDE "twi/twi0-config.inc"

;***************************************************************************************************
;**     Constant Configuration Registers Definitions                                              **
;***************************************************************************************************

; @brief TWI0 Control A Register
.EQU CONFIG_TWI0_CTRLA = CONFIG_TWI0_SDA_SETUP_TIME | \
                         CONFIG_TWI0_SDA_HOLD_TIME  | \
                         CONFIG_TWI0_FAST_MODE_PLUS

; @brief TWI0 Host Control A Register
.EQU CONFIG_TWI0_MCTRLA = CONFIG_TWI0_READ_INTERRUPT  | \
                          CONFIG_TWI0_WRITE_INTERRUPT | \
                          CONFIG_TWI0_QUICK_COMMAND   | \
                          CONFIG_TWI0_BUS_TIMEOUT     | \
                          CONFIG_TWI0_SMART_MODE      | \
                          TWI_HOST_DISABLED

; comment
.EQU TIME_RISE = 200    ; [ns]

; comment
.EQU TIME_RISE_DIV = (1000000000 / TIME_RISE)

; @brief TWI0 Host Baud Rate Register
.EQU CONFIG_TWI0_MBAUD = (PERIPHERAL_CLOCK_FREQUENCY / (2 * CONFIG_TWI0_BAUD_RATE)) - \
                         (5 + ((PERIPHERAL_CLOCK_FREQUENCY / TIME_RISE_DIV) / 2))
