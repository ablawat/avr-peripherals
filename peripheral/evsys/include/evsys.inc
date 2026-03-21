;**********************************************************************************************;
; @description : Event System Header                                                           ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "peripheral/evsys/config/evsys-config.inc"

;**********************************************************************************************;
; @section : Register Configuration                                                            ;
;**********************************************************************************************;

; @brief Asynchronous Channel 0 Generator Selection Register
.EQU CONFIG_EVSYS_ASYNCCH0 = CONFIG_EVSYS_ASYNC_CHANNEL0_GENERATOR

; @brief Asynchronous Channel 1 Generator Selection Register
.EQU CONFIG_EVSYS_ASYNCCH1 = CONFIG_EVSYS_ASYNC_CHANNEL1_GENERATOR

; @brief Asynchronous User Channel 0 Input Selection Register
.EQU CONFIG_EVSYS_ASYNCUSER0 = CONFIG_EVSYS_TCB0_INPUT

; @brief Asynchronous User Channel 1 Input Selection Register
.EQU CONFIG_EVSYS_ASYNCUSER1 = CONFIG_EVSYS_ADC0_INPUT
