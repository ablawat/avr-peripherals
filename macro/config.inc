;**********************************************************************************************;
; @section : Macro Definition                                                                  ;
;**********************************************************************************************;

.IFNDEF MACRO_CONFIG
.SET    MACRO_CONFIG = 1

#define SET_CONFIG_BYTE0(value) ((value) <<  0)
#define SET_CONFIG_BYTE1(value) ((value) <<  8)
#define SET_CONFIG_BYTE2(value) ((value) << 16)
#define SET_CONFIG_BYTE3(value) ((value) << 24)

#define GET_CONFIG_BYTE0(value) (LOW (LWRD(value)))
#define GET_CONFIG_BYTE1(value) (HIGH(LWRD(value)))
#define GET_CONFIG_BYTE2(value) (LOW (HWRD(value)))
#define GET_CONFIG_BYTE3(value) (HIGH(HWRD(value)))

.ENDIF
