GCCPARAMS = -m32 -ffreestanding
ASPARAMS = -f elf32
LDPARAMS = -melf_i386


objects =  obj/multiboot_header.o \
	   obj/boot.o \
	   obj/long_mode_start.o \
	   obj/kernel.o \
	   obj/gdt.o \
	   obj/gdt_flush.o \
	   obj/screen.o \
	   obj/idt_flush.o \
	   obj/isr.o \
	   obj/isr_stub.o\
	   obj/port.o\
	   obj/timer.o \
	   obj/keyboard.o\
	   obj/file.o \
	   obj/pci.o 



obj/%.o :src/%.c
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o :src/%.asm
	nasm $(ASPARAMS) -o $@ $<





kernel.bin: linker.ld $(objects)	
	ld $(LDPARAMS)  -n -o kernel.bin -T $< -o $@ $(objects)

os.iso: kernel.bin grub.cfg
	mkdir -p isofiles/boot/grub
	cp grub.cfg isofiles/boot/grub
	cp kernel.bin isofiles/boot/
	grub-mkrescue -o os.iso isofiles


run :os.iso 
	(killall VirtualBox && sleep 1) ||true
	VirtualBox --startvm 'intermezzOS' &

