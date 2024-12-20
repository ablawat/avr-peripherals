;***************************************************************************************************
;**     Include Files                                                                             **
;***************************************************************************************************

.INCLUDE "usart/usart0-config.inc"

;***************************************************************************************************
;**     Constant Configuration Registers Definitions                                              **
;***************************************************************************************************

; @brief USART0 Control A Register
.EQU CONFIG_USART0_CTRLA = CONFIG_USART0_RX_COMPLETE_INTERRUPT     | \
                           CONFIG_USART0_TX_COMPLETE_INTERRUPT     | \
                           CONFIG_USART0_DATA_REG_EMPTY_INTERRUPT  | \
                           CONFIG_USART0_RX_START_FRAME_INTERRUPT  | \
                           CONFIG_USART0_LOOP_BACK_MODE            | \
                           CONFIG_USART0_AUTO_BAUD_ERROR_INTERRUPT

; @brief USART0 Control B Register
.EQU CONFIG_USART0_CTRLB = USART_RX_DISABLED | USART_TX_DISABLED | \
                           CONFIG_USART0_START_FRAME_DETECTION   | \
                           CONFIG_USART0_OPEN_DRAIN_MODE         | \
                           CONFIG_USART0_RX_MODE                 | \
                           CONFIG_USART0_MULTI_PROC_COMM_MODE

; @brief USART0 Control C Register
.EQU CONFIG_USART0_CTRLC = CONFIG_USART0_COMM_MODE      | \
                           CONFIG_USART0_PARITY_MODE    | \
                           CONFIG_USART0_STOP_BIT_MODE  | \
                           CONFIG_USART0_CHARACTER_SIZE

; Define S
.IF   CONFIG_USART0_RX_MODE == USART_RX_MODE_SPEED_NORMAL
.EQU S = 16
.ELIF CONFIG_USART0_RX_MODE == USART_RX_MODE_SPEED_DOUBLE
.EQU S = 8
.ELSE
.EQU S = 2
.ENDIF

; @brief USART0 Baud Register
.EQU CONFIG_USART0_BAUD = (64 * PERIPHERAL_CLOCK_FREQUENCY) / (S * CONFIG_USART0_BAUD_RATE)
