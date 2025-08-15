;***********************************************************************************************************************
;** Universal Synchronous and Asynchronous Receiver and Transmitter Peripheral Definitions                            **
;***********************************************************************************************************************

.IFNDEF USART_DEF
.SET    USART_DEF = 1

; USART Registers Offset
.EQU USART_OFFSET = 32

;***********************************************************************************************************************
;** USART - Control A - Definitions                                                                                   **
;***********************************************************************************************************************

; CTRLA - Receive Complete Interrupt Enable
.EQU USART_CTRLA_RXCIE_CLR = 0
.EQU USART_CTRLA_RXCIE_SET = 1

; Receive Complete Interrupt Enable Configuration Options
.EQU USART_RX_COMPLETE_INTERRUPT_DISABLED = (USART_CTRLA_RXCIE_CLR << USART_RXCIE_bp)
.EQU USART_RX_COMPLETE_INTERRUPT_ENABLED  = (USART_CTRLA_RXCIE_SET << USART_RXCIE_bp)

; CTRLA - Transmit Complete Interrupt Enable
.EQU USART_CTRLA_TXCIE_CLR = 0
.EQU USART_CTRLA_TXCIE_SET = 1

; Transmit Complete Interrupt Enable Configuration Options
.EQU USART_TX_COMPLETE_INTERRUPT_DISABLED = (USART_CTRLA_TXCIE_CLR << USART_TXCIE_bp)
.EQU USART_TX_COMPLETE_INTERRUPT_ENABLED  = (USART_CTRLA_TXCIE_SET << USART_TXCIE_bp)

; CTRLA - Data Register Empty Interrupt Enable
.EQU USART_CTRLA_DREIE_CLR = 0
.EQU USART_CTRLA_DREIE_SET = 1

; Data Register Empty Interrupt Enable Configuration Options
.EQU USART_DATA_REG_EMPTY_INTERRUPT_DISABLED = (USART_CTRLA_DREIE_CLR << USART_DREIE_bp)
.EQU USART_DATA_REG_EMPTY_INTERRUPT_ENABLED  = (USART_CTRLA_DREIE_SET << USART_DREIE_bp)

; CTRLA - Receiver Start Frame Interrupt Enable
.EQU USART_CTRLA_RXSIE_CLR = 0
.EQU USART_CTRLA_RXSIE_SET = 1

; Receiver Start Frame Interrupt Enable Configuration Options
.EQU USART_RX_START_FRAME_INTERRUPT_DISABLED = (USART_CTRLA_RXSIE_CLR << USART_RXSIE_bp)
.EQU USART_RX_START_FRAME_INTERRUPT_ENABLED  = (USART_CTRLA_RXSIE_SET << USART_RXSIE_bp)

; CTRLA - Loop-Back Mode Enable
.EQU USART_CTRLA_LBME_CLR = 0
.EQU USART_CTRLA_LBME_SET = 1

; Loop-Back Mode Enable Configuration Options
.EQU USART_LOOP_BACK_MODE_DISABLED = (USART_CTRLA_LBME_CLR << USART_LBME_bp)
.EQU USART_LOOP_BACK_MODE_ENABLED  = (USART_CTRLA_LBME_SET << USART_LBME_bp)

; CTRLA - Auto-Baud Error Interrupt Enable
.EQU USART_CTRLA_ABEIE_CLR = 0
.EQU USART_CTRLA_ABEIE_SET = 1

; Auto-Baud Error Interrupt Enable Configuration Options
.EQU USART_AUTO_BAUD_ERROR_INTERRUPT_DISABLED = (USART_CTRLA_ABEIE_CLR << USART_ABEIE_bp)
.EQU USART_AUTO_BAUD_ERROR_INTERRUPT_ENABLED  = (USART_CTRLA_ABEIE_SET << USART_ABEIE_bp)

; CTRLA - RS485 Mode [TBD]
.equ USART_RS485_XDIR_A = 0 ; 
.equ USART_RS485_XDIR_B = 1 ; 
.equ USART_RS485_TXD_A  = 2 ; 
.equ USART_RS485_TXD_B  = 3 ; 

;
;
;
;

;***********************************************************************************************************************
;** USART - Control B - Definitions                                                                                   **
;***********************************************************************************************************************

; CTRLB - Receiver Enable
.EQU USART_CTRLB_RXEN_CLR = 0
.EQU USART_CTRLB_RXEN_SET = 1

; Receiver Enable Configuration Options
.EQU USART_RX_DISABLED = (USART_CTRLB_RXEN_CLR << USART_RXEN_bp)
.EQU USART_RX_ENABLED  = (USART_CTRLB_RXEN_SET << USART_RXEN_bp)

; CTRLB - Transmitter Enable
.EQU USART_CTRLB_TXEN_CLR = 0
.EQU USART_CTRLB_TXEN_SET = 1

; Transmitter Enable Configuration Options
.EQU USART_TX_DISABLED = (USART_CTRLB_TXEN_CLR << USART_TXEN_bp)
.EQU USART_TX_ENABLED  = (USART_CTRLB_TXEN_SET << USART_TXEN_bp)

; CTRLB - Start Frame Detection Enable
.EQU USART_CTRLB_SFDEN_CLR = 0
.EQU USART_CTRLB_SFDEN_SET = 1

; Start-of-Frame Detection Enable Configuration Options
.EQU USART_START_FRAME_DETECTION_DISABLED = (USART_CTRLB_SFDEN_CLR << USART_SFDEN_bp)
.EQU USART_START_FRAME_DETECTION_ENABLED  = (USART_CTRLB_SFDEN_SET << USART_SFDEN_bp)

; CTRLB - Open Drain Mode Enable
.EQU USART_CTRLB_ODME_CLR = 0
.EQU USART_CTRLB_ODME_SET = 1

; Open Drain Mode Enable Configuration Options
.EQU USART_OPEN_DRAIN_MODE_DISABLED = (USART_CTRLB_ODME_CLR << USART_ODME_bp)
.EQU USART_OPEN_DRAIN_MODE_ENABLED  = (USART_CTRLB_ODME_SET << USART_ODME_bp)

; CTRLB - Receiver Mode
.EQU USART_CTRLB_RX_MODE_NORMAL  = 0 ; 
.EQU USART_CTRLB_RX_MODE_CLK2X   = 1 ; 
.EQU USART_CTRLB_RX_MODE_GENAUTO = 2 ; 
.EQU USART_CTRLB_RX_MODE_LINAUTO = 3 ; 

; Receiver Mode Configuration Options
.EQU USART_RX_MODE_SPEED_NORMAL  = (USART_CTRLB_RX_MODE_NORMAL  << USART_RXMODE_gp)
.EQU USART_RX_MODE_SPEED_DOUBLE  = (USART_CTRLB_RX_MODE_CLK2X   << USART_RXMODE_gp)
.EQU USART_RX_MODE_AUTO_BAUD_GEN = (USART_CTRLB_RX_MODE_GENAUTO << USART_RXMODE_gp)
.EQU USART_RX_MODE_AUTO_BAUD_LIN = (USART_CTRLB_RX_MODE_LINAUTO << USART_RXMODE_gp)

; CTRLB - Multi-Processor Communication Mode Enable
.EQU USART_CTRLB_MPCM_CLR = 0
.EQU USART_CTRLB_MPCM_SET = 1

; Multi-Processor Communication Mode Configuration Options
.EQU USART_MULTI_PROC_COMM_MODE_DISABLED = (USART_CTRLB_MPCM_CLR << USART_MPCM_bp)
.EQU USART_MULTI_PROC_COMM_MODE_ENABLED  = (USART_CTRLB_MPCM_SET << USART_MPCM_bp)

;***********************************************************************************************************************
;** USART - Control C - Definitions                                                                                   **
;***********************************************************************************************************************

; CTRLC - Communication Mode
.EQU USART_CTRLC_CMODE_ASYNC = 0 ; 
.EQU USART_CTRLC_CMODE_SYNC  = 1 ; 
.EQU USART_CTRLC_CMODE_IR    = 2 ; 
.EQU USART_CTRLC_CMODE_SPI   = 3 ; 

; Communication Mode Configuration Options
.EQU USART_COMM_MODE_ASYNCHRONOUS = (USART_CTRLC_CMODE_ASYNC << USART_CMODE_gp)
.EQU USART_COMM_MODE_SYNCHRONOUS  = (USART_CTRLC_CMODE_SYNC  << USART_CMODE_gp)
.EQU USART_COMM_MODE_IR           = (USART_CTRLC_CMODE_IR    << USART_CMODE_gp)
.EQU USART_COMM_MODE_SPI          = (USART_CTRLC_CMODE_SPI   << USART_CMODE_gp)

; CTRLC - Parity Mode
.EQU USART_CTRLC_PMODE_NONE = 0 ; 
.EQU USART_CTRLC_PMODE_EVEN = 2 ; 
.EQU USART_CTRLC_PMODE_ODD  = 3 ; 

; Parity Mode Configuration Options
.EQU USART_PARITY_MODE_NONE = (USART_CTRLC_PMODE_NONE << USART_PMODE_gp)
.EQU USART_PARITY_MODE_EVEN = (USART_CTRLC_PMODE_EVEN << USART_PMODE_gp)
.EQU USART_PARITY_MODE_ODD  = (USART_CTRLC_PMODE_ODD  << USART_PMODE_gp)

; CTRLC - Stop Bit Mode
.EQU USART_CTRLC_SBMODE_1BIT = 0 ; 
.EQU USART_CTRLC_SBMODE_2BIT = 1 ; 

; Stop Bit Mode Configuration Options
.EQU USART_STOP_BIT_MODE_1BIT = (USART_CTRLC_SBMODE_1BIT << USART_SBMODE_bp)
.EQU USART_STOP_BIT_MODE_2BIT = (USART_CTRLC_SBMODE_2BIT << USART_SBMODE_bp)

; CTRLC - Character Size
.EQU USART_CTRLC_CHSIZE_5BIT      = 0 ; 
.EQU USART_CTRLC_CHSIZE_6BIT      = 1 ; 
.EQU USART_CTRLC_CHSIZE_7BIT      = 2 ; 
.EQU USART_CTRLC_CHSIZE_8BIT      = 3 ; 
.EQU USART_CTRLC_CHSIZE_9BIT_LOW  = 6 ; 
.EQU USART_CTRLC_CHSIZE_9BIT_HIGH = 7 ; 

; Character Size Configuration Options
.EQU USART_CHARACTER_SIZE_5BIT      = (USART_CTRLC_CHSIZE_5BIT      << USART_CHSIZE_gp)
.EQU USART_CHARACTER_SIZE_6BIT      = (USART_CTRLC_CHSIZE_6BIT      << USART_CHSIZE_gp)
.EQU USART_CHARACTER_SIZE_7BIT      = (USART_CTRLC_CHSIZE_7BIT      << USART_CHSIZE_gp)
.EQU USART_CHARACTER_SIZE_8BIT      = (USART_CTRLC_CHSIZE_8BIT      << USART_CHSIZE_gp)
.EQU USART_CHARACTER_SIZE_9BIT_LOW  = (USART_CTRLC_CHSIZE_9BIT_LOW  << USART_CHSIZE_gp)
.EQU USART_CHARACTER_SIZE_9BIT_HIGH = (USART_CTRLC_CHSIZE_9BIT_HIGH << USART_CHSIZE_gp)

;***********************************************************************************************************************
;** USART - Status - Definitions                                                                                      **
;***********************************************************************************************************************

; STATUS - Receive Complete Interrupt Flag - Bit Number
.EQU USART_RXCIF_BIT_NUMBER = USART_RXCIF_bp

.EQU USART_STATUS_RECEIVE_COMPLETED = (1 << USART_RXCIF_BIT_NUMBER)

; STATUS - Transmit Complete Interrupt Flag - Bit Number
.EQU USART_TXCIF_BIT_NUMBER = USART_TXCIF_bp

.EQU USART_STATUS_TRANSMIT_COMPLETED = (1 << USART_TXCIF_BIT_NUMBER)

; STATUS - Data Register Empty Interrupt Flag - Bit Number
.EQU USART_DREIF_BIT_NUMBER = USART_DREIF_bp

.EQU USART_STATUS_DATA_EMPTY = (1 << USART_DREIF_BIT_NUMBER)

.ENDIF
