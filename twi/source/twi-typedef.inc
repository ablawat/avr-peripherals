;**************************************************************;
; @description : Two-Wire Interface Type Definition            ;
;**************************************************************;

;**************************************************************;
; @section : Global Definition                                 ;
;**************************************************************;

.IFNDEF TWI_TYPE
.SET    TWI_TYPE = 1

; @brief Transfer
.EQU TWI_TRANSFER_STOP     = 0
.EQU TWI_TRANSFER_CONTINUE = 1

; @brief one second in nanoseconds
.EQU TWI_ONE_SECOND_IN_NS = 1000000000

.ENDIF
