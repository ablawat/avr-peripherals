;**********************************************************************************************;
; @description : Interrupt Vector Mapping                                                      ;
;**********************************************************************************************;

.CSEG

.ORG    0
rjmp    reset

; Timer/Counter B 0 - Capture Interrupt
.IF DEFINED(TCB0_CONFIG_DEFINE)
    .IF CONFIG_TCB0_CAPTURE_INTERRUPT == TCB_CAPTURE_INTERRUPT_ENABLED
        .ORG    TCB0_INT_vect
        rjmp    TCB_CAPTURE_ISR_NAME(0)
    .ENDIF
.ENDIF

; Timer/Counter B 1 - Capture Interrupt
.IF DEFINED(TCB1_CONFIG_DEFINE)
    .IF CONFIG_TCB1_CAPTURE_INTERRUPT == TCB_CAPTURE_INTERRUPT_ENABLED
        .ORG    TCB1_INT_vect
        rjmp    TCB_CAPTURE_ISR_NAME(1)
    .ENDIF
.ENDIF

; @brief Flash Program Code Start
.EQU FLASH_CODE_START = INT_VECTORS_SIZE
