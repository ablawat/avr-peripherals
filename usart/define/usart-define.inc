;******************************************************************************************************************************;
; @description : Universal Synchronous and Asynchronous Receiver and Transmitter Peripheral Definition                         ;
;******************************************************************************************************************************;

.IFNDEF USART_DEF
.SET    USART_DEF = 1

;******************************************************************************************************************************;
; @section : Include File                                                                                                      ;
;******************************************************************************************************************************;

.INCLUDE "usart/define/usart-register.inc"
.INCLUDE "macro/config.inc"

;******************************************************************************************************************************;
; @section : Configuration Option Definition                                                                                   ;
;******************************************************************************************************************************;

; @brief USART - Receive Complete Interrupt
.EQU USART_RX_COMPLETE_INTERRUPT_DISABLED = USART_CTRLA_RXCIE_OFF
.EQU USART_RX_COMPLETE_INTERRUPT_ENABLED  = USART_CTRLA_RXCIE_ON

; @brief USART - Transmit Complete Interrupt
.EQU USART_TX_COMPLETE_INTERRUPT_DISABLED = USART_CTRLA_TXCIE_OFF
.EQU USART_TX_COMPLETE_INTERRUPT_ENABLED  = USART_CTRLA_TXCIE_ON

; @brief USART - Data Register Empty Interrupt
.EQU USART_DATA_REG_EMPTY_INTERRUPT_DISABLED = USART_CTRLA_DREIE_OFF
.EQU USART_DATA_REG_EMPTY_INTERRUPT_ENABLED  = USART_CTRLA_DREIE_ON

; @brief USART - Receiver Start Frame Interrupt
.EQU USART_RX_START_FRAME_INTERRUPT_DISABLED = USART_CTRLA_RXSIE_OFF
.EQU USART_RX_START_FRAME_INTERRUPT_ENABLED  = USART_CTRLA_RXSIE_ON

; @brief USART - Loop-Back Mode
.EQU USART_LOOP_BACK_MODE_DISABLED = USART_CTRLA_LBME_OFF
.EQU USART_LOOP_BACK_MODE_ENABLED  = USART_CTRLA_LBME_ON

; @brief USART - Auto-Baud Error Interrupt
.EQU USART_AUTO_BAUD_ERROR_INTERRUPT_DISABLED = USART_CTRLA_ABEIE_OFF
.EQU USART_AUTO_BAUD_ERROR_INTERRUPT_ENABLED  = USART_CTRLA_ABEIE_ON

; @brief USART - Receiver Enable
.EQU USART_RX_DISABLED = USART_CTRLB_RXEN_OFF
.EQU USART_RX_ENABLED  = USART_CTRLB_RXEN_ON

; @brief USART - Transmitter Enable
.EQU USART_TX_DISABLED = USART_CTRLB_TXEN_OFF
.EQU USART_TX_ENABLED  = USART_CTRLB_TXEN_ON

; @brief USART - Start Frame Detection
.EQU USART_START_FRAME_DETECTION_DISABLED = USART_CTRLB_SFDEN_OFF
.EQU USART_START_FRAME_DETECTION_ENABLED  = USART_CTRLB_SFDEN_ON

; @brief USART - Open Drain Mode
.EQU USART_OPEN_DRAIN_MODE_DISABLED = USART_CTRLB_ODME_OFF
.EQU USART_OPEN_DRAIN_MODE_ENABLED  = USART_CTRLB_ODME_ON

; @brief USART - Receiver Mode
.EQU USART_SPEED_MODE_NORMAL        = USART_CTRLB_RXMODE_NORMAL
.EQU USART_SPEED_MODE_DOUBLE        = USART_CTRLB_RXMODE_CLK2X
.EQU USART_SPEED_MODE_AUTO_BAUD_GEN = USART_CTRLB_RXMODE_GENAUTO
.EQU USART_SPEED_MODE_AUTO_BAUD_LIN = USART_CTRLB_RXMODE_LINAUTO

; @brief USART - Multi-Processor Communication Mode
.EQU USART_MULTI_PROC_COMM_MODE_DISABLED = USART_CTRLB_MPCM_OFF
.EQU USART_MULTI_PROC_COMM_MODE_ENABLED  = USART_CTRLB_MPCM_ON

; @brief USART - Communication Mode
.EQU USART_COMM_MODE_ASYNCHRONOUS = USART_CTRLC_CMODE_ASYNC
.EQU USART_COMM_MODE_SYNCHRONOUS  = USART_CTRLC_CMODE_SYNC
.EQU USART_COMM_MODE_IR           = USART_CTRLC_CMODE_IR
.EQU USART_COMM_MODE_SPI          = USART_CTRLC_CMODE_SPI

; @brief USART - Parity Mode
.EQU USART_PARITY_MODE_NONE = USART_CTRLC_PMODE_NONE
.EQU USART_PARITY_MODE_EVEN = USART_CTRLC_PMODE_EVEN
.EQU USART_PARITY_MODE_ODD  = USART_CTRLC_PMODE_ODD

; @brief USART - Stop Bit Mode
.EQU USART_STOP_BIT_MODE_1BIT = USART_CTRLC_SBMODE_1BIT
.EQU USART_STOP_BIT_MODE_2BIT = USART_CTRLC_SBMODE_2BIT

; @brief USART - Character Size
.EQU USART_CHARACTER_SIZE_5BIT      = USART_CTRLC_CHSIZE_5BIT
.EQU USART_CHARACTER_SIZE_6BIT      = USART_CTRLC_CHSIZE_6BIT
.EQU USART_CHARACTER_SIZE_7BIT      = USART_CTRLC_CHSIZE_7BIT
.EQU USART_CHARACTER_SIZE_8BIT      = USART_CTRLC_CHSIZE_8BIT
.EQU USART_CHARACTER_SIZE_9BIT_LOW  = USART_CTRLC_CHSIZE_9BIT_LOW
.EQU USART_CHARACTER_SIZE_9BIT_HIGH = USART_CTRLC_CHSIZE_9BIT_HIGH

.ENDIF
