;**********************************************************************************************;
; @brief    Initializes Clock Controller Peripheral
;
; @input    : none
; @output   : none
;
; @used     : XH:XL (changed), TEMPH (changed), TEMPL (changed)
;**********************************************************************************************;
clkctrl_init:   ; get clock controller base address
                ldi     XH, HIGH (CLKCTRL_base)
                ldi     XL, LOW  (CLKCTRL_base)

                ldi     TEMPH, CPU_CCP_IOREG_gc         ; get I/O registers unlock value

                ; unlock protected I/O registers
                out     CPU_CCP, TEMPH                  ; write into configuration change protection

                ; configure register MCLKCTRLA
                ldi     TEMPL, CONFIG_CLKCTRL_MCLKCTRLA ; get config constant
                st      X+, TEMPL                       ; write into register

                ; unlock protected I/O registers
                out     CPU_CCP, TEMPH                  ; write into configuration change protection

                ; configure register MCLKCTRLB
                ldi     TEMPL, CONFIG_CLKCTRL_MCLKCTRLB ; get config constant
                st      X+, TEMPL                       ; write into register

                ; unlock protected I/O registers
                out     CPU_CCP, TEMPH                  ; write into configuration change protection

                ; configure register MCLKLOCK
                ldi     TEMPL, CONFIG_CLKCTRL_MCLKLOCK  ; get config constant
                st      X+, TEMPL                       ; write into register

                ret
