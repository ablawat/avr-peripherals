;**********************************************************************************************;
; @description : Event System Peripheral                                                       ;
;**********************************************************************************************;

.IFNDEF EVSYS_REGISTER
.SET    EVSYS_REGISTER = 1

;**********************************************************************************************;
; @section : ASYNCCH - Asynchronous Channel Generator Selection                                ;
;**********************************************************************************************;

; ASYNCCH - Asynchronous Channel Generator Selection
.EQU EVSYS_ASYNCCH_OFF          = 0 ; none
.EQU EVSYS_ASYNCCH_CCL_LUT0     = 1 ; configurable custom logic look-up table 0
.EQU EVSYS_ASYNCCH_CCL_LUT1     = 2 ; configurable custom logic look-up table 1
.EQU EVSYS_ASYNCCH_AC0_OUT      = 3 ; analog comparator 0 output
.EQU EVSYS_ASYNCCH_TCD0_CMPBCLR = 4 ; timer/counter type D 0 CMPBCLR match
.EQU EVSYS_ASYNCCH_TCD0_CMPASET = 5 ; timer/counter type D 0 CMPASET match
.EQU EVSYS_ASYNCCH_TCD0_CMPBSET = 6 ; timer/counter type D 0 CMPBSET match
.EQU EVSYS_ASYNCCH_TCD0_PROGEV  = 7 ; timer/counter type D 0 programmable output
.EQU EVSYS_ASYNCCH_RTC_OVF      = 8 ; real-time counter overflow
.EQU EVSYS_ASYNCCH_RTC_CMP      = 9 ; real-time counter compare

.EQU EVSYS_ASYNCCH_UPDI = 18 ; unified program and debug interface

.EQU EVSYS_ASYNCCH_PORTA_PIN0 = 10 ; PORTA pin 0
.EQU EVSYS_ASYNCCH_PORTA_PIN1 = 11 ; PORTA pin 1
.EQU EVSYS_ASYNCCH_PORTA_PIN2 = 12 ; PORTA pin 2
.EQU EVSYS_ASYNCCH_PORTA_PIN3 = 13 ; PORTA pin 3
.EQU EVSYS_ASYNCCH_PORTA_PIN4 = 14 ; PORTA pin 4
.EQU EVSYS_ASYNCCH_PORTA_PIN5 = 15 ; PORTA pin 5
.EQU EVSYS_ASYNCCH_PORTA_PIN6 = 16 ; PORTA pin 6
.EQU EVSYS_ASYNCCH_PORTA_PIN7 = 17 ; PORTA pin 7

.EQU EVSYS_ASYNCCH_PORTB_PIN0 = 10 ; PORTB pin 0
.EQU EVSYS_ASYNCCH_PORTB_PIN1 = 11 ; PORTB pin 1
.EQU EVSYS_ASYNCCH_PORTB_PIN2 = 12 ; PORTB pin 2
.EQU EVSYS_ASYNCCH_PORTB_PIN3 = 13 ; PORTB pin 3
.EQU EVSYS_ASYNCCH_PORTB_PIN4 = 14 ; PORTB pin 4
.EQU EVSYS_ASYNCCH_PORTB_PIN5 = 15 ; PORTB pin 5
.EQU EVSYS_ASYNCCH_PORTB_PIN6 = 16 ; PORTB pin 6
.EQU EVSYS_ASYNCCH_PORTB_PIN7 = 17 ; PORTB pin 7

.EQU EVSYS_ASYNCCH_PORTC_PIN0 = 10 ; PORTC pin 0
.EQU EVSYS_ASYNCCH_PORTC_PIN1 = 11 ; PORTC pin 1
.EQU EVSYS_ASYNCCH_PORTC_PIN2 = 12 ; PORTC pin 2
.EQU EVSYS_ASYNCCH_PORTC_PIN3 = 13 ; PORTC pin 3
.EQU EVSYS_ASYNCCH_PORTC_PIN4 = 14 ; PORTC pin 4
.EQU EVSYS_ASYNCCH_PORTC_PIN5 = 15 ; PORTC pin 5

.EQU EVSYS_ASYNCCH_PIT_DIV_8192 = 10 ; periodic interrupt divided by 8192
.EQU EVSYS_ASYNCCH_PIT_DIV_4096 = 11 ; periodic interrupt divided by 4096
.EQU EVSYS_ASYNCCH_PIT_DIV_2048 = 12 ; periodic interrupt divided by 2048
.EQU EVSYS_ASYNCCH_PIT_DIV_1024 = 13 ; periodic interrupt divided by 1024
.EQU EVSYS_ASYNCCH_PIT_DIV_512  = 14 ; periodic interrupt divided by 512
.EQU EVSYS_ASYNCCH_PIT_DIV_256  = 15 ; periodic interrupt divided by 256
.EQU EVSYS_ASYNCCH_PIT_DIV_128  = 16 ; periodic interrupt divided by 128
.EQU EVSYS_ASYNCCH_PIT_DIV_64   = 17 ; periodic interrupt divided by 64

;**********************************************************************************************;
; @section : ASYNCUSER - Asynchronous User Input Selection                                     ;
;**********************************************************************************************;

; ASYNCUSER - Asynchronous User Channel Input Selection
.EQU EVSYS_ASYNCUSER_OFF      = 0   ; none
.EQU EVSYS_ASYNCUSER_SYNCCH0  = 1   ; synchronous channel 0
.EQU EVSYS_ASYNCUSER_SYNCCH1  = 2   ; synchronous channel 1
.EQU EVSYS_ASYNCUSER_ASYNCCH0 = 3   ; asynchronous channel 0
.EQU EVSYS_ASYNCUSER_ASYNCCH1 = 4   ; asynchronous channel 1
.EQU EVSYS_ASYNCUSER_ASYNCCH2 = 5   ; asynchronous channel 2
.EQU EVSYS_ASYNCUSER_ASYNCCH3 = 6   ; asynchronous channel 3

.ENDIF
