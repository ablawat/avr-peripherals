.INCLUDE "twi/twi-def.inc"

;**
;** @brief  SDA Setup Time
;**
;** @value  SDA Setup Time Configuration Options
;**
.EQU CONFIG_TWI0_SDA_SETUP_TIME = TWI_SDA_SETUP_TIME_CYCLES_4

;**
;** @brief  SDA Hold Time
;**
;** @value  SDA Hold Time Configuration Options
;**
.EQU CONFIG_TWI0_SDA_HOLD_TIME = TWI_SDA_HOLD_TIME_50N

;**
;** @brief  Fast Mode Plus
;**
;** @value  Fast Mode Plus Configuration Options
;**
.EQU CONFIG_TWI0_FAST_MODE_PLUS = TWI_FAST_MODE_PLUS_DISABLED

;**
;** @brief  Read Interrupt Enable
;**
;** @value  Read Interrupt Enable Configuration Options
;**
.EQU CONFIG_TWI0_READ_INTERRUPT = TWI_READ_INTERRUPT_DISABLED

;**
;** @brief  Write Interrupt Enable
;**
;** @value  Write Interrupt Enable Configuration Options
;**
.EQU CONFIG_TWI0_WRITE_INTERRUPT = TWI_WRITE_INTERRUPT_DISABLED

;**
;** @brief  Quick Command Enable
;**
;** @value  Quick Command Enable Configuration Options
;**
.EQU CONFIG_TWI0_QUICK_COMMAND = TWI_QUICK_COMMAND_DISABLED

;**
;** @brief  Inactive Bus Time-Out
;**
;** @value  Inactive Bus Time-Out Configuration Options
;**
.EQU CONFIG_TWI0_BUS_TIMEOUT = TWI_BUS_TIMEOUT_DISABLED

;**
;** @brief  Smart Mode Enable
;**
;** @value  Smart Mode Enable Configuration Options
;**
.EQU CONFIG_TWI0_SMART_MODE = TWI_SMART_MODE_DISABLED

;**
;** @brief  Baud Rate
;**
;** @value  Baud Rate Configuration Options
;**
.EQU CONFIG_TWI0_BAUD_RATE = 100000
