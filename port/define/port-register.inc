;**********************************************************************************************;
; @description : Input and Output Pin Configuration Peripheral                                 ;
;**********************************************************************************************;

.IFNDEF PORT_REGISTER
.SET    PORT_REGISTER = 1

; PORT Registers Offset
.EQU PORT_OFFSET = 32

;**********************************************************************************************;
; @section : DIR - Data Direction                                                              ;
;**********************************************************************************************;

; DIR - Data Direction
.EQU PORT_DIR_IN  = 0 ; 
.EQU PORT_DIR_OUT = 1 ; 

;**********************************************************************************************;
; @section : OUT - Output Value                                                                ;
;**********************************************************************************************;

; OUT - Output Value
.EQU PORT_OUT_LOW  = 0 ; 
.EQU PORT_OUT_HIGH = 1 ; 

;**********************************************************************************************;
; @section : PINCTRL - Pin Control                                                             ;
;**********************************************************************************************;

; PINCTRL - Polarity Inversion Enable
.EQU PORT_PINCTRL_INVEN_OFF = 0
.EQU PORT_PINCTRL_INVEN_ON  = 1

; PINCTRL - Pull-Up Enable
.EQU PORT_PINCTRL_PULLUPEN_OFF = 0
.EQU PORT_PINCTRL_PULLUPEN_ON  = 1

; PINCTRL - Input/Sense Interrupt
.EQU PORT_PINCTRL_ISC_INTDISABLE    = 0 ; 
.EQU PORT_PINCTRL_ISC_BOTHEDGES     = 1 ; 
.EQU PORT_PINCTRL_ISC_RISING        = 2 ; 
.EQU PORT_PINCTRL_ISC_FALLING       = 3 ; 
.EQU PORT_PINCTRL_ISC_INPUT_DISABLE = 4 ; 
.EQU PORT_PINCTRL_ISC_LEVEL         = 5 ; 

.ENDIF
