;**************************************************************;
; @description : Global Register Definition                    ;
;**************************************************************;

.IFNDEF GLOBAL_REGISTER
.SET    GLOBAL_REGISTER = 1

;**************************************************************;
; @section : Register Name Definition                          ;
;**************************************************************;

; [RESH:RESL] - Multiplication Result Register Pair
.DEF RESL  = r0
.DEF RESH  = r1

; [BUFFH:BUFFL] - Temporary Buffer Register Pair
.DEF BUFFL = r14
.DEF BUFFH = r15

; [TEMP3:TEMP2:TEMP1:TEMP0] - Temporary Register Group
.DEF TEMP0 = r16
.DEF TEMP1 = r17
.DEF TEMP2 = r18
.DEF TEMP3 = r19

; [ARG3:ARG2:ARG1:ARG0] - Subroutine Argument Register Group
.DEF ARG0 = r20
.DEF ARG1 = r21
.DEF ARG2 = r22
.DEF ARG3 = r23

.ENDIF
