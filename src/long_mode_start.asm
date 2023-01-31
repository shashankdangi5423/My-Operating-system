global long_mode_start

section .text
bits 32
;bits 32
long_mode_start:
     ;print `OKAY` to screen
    mov ax, 0x0259
    mov word [0xb8000], ax
	mov word [0xb8002],0x0259
    ;mov word [0xb8010],rax	
    hlt
