#include "types.h"
#include "gdt.h"
#include "screen.h"
#include "timer.h"
#include"keyboard.h"
#include "pci.h"

		

void main()
{
	

	
	init_descriptor_tables();
	asm volatile("sti");
	init_timer(100);
	init_keyboard();
	//selectdriver();
	//init_sample();
	
	//asm volatile("int $0x50");
	

}
