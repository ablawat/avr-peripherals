.INCLUDE "usart/usart-def.inc"

;**
;** @brief  Receive Complete Interrupt Enable
;**
;** @value  Receive Complete Interrupt Enable Configuration Options
;**
.EQU CONFIG_USART0_RX_COMPLETE_INTERRUPT = USART_RX_COMPLETE_INTERRUPT_DISABLED

;**
;** @brief  Transmit Complete Interrupt Enable
;**
;** @value  Transmit Complete Interrupt Enable Configuration Options
;**
.EQU CONFIG_USART0_TX_COMPLETE_INTERRUPT = USART_TX_COMPLETE_INTERRUPT_DISABLED

;**
;** @brief  Data Register Empty Interrupt Enable
;**
;** @value  Data Register Empty Interrupt Enable Configuration Options
;**
.EQU CONFIG_USART0_DATA_REG_EMPTY_INTERRUPT = USART_DATA_REG_EMPTY_INTERRUPT_DISABLED

;**
;** @brief  Receiver Start Frame Interrupt Enable
;**
;** @value  Receiver Start Frame Interrupt Enable Configuration Options
;**
.EQU CONFIG_USART0_RX_START_FRAME_INTERRUPT = USART_RX_START_FRAME_INTERRUPT_DISABLED

;**
;** @brief  Loop-Back Mode Enable
;**
;** @value  Loop-Back Mode Enable Configuration Options
;**
.EQU CONFIG_USART0_LOOP_BACK_MODE = USART_LOOP_BACK_MODE_DISABLED

;**
;** @brief  Auto-Baud Error Interrupt Enable
;**
;** @value  Auto-Baud Error Interrupt Enable Configuration Options
;**
.EQU CONFIG_USART0_AUTO_BAUD_ERROR_INTERRUPT = USART_AUTO_BAUD_ERROR_INTERRUPT_DISABLED

;**
;** @brief  Start Frame Detection Enable
;**
;** @value  Start Frame Detection Enable Configuration Options
;**
.EQU CONFIG_USART0_START_FRAME_DETECTION = USART_START_FRAME_DETECTION_DISABLED

;**
;** @brief  Open Drain Mode Enable
;**
;** @value  Open Drain Mode Enable Configuration Options
;**
.EQU CONFIG_USART0_OPEN_DRAIN_MODE = USART_OPEN_DRAIN_MODE_DISABLED

;**
;** @brief  Receiver Mode
;**
;** @value  Receiver Mode Configuration Options
;**
.EQU CONFIG_USART0_RX_MODE = USART_RX_MODE_SPEED_NORMAL

;**
;** @brief  Multi-Processor Communication Mode Enable
;**
;** @value  Multi-Processor Communication Mode Enable Configuration Options
;**
.EQU CONFIG_USART0_MULTI_PROC_COMM_MODE = USART_MULTI_PROC_COMM_MODE_DISABLED

;**
;** @brief  Communication Mode
;**
;** @value  Communication Mode Configuration Options
;**
.EQU CONFIG_USART0_COMM_MODE = USART_COMM_MODE_ASYNCHRONOUS

;**
;** @brief  Parity Mode
;**
;** @value  Parity Mode Configuration Options
;**
.EQU CONFIG_USART0_PARITY_MODE = USART_PARITY_MODE_NONE

;**
;** @brief  Stop Bit Mode
;**
;** @value  Stop Bit Mode Configuration Options
;**
.EQU CONFIG_USART0_STOP_BIT_MODE = USART_STOP_BIT_MODE_1BIT

;**
;** @brief  Character Size
;**
;** @value  Character Size Configuration Options
;**
.EQU CONFIG_USART0_CHARACTER_SIZE = USART_CHARACTER_SIZE_8BIT

;**
;** @brief  Baud Rate
;**
;** @value  Baud Rate Configuration Options
;**
.EQU CONFIG_USART0_BAUD_RATE = 9600
