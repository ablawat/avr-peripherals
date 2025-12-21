;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "usart/config/usart1-config.inc"

;**********************************************************************************************;
; @section : Register Configuration                                                            ;
;**********************************************************************************************;

; CTRLA - Receive Complete Interrupt Enable
.EQU CONFIG_USART1_CTRLA_RXCIE = CONFIG_USART1_RX_COMPLETE_INTERRUPT

; CTRLA - Transmit Complete Interrupt Enable
.EQU CONFIG_USART1_CTRLA_TXCIE = CONFIG_USART1_TX_COMPLETE_INTERRUPT

; CTRLA - Data Register Empty Interrupt Enable
.EQU CONFIG_USART1_CTRLA_DREIE = CONFIG_USART1_DATA_REG_EMPTY_INTERRUPT

; CTRLA - Receiver Start Frame Interrupt Enable
.EQU CONFIG_USART1_CTRLA_RXSIE = CONFIG_USART1_RX_START_FRAME_INTERRUPT

; CTRLA - Loop-Back Mode Enable
.EQU CONFIG_USART1_CTRLA_LBME  = CONFIG_USART1_LOOP_BACK_MODE

; CTRLA - Auto-Baud Error Interrupt Enable
.EQU CONFIG_USART1_CTRLA_ABEIE = CONFIG_USART1_AUTO_BAUD_ERROR_INTERRUPT

; CTRLA - RS485 Mode
.EQU CONFIG_USART1_CTRLA_RS485 = USART_CTRLA_RS485_OFF

; @brief Control A Register
.EQU CONFIG_USART1_CTRLA = (CONFIG_USART1_CTRLA_RXCIE << USART_RXCIE_bp) | \
                           (CONFIG_USART1_CTRLA_TXCIE << USART_TXCIE_bp) | \
                           (CONFIG_USART1_CTRLA_DREIE << USART_DREIE_bp) | \
                           (CONFIG_USART1_CTRLA_RXSIE << USART_RXSIE_bp) | \
                           (CONFIG_USART1_CTRLA_LBME  << USART_LBME_bp ) | \
                           (CONFIG_USART1_CTRLA_ABEIE << USART_ABEIE_bp) | \
                           (CONFIG_USART1_CTRLA_RS485 << USART_RS485_gp)

; CTRLB - Receiver Enable
.EQU CONFIG_USART1_CTRLB_RXEN   = USART_CTRLB_RXEN_OFF

; CTRLB - Transmitter Enable
.EQU CONFIG_USART1_CTRLB_TXEN   = USART_CTRLB_TXEN_OFF

; CTRLB - Start Frame Detection Enable
.EQU CONFIG_USART1_CTRLB_SFDEN  = CONFIG_USART1_START_FRAME_DETECTION

; CTRLB - Open Drain Mode Enable
.EQU CONFIG_USART1_CTRLB_ODME   = CONFIG_USART1_OPEN_DRAIN_MODE

; CTRLB - Receiver Mode
.EQU CONFIG_USART1_CTRLB_RXMODE = CONFIG_USART1_SPEED_MODE

; CTRLB - Multi-Processor Communication Mode Enable
.EQU CONFIG_USART1_CTRLB_MPCM   = CONFIG_USART1_MULTI_PROC_COMM_MODE

; @brief Control B Register
.EQU CONFIG_USART1_CTRLB = (CONFIG_USART1_CTRLB_RXEN   << USART_RXEN_bp  ) | \
                           (CONFIG_USART1_CTRLB_TXEN   << USART_TXEN_bp  ) | \
                           (CONFIG_USART1_CTRLB_SFDEN  << USART_SFDEN_bp ) | \
                           (CONFIG_USART1_CTRLB_ODME   << USART_ODME_bp  ) | \
                           (CONFIG_USART1_CTRLB_RXMODE << USART_RXMODE_gp) | \
                           (CONFIG_USART1_CTRLB_MPCM   << USART_MPCM_bp  )

; CTRLC - Communication Mode
.EQU CONFIG_USART1_CTRLC_CMODE  = CONFIG_USART1_COMM_MODE
; CTRLC - Parity Mode
.EQU CONFIG_USART1_CTRLC_PMODE  = CONFIG_USART1_PARITY_MODE
; CTRLC - Stop Bit Mode
.EQU CONFIG_USART1_CTRLC_SBMODE = CONFIG_USART1_STOP_BIT_MODE
; CTRLC - Character Size
.EQU CONFIG_USART1_CTRLC_CHSIZE = CONFIG_USART1_CHARACTER_SIZE

; @brief Control C Register
.EQU CONFIG_USART1_CTRLC = (CONFIG_USART1_CTRLC_CMODE  << USART_CMODE_gp ) | \
                           (CONFIG_USART1_CTRLC_PMODE  << USART_PMODE_gp ) | \
                           (CONFIG_USART1_CTRLC_SBMODE << USART_SBMODE_bp) | \
                           (CONFIG_USART1_CTRLC_CHSIZE << USART_CHSIZE_gp)

; Define S
.IF   CONFIG_USART1_SPEED_MODE == USART_SPEED_MODE_NORMAL
.EQU USART1_S = 16
.ELIF CONFIG_USART1_SPEED_MODE == USART_SPEED_MODE_DOUBLE
.EQU USART1_S = 8
.ELSE
.EQU USART1_S = 2
.ENDIF

; @brief Baud Register
.EQU CONFIG_USART1_BAUD = (64 * PERIPHERAL_CLOCK_FREQUENCY) / (USART1_S * CONFIG_USART1_BAUD_RATE)

; @brief Configuration Marker
.EQU USART1_CONFIG_DEFINE = 1
