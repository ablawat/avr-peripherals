;**********************************************************************************************;
; @description : Input and Output Pin Configuration Peripheral Definition                      ;
;**********************************************************************************************;

.IFNDEF PORT_DEFINE
.SET    PORT_DEFINE = 1

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "port/define/port-register.inc"

.INCLUDE "macro/registers.inc"
.INCLUDE "macro/config.inc"

;**********************************************************************************************;
; @section : Configuration Option Definition                                                   ;
;**********************************************************************************************;

; @brief PORT - Pin Data Direction
.EQU PORT_PIN_DATA_DIRECTION_INPUT  = PORT_DIR_IN
.EQU PORT_PIN_DATA_DIRECTION_OUTPUT = PORT_DIR_OUT

; @brief PORT - Pin Output Level
.EQU PORT_PIN_OUTPUT_LEVEL_LOW  = PORT_OUT_LOW
.EQU PORT_PIN_OUTPUT_LEVEL_HIGH = PORT_OUT_HIGH

; @brief PORT - Pin Polarity Inversion
.EQU PORT_PIN_POLARITY_INVERSION_DISABLED = PORT_PINCTRL_INVEN_OFF
.EQU PORT_PIN_POLARITY_INVERSION_ENABLED  = PORT_PINCTRL_INVEN_ON

; @brief PORT - Pin Pull-Up
.EQU PORT_PIN_PULLUP_DISABLED = PORT_PINCTRL_PULLUPEN_OFF
.EQU PORT_PIN_PULLUP_ENABLED  = PORT_PINCTRL_PULLUPEN_ON

; @brief PORT - Pin Input/Sense Interrupt
.EQU PORT_PIN_INPUT_BUFFER_DISABLED                       = PORT_PINCTRL_ISC_INPUT_DISABLE
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_DISABLED     = PORT_PINCTRL_ISC_INTDISABLE
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_EDGE_BOTH    = PORT_PINCTRL_ISC_BOTHEDGES
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_EDGE_RISING  = PORT_PINCTRL_ISC_RISING
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_EDGE_FALLING = PORT_PINCTRL_ISC_FALLING
.EQU PORT_PIN_INPUT_BUFFER_ENABLED_INTERRUPT_LEVEL_LOW    = PORT_PINCTRL_ISC_LEVEL

; Interrupt Service Routine
.EQU PORT_ISR_NONE = 0

.ENDIF
