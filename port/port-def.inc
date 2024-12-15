;***********************************************************************************************************************
;** Port Peripheral Definitions                                                                                       **
;***********************************************************************************************************************

.IFNDEF PORT_DEF
.SET    PORT_DEF = 1

; PORT Registers Offset
.EQU PORT_OFFSET = 32

;***********************************************************************************************************************
;** Port - Data Direction - Definitions                                                                               **
;***********************************************************************************************************************

; DIR - Pin Data Direction
.EQU PORT_DIR_CLR = 0
.EQU PORT_DIR_SET = 1

; Pin Data Direction Configuration Options
.EQU PORT_PIN_DATA_DIRECTION_INPUT  = PORT_DIR_CLR
.EQU PORT_PIN_DATA_DIRECTION_OUTPUT = PORT_DIR_SET

;***********************************************************************************************************************
;** Port - Output Value - Definitions                                                                                 **
;***********************************************************************************************************************

; OUT - Pin Output Value
.EQU PORT_OUT_CLR = 0
.EQU PORT_OUT_SET = 1

; Pin Output Value Configuration Options
.EQU PORT_PIN_OUTPUT_LEVEL_LOW  = PORT_OUT_CLR
.EQU PORT_PIN_OUTPUT_LEVEL_HIGH = PORT_OUT_SET

;***********************************************************************************************************************
;** Port - Pin Control - Definitions                                                                                  **
;***********************************************************************************************************************

; PINCTRL - Inverted I/O Enable
.EQU PORT_PINCTRL_INVEN_CLR = 0
.EQU PORT_PINCTRL_INVEN_SET = 1

; Inverted I/O Enable Configuration Options
.EQU PORT_PIN_POLARITY_INVERSION_DISABLED = (PORT_PINCTRL_INVEN_CLR << PORT_INVEN_bp)
.EQU PORT_PIN_POLARITY_INVERSION_ENABLED  = (PORT_PINCTRL_INVEN_SET << PORT_INVEN_bp)

; PINCTRL - Pull-Up Enable
.EQU PORT_PINCTRL_PULLUPEN_CLR = 0
.EQU PORT_PINCTRL_PULLUPEN_SET = 1

; Pull-Up Enable Configuration Options
.EQU PORT_PIN_PULLUP_DISABLED = (PORT_PINCTRL_PULLUPEN_CLR << PORT_PULLUPEN_bp)
.EQU PORT_PIN_PULLUP_ENABLED  = (PORT_PINCTRL_PULLUPEN_SET << PORT_PULLUPEN_bp)

; PINCTRL - Input/Sense Interrupt
.EQU PORT_PINCTRL_ISC_INTDISABLE    = 0 ; 
.EQU PORT_PINCTRL_ISC_BOTHEDGES     = 1 ; 
.EQU PORT_PINCTRL_ISC_RISING        = 2 ; 
.EQU PORT_PINCTRL_ISC_FALLING       = 3 ; 
.EQU PORT_PINCTRL_ISC_INPUT_DISABLE = 4 ; 
.EQU PORT_PINCTRL_ISC_LEVEL         = 5 ; 

; Input/Sense Interrupt Configuration Options
.EQU PORT_PIN_INPUT_BUFFER_DISABLED                       = (PORT_PINCTRL_ISC_INPUT_DISABLE << PORT_ISC_gp)
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_DISABLED     = (PORT_PINCTRL_ISC_INTDISABLE    << PORT_ISC_gp)
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_EDGE_BOTH    = (PORT_PINCTRL_ISC_BOTHEDGES     << PORT_ISC_gp)
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_EDGE_RISING  = (PORT_PINCTRL_ISC_RISING        << PORT_ISC_gp)
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_EDGE_FALLING = (PORT_PINCTRL_ISC_FALLING       << PORT_ISC_gp)
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_LEVEL_LOW    = (PORT_PINCTRL_ISC_LEVEL         << PORT_ISC_gp)

.ENDIF
