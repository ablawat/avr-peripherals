;**********************************************************************************************;
; @description : Event System Source                                                           ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Code [FLASH]                                                                      ;
;**********************************************************************************************;

.CSEG

;**********************************************************************************************;
; @brief    : Initializes Event System Peripheral
;
; @input    : none
; @output   : none
;
; @use      : XH:XL, TEMPL
;**********************************************************************************************;
evsys_init: ; get EVSYS base address
            ldi     XH, HIGH (EVSYS_base + 2)
            ldi     XL, LOW  (EVSYS_base + 2)

            ; configure register Asynchronous Channel 0 Generator Selection
            ldi     TEMPL, CONFIG_EVSYS_ASYNCCH0    ; get config constant
            st      X+, TEMPL                       ; write into register

            ; configure register Asynchronous Channel 1 Generator Selection
            ldi     TEMPL, CONFIG_EVSYS_ASYNCCH1    ; get config constant
            st      X+, TEMPL                       ; write into register

            ; go to asynchronous user channels
            adiw    XL, 14                          ; move pointer forward

            ; configure register Asynchronous User Channel 0 Input Selection
            ldi     TEMPL, CONFIG_EVSYS_ASYNCUSER0  ; get config constant
            st      X+, TEMPL                       ; write into register

            ; configure register Asynchronous User Channel 1 Input Selection
            ldi     TEMPL, CONFIG_EVSYS_ASYNCUSER1  ; get config constant
            st      X+, TEMPL                       ; write into register

            ret
