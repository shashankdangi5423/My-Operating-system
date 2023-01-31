; In isr.c
[EXTERN isr_handler]

; This is our common ISR stub. It saves the processor state, sets
; up for kernel mode segments, calls the C-level fault handler,
; and finally restores the stack frame.
isr_common_stub:
   pusha                    ; Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax

   mov ax, ds               ; Lower 16-bits of eax = ds.
   push eax                 ; save the data segment descriptor

   mov ax, 0x10  ; load the kernel data segment descriptor
   mov ds, ax
   mov es, ax
   mov fs, ax
   mov gs, ax
		
   call isr_handler

   pop eax        ; reload the original data segment descriptor
   mov ds, ax
   mov es, ax
   mov fs, ax
   mov gs, ax

   popa                     ; Pops edi,esi,ebp...
   add esp, 8     ; Cleans up the pushed error code and pushed ISR number
   sti
   iret           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP




[GLOBAL isr0]
isr0:
  cli                 ; Disable interrupts
  push byte 10         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 0         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr1]
isr1:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 1         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr2]
isr2:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 2        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr3]
isr3:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 3         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr4]
isr4:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 4         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr5]
isr5:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 5         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr6]
isr6:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 6      ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr7]
isr7:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 7         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr8]
isr8:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 8         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr9]
isr9:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 9         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr10]
isr10:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 10         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr11]
isr11:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 11         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr12]
isr12:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 12         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr13]
isr13:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 13         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr14]
isr14:
  cli                 ; Disable interrupts
  push byte 0         ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 14         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr15]
isr15:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 15         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr16]
isr16:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 16         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr17]
isr17:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 17         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr18]
isr18:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 18         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr19]
isr19:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 19         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr20]
isr20:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 20         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr21]
isr21:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 21         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr22]
isr22:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 22         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr23]
isr23:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 23         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr24]
isr24:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 24         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr25]
isr25:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 25         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr26]
isr26:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 26         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr27]
isr27:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 27         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr28]
isr28:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 28         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr29]
isr29:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 29        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr30]
isr30:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 30         ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr31]
isr31:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 31        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr32]
isr32:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 32        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler
[GLOBAL isr33]
isr33:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 33        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr34]
isr34:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 34      ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr35]
isr35:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 35        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr36]
isr36:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 36        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr37]
isr37:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 37       ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr38]
isr38:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 38        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr39]
isr39:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 39        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr40]
isr40:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 40        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr41]
isr41:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 41        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr42]
isr42:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 42        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr43]
isr43:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 43        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr44]
isr44:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 44        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr45]
isr45:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 45        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.
[GLOBAL isr46]
isr46:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 46        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.

[GLOBAL isr47]
isr47:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 47        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.


[GLOBAL isr80]
isr80:
  cli                 ; Disable interrupts
  push byte 1        ; Push a dummy error code (if ISR0 doesn't push it's own error code)
  push byte 80        ; Push the interrupt number (0)
  jmp isr_common_stub ; Go to our common handler.







