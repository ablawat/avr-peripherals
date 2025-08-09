;***********************************************************************************************************************
;** Two-Wire Interface Peripheral Definitions                                                                         **
;***********************************************************************************************************************

.IFNDEF TWI_DEF
.SET    TWI_DEF = 1

; TWI Registers Offset
.EQU TWI_OFFSET = 32

;***********************************************************************************************************************
;** CTRLA - Control A - Definitions                                                                                   **
;***********************************************************************************************************************

; CTRLA - SDA Setup Time
.EQU TWI_CTRLA_SDASETUP_CYCLES_4 = 0
.EQU TWI_CTRLA_SDASETUP_CYCLES_8 = 1

; SDA Setup Time Configuration Options
.EQU TWI_SDA_SETUP_TIME_CYCLES_4 = (TWI_CTRLA_SDASETUP_CYCLES_4 << TWI_SDASETUP_bp)
.EQU TWI_SDA_SETUP_TIME_CYCLES_8 = (TWI_CTRLA_SDASETUP_CYCLES_8 << TWI_SDASETUP_bp)

; CTRLA - SDA Hold Time
.EQU TWI_CTRLA_SDAHOLD_OFF  = 0 ; hold time is off
.EQU TWI_CTRLA_SDAHOLD_50N  = 1 ; hold time 50 ns
.EQU TWI_CTRLA_SDAHOLD_300N = 2 ; hold time 300 ns
.EQU TWI_CTRLA_SDAHOLD_500N = 3 ; hold time 500 ns

; SDA Hold Time Configuration Options
.EQU TWI_SDA_HOLD_TIME_OFF  = (TWI_CTRLA_SDAHOLD_OFF  << TWI_SDAHOLD_gp)
.EQU TWI_SDA_HOLD_TIME_50N  = (TWI_CTRLA_SDAHOLD_50N  << TWI_SDAHOLD_gp)
.EQU TWI_SDA_HOLD_TIME_300N = (TWI_CTRLA_SDAHOLD_300N << TWI_SDAHOLD_gp)
.EQU TWI_SDA_HOLD_TIME_500N = (TWI_CTRLA_SDAHOLD_500N << TWI_SDAHOLD_gp)

; CTRLA - Fast Mode Plus Enable
.EQU TWI_CTRLA_FMPEN_OFF = 0
.EQU TWI_CTRLA_FMPEN_ON  = 1

; Fast Mode Plus Configuration Options
.EQU TWI_FAST_MODE_PLUS_DISABLED = (TWI_CTRLA_FMPEN_OFF << TWI_FMPEN_bp)
.EQU TWI_FAST_MODE_PLUS_ENABLED  = (TWI_CTRLA_FMPEN_ON  << TWI_FMPEN_bp)

;***********************************************************************************************************************
;** MCTRLA - Host Control A - Definitions                                                                             **
;***********************************************************************************************************************

; MCTRLA - Read Interrupt Enable
.EQU TWI_MCTRLA_RIEN_CLR = 0
.EQU TWI_MCTRLA_RIEN_SET = 1

; Read Interrupt Enable Configuration Options
.EQU TWI_READ_INTERRUPT_DISABLED = (TWI_MCTRLA_RIEN_CLR << TWI_RIEN_bp)
.EQU TWI_READ_INTERRUPT_ENABLED  = (TWI_MCTRLA_RIEN_SET << TWI_RIEN_bp)

; MCTRLA - Write Interrupt Enable
.EQU TWI_MCTRLA_WIEN_CLR = 0
.EQU TWI_MCTRLA_WIEN_SET = 1

; Write Interrupt Enable Configuration Options
.EQU TWI_WRITE_INTERRUPT_DISABLED = (TWI_MCTRLA_WIEN_CLR << TWI_WIEN_bp)
.EQU TWI_WRITE_INTERRUPT_ENABLED  = (TWI_MCTRLA_WIEN_SET << TWI_WIEN_bp)

; MCTRLA - Quick Command Enable
.EQU TWI_MCTRLA_QCEN_CLR = 0
.EQU TWI_MCTRLA_QCEN_SET = 1

; Quick Command Enable Configuration Options
.EQU TWI_QUICK_COMMAND_DISABLED = (TWI_MCTRLA_QCEN_CLR << TWI_QCEN_bp)
.EQU TWI_QUICK_COMMAND_ENABLED  = (TWI_MCTRLA_QCEN_SET << TWI_QCEN_bp)

; MCTRLA - Inactive Bus Time-Out
.EQU TWI_MCTRLA_TIMEOUT_OFF  = 0 ; bus time-out is disabled
.EQU TWI_MCTRLA_TIMEOUT_50U  = 1 ; bus time-out 50 us
.EQU TWI_MCTRLA_TIMEOUT_100U = 2 ; bus time-out 100 us
.EQU TWI_MCTRLA_TIMEOUT_200U = 3 ; bus time-out 200 us

; Inactive Bus Time-Out Configuration Options
.EQU TWI_BUS_TIMEOUT_DISABLED = (TWI_MCTRLA_TIMEOUT_OFF  << TWI_TIMEOUT_gp)
.EQU TWI_BUS_TIMEOUT_50U      = (TWI_MCTRLA_TIMEOUT_50U  << TWI_TIMEOUT_gp)
.EQU TWI_BUS_TIMEOUT_100U     = (TWI_MCTRLA_TIMEOUT_100U << TWI_TIMEOUT_gp)
.EQU TWI_BUS_TIMEOUT_200U     = (TWI_MCTRLA_TIMEOUT_200U << TWI_TIMEOUT_gp)

; MCTRLA - Smart Mode Enable
.EQU TWI_MCTRLA_SMEN_CLR = 0
.EQU TWI_MCTRLA_SMEN_SET = 1

; Smart Mode Enable Configuration Options
.EQU TWI_SMART_MODE_DISABLED = (TWI_MCTRLA_SMEN_CLR << TWI_SMEN_bp)
.EQU TWI_SMART_MODE_ENABLED  = (TWI_MCTRLA_SMEN_SET << TWI_SMEN_bp)

; MCTRLA - TWI Host Enable
.EQU TWI_MCTRLA_ENABLE_CLR = 0
.EQU TWI_MCTRLA_ENABLE_SET = 1

; TWI Host Enable Configuration Options
.EQU TWI_HOST_DISABLED = (TWI_MCTRLA_ENABLE_CLR << TWI_ENABLE_bp)
.EQU TWI_HOST_ENABLED  = (TWI_MCTRLA_ENABLE_SET << TWI_ENABLE_bp)

;***********************************************************************************************************************
;** MSTATUS - Host Status - Definitions                                                                               **
;***********************************************************************************************************************

; MSTATUS - Write Interrupt - Bit Number
.EQU TWI_WIF_BIT_NUMBER = TWI_WIF_bp

.EQU TWI_STATUS_WRITE_COMPLETED = (1 << TWI_WIF_BIT_NUMBER)

; MSTATUS - Read Interrupt - Bit Number
.EQU TWI_RIF_BIT_NUMBER = TWI_RIF_bp

.EQU TWI_STATUS_READ_COMPLETED = (1 << TWI_RIF_BIT_NUMBER)

; MSTATUS - Clock Hold - Bit Number
.EQU TWI_CLKHOLD_BIT_NUMBER = TWI_CLKHOLD_bp

.EQU TWI_STATUS_CLOCK_HELD = (1 << TWI_CLKHOLD_BIT_NUMBER)

; MSTATUS - Bus State - Group Position
.EQU TWI_BUS_STATE_BIT_MASK = ~TWI_BUSSTATE_gm

; MSTATUS - TWI Host Enable
.EQU TWI_MSTATUS_BUSSTATE_UNKNOWN = 0
.EQU TWI_MSTATUS_BUSSTATE_IDLE    = 1
.EQU TWI_MSTATUS_BUSSTATE_OWNER   = 2
.EQU TWI_MSTATUS_BUSSTATE_BUSY    = 3

.EQU TWI_STATUS_UNKNOWN = (TWI_MSTATUS_BUSSTATE_UNKNOWN << TWI_BUSSTATE_gp)
.EQU TWI_STATUS_IDLE    = (TWI_MSTATUS_BUSSTATE_IDLE    << TWI_BUSSTATE_gp)
.EQU TWI_STATUS_OWNER   = (TWI_MSTATUS_BUSSTATE_OWNER   << TWI_BUSSTATE_gp)
.EQU TWI_STATUS_BUSY    = (TWI_MSTATUS_BUSSTATE_BUSY    << TWI_BUSSTATE_gp)

.ENDIF
