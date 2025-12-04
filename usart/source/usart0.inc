;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "usart/config/usart0-config.inc"

;**********************************************************************************************;
; @section : Macro Definition                                                                  ;
;**********************************************************************************************;

#define GET_CONFIG_BYTE0(value) (LOW (LWRD(value)))
#define GET_CONFIG_BYTE1(value) (HIGH(LWRD(value)))
#define GET_CONFIG_BYTE2(value) (LOW (HWRD(value)))
#define GET_CONFIG_BYTE3(value) (HIGH(HWRD(value)))

;**********************************************************************************************;
; @section : Register Configuration                                                            ;
;**********************************************************************************************;

; CTRLA - Receive Complete Interrupt Enable
.EQU CONFIG_USART0_CTRLA_RXCIE = CONFIG_USART0_RX_COMPLETE_INTERRUPT

; CTRLA - Transmit Complete Interrupt Enable
.EQU CONFIG_USART0_CTRLA_TXCIE = CONFIG_USART0_TX_COMPLETE_INTERRUPT

; CTRLA - Data Register Empty Interrupt Enable
.EQU CONFIG_USART0_CTRLA_DREIE = CONFIG_USART0_DATA_REG_EMPTY_INTERRUPT

; CTRLA - Receiver Start Frame Interrupt Enable
.EQU CONFIG_USART0_CTRLA_RXSIE = CONFIG_USART0_RX_START_FRAME_INTERRUPT

; CTRLA - Loop-Back Mode Enable
.EQU CONFIG_USART0_CTRLA_LBME  = CONFIG_USART0_LOOP_BACK_MODE

; CTRLA - Auto-Baud Error Interrupt Enable
.EQU CONFIG_USART0_CTRLA_ABEIE = CONFIG_USART0_AUTO_BAUD_ERROR_INTERRUPT

; CTRLA - RS485 Mode
.EQU CONFIG_USART0_CTRLA_RS485 = USART_CTRLA_RS485_OFF

; @brief USART0 Control A Register
.EQU CONFIG_USART0_CTRLA = (CONFIG_USART0_CTRLA_RXCIE << USART_RXCIE_bp) | \
                           (CONFIG_USART0_CTRLA_TXCIE << USART_TXCIE_bp) | \
                           (CONFIG_USART0_CTRLA_DREIE << USART_DREIE_bp) | \
                           (CONFIG_USART0_CTRLA_RXSIE << USART_RXSIE_bp) | \
                           (CONFIG_USART0_CTRLA_LBME  << USART_LBME_bp ) | \
                           (CONFIG_USART0_CTRLA_ABEIE << USART_ABEIE_bp) | \
                           (CONFIG_USART0_CTRLA_RS485 << USART_RS485_gp)

; CTRLB - Receiver Enable
.EQU CONFIG_USART0_CTRLB_RXEN   = USART_CTRLB_RXEN_OFF

; CTRLB - Transmitter Enable
.EQU CONFIG_USART0_CTRLB_TXEN   = USART_CTRLB_TXEN_OFF

; CTRLB - Start Frame Detection Enable
.EQU CONFIG_USART0_CTRLB_SFDEN  = CONFIG_USART0_START_FRAME_DETECTION

; CTRLB - Open Drain Mode Enable
.EQU CONFIG_USART0_CTRLB_ODME   = CONFIG_USART0_OPEN_DRAIN_MODE

; CTRLB - Receiver Mode
.EQU CONFIG_USART0_CTRLB_RXMODE = CONFIG_USART0_SPEED_MODE

; CTRLB - Multi-Processor Communication Mode Enable
.EQU CONFIG_USART0_CTRLB_MPCM   = CONFIG_USART0_MULTI_PROC_COMM_MODE

; @brief USART0 Control B Register
.EQU CONFIG_USART0_CTRLB = (CONFIG_USART0_CTRLB_RXEN   << USART_RXEN_bp  ) | \
                           (CONFIG_USART0_CTRLB_TXEN   << USART_TXEN_bp  ) | \
                           (CONFIG_USART0_CTRLB_SFDEN  << USART_SFDEN_bp ) | \
                           (CONFIG_USART0_CTRLB_ODME   << USART_ODME_bp  ) | \
                           (CONFIG_USART0_CTRLB_RXMODE << USART_RXMODE_gp) | \
                           (CONFIG_USART0_CTRLB_MPCM   << USART_MPCM_bp  )

; CTRLC - Communication Mode
.EQU CONFIG_USART0_CTRLC_CMODE  = CONFIG_USART0_COMM_MODE
; CTRLC - Parity Mode
.EQU CONFIG_USART0_CTRLC_PMODE  = CONFIG_USART0_PARITY_MODE
; CTRLC - Stop Bit Mode
.EQU CONFIG_USART0_CTRLC_SBMODE = CONFIG_USART0_STOP_BIT_MODE
; CTRLC - Character Size
.EQU CONFIG_USART0_CTRLC_CHSIZE = CONFIG_USART0_CHARACTER_SIZE

; @brief USART0 Control C Register
.EQU CONFIG_USART0_CTRLC = (CONFIG_USART0_CTRLC_CMODE  << USART_CMODE_gp ) | \
                           (CONFIG_USART0_CTRLC_PMODE  << USART_PMODE_gp ) | \
                           (CONFIG_USART0_CTRLC_SBMODE << USART_SBMODE_bp) | \
                           (CONFIG_USART0_CTRLC_CHSIZE << USART_CHSIZE_gp)

; Define S
.IF   CONFIG_USART0_SPEED_MODE == USART_SPEED_MODE_NORMAL
.EQU S = 16
.ELIF CONFIG_USART0_SPEED_MODE == USART_SPEED_MODE_DOUBLE
.EQU S = 8
.ELSE
.EQU S = 2
.ENDIF

; @brief USART0 Baud Register
.EQU CONFIG_USART0_BAUD = (64 * PERIPHERAL_CLOCK_FREQUENCY) / (S * CONFIG_USART0_BAUD_RATE)

; @brief USART0 Enable
.EQU USART_RXTX_ENABLE = (USART_CTRLB_RXEN_ON << USART_RXEN_bp) | \
                         (USART_CTRLB_TXEN_ON << USART_TXEN_bp)
