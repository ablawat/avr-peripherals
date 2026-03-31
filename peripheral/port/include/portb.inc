;**********************************************************************************************;
; @description : Input and Output Pin Configuration B Header                                   ;
;**********************************************************************************************;

;**********************************************************************************************;
; @section : Include File                                                                      ;
;**********************************************************************************************;

.INCLUDE "config/port/portb-config.inc"

;**********************************************************************************************;
; @section : Register Configuration                                                            ;
;**********************************************************************************************;

; DIR - Pin Data Direction
.EQU CONFIG_PORTB_DIR_PB0 = CONFIG_PORTB_PIN0_DATA_DIRECTION
.EQU CONFIG_PORTB_DIR_PB1 = CONFIG_PORTB_PIN1_DATA_DIRECTION
.EQU CONFIG_PORTB_DIR_PB2 = CONFIG_PORTB_PIN2_DATA_DIRECTION
.EQU CONFIG_PORTB_DIR_PB3 = CONFIG_PORTB_PIN3_DATA_DIRECTION
.EQU CONFIG_PORTB_DIR_PB4 = CONFIG_PORTB_PIN4_DATA_DIRECTION
.EQU CONFIG_PORTB_DIR_PB5 = CONFIG_PORTB_PIN5_DATA_DIRECTION
.EQU CONFIG_PORTB_DIR_PB6 = CONFIG_PORTB_PIN6_DATA_DIRECTION
.EQU CONFIG_PORTB_DIR_PB7 = CONFIG_PORTB_PIN7_DATA_DIRECTION

; @brief Data Direction Register
.EQU CONFIG_PORTB_DIR = (CONFIG_PORTB_DIR_PB0 << 0) | \
                        (CONFIG_PORTB_DIR_PB1 << 1) | \
                        (CONFIG_PORTB_DIR_PB2 << 2) | \
                        (CONFIG_PORTB_DIR_PB3 << 3) | \
                        (CONFIG_PORTB_DIR_PB4 << 4) | \
                        (CONFIG_PORTB_DIR_PB5 << 5) | \
                        (CONFIG_PORTB_DIR_PB6 << 6) | \
                        (CONFIG_PORTB_DIR_PB7 << 7)

; OUT - Pin Output Value
.EQU CONFIG_PORTB_OUT_PB0 = CONFIG_PORTB_PIN0_OUTPUT_LEVEL
.EQU CONFIG_PORTB_OUT_PB1 = CONFIG_PORTB_PIN1_OUTPUT_LEVEL
.EQU CONFIG_PORTB_OUT_PB2 = CONFIG_PORTB_PIN2_OUTPUT_LEVEL
.EQU CONFIG_PORTB_OUT_PB3 = CONFIG_PORTB_PIN3_OUTPUT_LEVEL
.EQU CONFIG_PORTB_OUT_PB4 = CONFIG_PORTB_PIN4_OUTPUT_LEVEL
.EQU CONFIG_PORTB_OUT_PB5 = CONFIG_PORTB_PIN5_OUTPUT_LEVEL
.EQU CONFIG_PORTB_OUT_PB6 = CONFIG_PORTB_PIN6_OUTPUT_LEVEL
.EQU CONFIG_PORTB_OUT_PB7 = CONFIG_PORTB_PIN7_OUTPUT_LEVEL

; @brief Output Value Register
.EQU CONFIG_PORTB_OUT = (CONFIG_PORTB_OUT_PB0 << 0) | \
                        (CONFIG_PORTB_OUT_PB1 << 1) | \
                        (CONFIG_PORTB_OUT_PB2 << 2) | \
                        (CONFIG_PORTB_OUT_PB3 << 3) | \
                        (CONFIG_PORTB_OUT_PB4 << 4) | \
                        (CONFIG_PORTB_OUT_PB5 << 5) | \
                        (CONFIG_PORTB_OUT_PB6 << 6) | \
                        (CONFIG_PORTB_OUT_PB7 << 7)

; PIN0CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN0CTRL_INVEN    = CONFIG_PORTB_PIN0_POLARITY_INVERSION

; PIN0CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN0CTRL_PULLUPEN = CONFIG_PORTB_PIN0_PULLUP

; PIN0CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN0CTRL_ISC      = CONFIG_PORTB_PIN0_INPUT_BUFFER

; @brief Pin 0 Control Register
.EQU CONFIG_PORTB_PIN0CTRL = (CONFIG_PORTB_PIN0CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN0CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN0CTRL_ISC      << PORT_ISC_gp     )

; PIN1CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN1CTRL_INVEN    = CONFIG_PORTB_PIN1_POLARITY_INVERSION

; PIN1CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN1CTRL_PULLUPEN = CONFIG_PORTB_PIN1_PULLUP

; PIN1CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN1CTRL_ISC      = CONFIG_PORTB_PIN1_INPUT_BUFFER

; @brief Pin 1 Control Register
.EQU CONFIG_PORTB_PIN1CTRL = (CONFIG_PORTB_PIN1CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN1CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN1CTRL_ISC      << PORT_ISC_gp     )

; PIN2CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN2CTRL_INVEN    = CONFIG_PORTB_PIN2_POLARITY_INVERSION

; PIN2CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN2CTRL_PULLUPEN = CONFIG_PORTB_PIN2_PULLUP

; PIN2CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN2CTRL_ISC      = CONFIG_PORTB_PIN2_INPUT_BUFFER

; @brief Pin 2 Control Register
.EQU CONFIG_PORTB_PIN2CTRL = (CONFIG_PORTB_PIN2CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN2CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN2CTRL_ISC      << PORT_ISC_gp     )

; PIN3CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN3CTRL_INVEN    = CONFIG_PORTB_PIN3_POLARITY_INVERSION

; PIN3CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN3CTRL_PULLUPEN = CONFIG_PORTB_PIN3_PULLUP

; PIN3CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN3CTRL_ISC      = CONFIG_PORTB_PIN3_INPUT_BUFFER

; @brief Pin 3 Control Register
.EQU CONFIG_PORTB_PIN3CTRL = (CONFIG_PORTB_PIN3CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN3CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN3CTRL_ISC      << PORT_ISC_gp     )

; PIN4CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN4CTRL_INVEN    = CONFIG_PORTB_PIN4_POLARITY_INVERSION

; PIN4CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN4CTRL_PULLUPEN = CONFIG_PORTB_PIN4_PULLUP

; PIN4CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN4CTRL_ISC      = CONFIG_PORTB_PIN4_INPUT_BUFFER

; @brief Pin 4 Control Register
.EQU CONFIG_PORTB_PIN4CTRL = (CONFIG_PORTB_PIN4CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN4CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN4CTRL_ISC      << PORT_ISC_gp     )

; PIN5CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN5CTRL_INVEN    = CONFIG_PORTB_PIN5_POLARITY_INVERSION

; PIN5CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN5CTRL_PULLUPEN = CONFIG_PORTB_PIN5_PULLUP

; PIN5CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN5CTRL_ISC      = CONFIG_PORTB_PIN5_INPUT_BUFFER

; @brief Pin 5 Control Register
.EQU CONFIG_PORTB_PIN5CTRL = (CONFIG_PORTB_PIN5CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN5CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN5CTRL_ISC      << PORT_ISC_gp     )

; PIN6CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN6CTRL_INVEN    = CONFIG_PORTB_PIN6_POLARITY_INVERSION

; PIN6CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN6CTRL_PULLUPEN = CONFIG_PORTB_PIN6_PULLUP

; PIN6CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN6CTRL_ISC      = CONFIG_PORTB_PIN6_INPUT_BUFFER

; @brief Pin 6 Control Register
.EQU CONFIG_PORTB_PIN6CTRL = (CONFIG_PORTB_PIN6CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN6CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN6CTRL_ISC      << PORT_ISC_gp     )

; PIN7CTRL - Inverted Input and Output Enable
.EQU CONFIG_PORTB_PIN7CTRL_INVEN    = CONFIG_PORTB_PIN7_POLARITY_INVERSION

; PIN7CTRL - Pull-Up Enable
.EQU CONFIG_PORTB_PIN7CTRL_PULLUPEN = CONFIG_PORTB_PIN7_PULLUP

; PIN7CTRL - Input and Sense Configuration
.EQU CONFIG_PORTB_PIN7CTRL_ISC      = CONFIG_PORTB_PIN7_INPUT_BUFFER

; @brief Pin 7 Control Register
.EQU CONFIG_PORTB_PIN7CTRL = (CONFIG_PORTB_PIN7CTRL_INVEN    << PORT_INVEN_bp   ) | \
                             (CONFIG_PORTB_PIN7CTRL_PULLUPEN << PORT_PULLUPEN_bp) | \
                             (CONFIG_PORTB_PIN7CTRL_ISC      << PORT_ISC_gp     )
