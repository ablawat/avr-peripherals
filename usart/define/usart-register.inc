;**********************************************************************************************;
; @description : Universal Synchronous and Asynchronous Receiver and Transmitter Peripheral    ;
;**********************************************************************************************;

.IFNDEF USART_REG
.SET    USART_REG = 1

; USART Registers Offset
.EQU USART_OFFSET = 32

;**********************************************************************************************;
; @section : CTRLA - Control A                                                                 ;
;**********************************************************************************************;

; CTRLA - Receive Complete Interrupt Enable
.EQU USART_CTRLA_RXCIE_OFF = 0
.EQU USART_CTRLA_RXCIE_ON  = 1

; CTRLA - Transmit Complete Interrupt Enable
.EQU USART_CTRLA_TXCIE_OFF = 0
.EQU USART_CTRLA_TXCIE_ON  = 1

; CTRLA - Data Register Empty Interrupt Enable
.EQU USART_CTRLA_DREIE_OFF = 0
.EQU USART_CTRLA_DREIE_ON  = 1

; CTRLA - Receiver Start Frame Interrupt Enable
.EQU USART_CTRLA_RXSIE_OFF = 0
.EQU USART_CTRLA_RXSIE_ON  = 1

; CTRLA - Loop-Back Mode Enable
.EQU USART_CTRLA_LBME_OFF = 0
.EQU USART_CTRLA_LBME_ON  = 1

; CTRLA - Auto-Baud Error Interrupt Enable
.EQU USART_CTRLA_ABEIE_OFF = 0
.EQU USART_CTRLA_ABEIE_ON  = 1

; CTRLA - RS485 Mode
.equ USART_CTRLA_RS485_OFF      = 0 ; disabled
.equ USART_CTRLA_RS485_XDIR     = 1 ; enabled with XDIR
.equ USART_CTRLA_RS485_TXD      = 2 ; enabled with TXD
.equ USART_CTRLA_RS485_XDIR_TXD = 3 ; enabled with XDIR and TXD

;**********************************************************************************************;
; @section : CTRLB - Control B                                                                 ;
;**********************************************************************************************;

; CTRLB - Receiver Enable
.EQU USART_CTRLB_RXEN_OFF = 0
.EQU USART_CTRLB_RXEN_ON  = 1

; CTRLB - Transmitter Enable
.EQU USART_CTRLB_TXEN_OFF = 0
.EQU USART_CTRLB_TXEN_ON  = 1

; CTRLB - Start Frame Detection Enable
.EQU USART_CTRLB_SFDEN_OFF = 0
.EQU USART_CTRLB_SFDEN_ON  = 1

; CTRLB - Open Drain Mode Enable
.EQU USART_CTRLB_ODME_OFF = 0
.EQU USART_CTRLB_ODME_ON  = 1

; CTRLB - Receiver Mode
.EQU USART_CTRLB_RXMODE_NORMAL  = 0 ; normal speed
.EQU USART_CTRLB_RXMODE_CLK2X   = 1 ; double speed
.EQU USART_CTRLB_RXMODE_GENAUTO = 2 ; generic auto-baud
.EQU USART_CTRLB_RXMODE_LINAUTO = 3 ; LIN constrained auto-baud

; CTRLB - Multi-Processor Communication Mode Enable
.EQU USART_CTRLB_MPCM_OFF = 0
.EQU USART_CTRLB_MPCM_ON  = 1

;**********************************************************************************************;
; @section : CTRLC - Control C                                                                 ;
;**********************************************************************************************;

; CTRLC - Communication Mode
.EQU USART_CTRLC_CMODE_ASYNC = 0    ; USART asynchronous
.EQU USART_CTRLC_CMODE_SYNC  = 1    ; USART synchronous
.EQU USART_CTRLC_CMODE_IR    = 2    ; infrared communication
.EQU USART_CTRLC_CMODE_SPI   = 3    ; SPI host

; CTRLC - Parity Mode
.EQU USART_CTRLC_PMODE_NONE = 0     ; disabled
.EQU USART_CTRLC_PMODE_EVEN = 2     ; parity even
.EQU USART_CTRLC_PMODE_ODD  = 3     ; parity odd

; CTRLC - Stop Bit Mode
.EQU USART_CTRLC_SBMODE_1BIT = 0    ; one stop bit
.EQU USART_CTRLC_SBMODE_2BIT = 1    ; two stop bits

; CTRLC - Character Size
.EQU USART_CTRLC_CHSIZE_5BIT      = 0   ; 5-bit
.EQU USART_CTRLC_CHSIZE_6BIT      = 1   ; 6-bit
.EQU USART_CTRLC_CHSIZE_7BIT      = 2   ; 7-bit
.EQU USART_CTRLC_CHSIZE_8BIT      = 3   ; 8-bit
.EQU USART_CTRLC_CHSIZE_9BIT_LOW  = 6   ; 9-bit first byte low
.EQU USART_CTRLC_CHSIZE_9BIT_HIGH = 7   ; 9-bit first byte high

;**********************************************************************************************;
; @section : STATUS - Status                                                                   ;
;**********************************************************************************************;

; STATUS - Receive Complete Interrupt Flag - Bit Position
.EQU USART_RXCIF_BPOS = USART_RXCIF_bp

; STATUS - Transmit Complete Interrupt Flag - Bit Position
.EQU USART_TXCIF_BPOS = USART_TXCIF_bp

; STATUS - Data Register Empty Interrupt Flag - Bit Position
.EQU USART_DREIF_BPOS = USART_DREIF_bp

.ENDIF
