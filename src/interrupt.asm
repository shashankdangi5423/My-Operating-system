;%macro ISR_NOERRCODE 1  ; define a macro, taking one parameter
 ; [GLOBAL isr%1]        ; %1 accesses the first parameter.
  ;isr%1:
   ; cli
    ;push byte 0
    ;push byte %1
    ;jmp isr_common_stub
;%endmacro

;%macro ISR_ERRCODE 1
 ; [GLOBAL isr%1]
  ;isr%1:
   ; cli
   ; push byte %1
   ; jmp isr_common_stub
;%endmacro

extern  isr_common_stub

[GLOBAL isr0]
isr0:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 0         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr1]
isr1:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 1         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
