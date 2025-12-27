.INCLUDE "twi/define/twi-define.inc"

;**
;** @brief  SDA Setup Time
;**
;** @value  TWI_SDA_SETUP_TIME_[OPTION]
;**
.EQU CONFIG_TWI0_SDA_SETUP_TIME = TWI_SDA_SETUP_TIME_CYCLES_4

;**
;** @brief  SDA Hold Time
;**
;** @value  TWI_SDA_HOLD_TIME_[OPTION]
;**
.EQU CONFIG_TWI0_SDA_HOLD_TIME = TWI_SDA_HOLD_TIME_50N

;**
;** @brief  Fast Mode Plus
;**
;** @value  TWI_FAST_MODE_PLUS_[OPTION]
;**
.EQU CONFIG_TWI0_FAST_MODE_PLUS = TWI_FAST_MODE_PLUS_DISABLED

;**
;** @brief  Read Interrupt Enable
;**
;** @value  TWI_READ_INTERRUPT_[OPTION]
;**
.EQU CONFIG_TWI0_READ_INTERRUPT = TWI_READ_INTERRUPT_DISABLED

;**
;** @brief  Write Interrupt Enable
;**
;** @value  TWI_WRITE_INTERRUPT_[OPTION]
;**
.EQU CONFIG_TWI0_WRITE_INTERRUPT = TWI_WRITE_INTERRUPT_DISABLED

;**
;** @brief  Quick Command Enable
;**
;** @value  TWI_QUICK_COMMAND_[OPTION]
;**
.EQU CONFIG_TWI0_QUICK_COMMAND = TWI_QUICK_COMMAND_DISABLED

;**
;** @brief  Inactive Bus Time-Out
;**
;** @value  TWI_BUS_TIMEOUT_[OPTION]
;**
.EQU CONFIG_TWI0_BUS_TIMEOUT = TWI_BUS_TIMEOUT_DISABLED

;**
;** @brief  Smart Mode Enable
;**
;** @value  TWI_SMART_MODE_[OPTION]
;**
.EQU CONFIG_TWI0_SMART_MODE = TWI_SMART_MODE_DISABLED

;**
;** @brief  Baud Rate
;**
;** @value  @MIN: 0, @MAX: 0, @Unit: bits per second [bps]
;**
.EQU CONFIG_TWI0_BAUD_RATE = 100000

;**
;** @brief  Bus Rise Time
;**
;** @value  @MIN: 0, @MAX: 0, @Unit: nanoseconds [ns]
;**
.EQU CONFIG_TWI0_BUS_RISE_TIME = 200
