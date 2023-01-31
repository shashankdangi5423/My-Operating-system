#include "port.h"


void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

 uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}



uint32_t in32(uint16_t port)
{
	uint32_t ret;
	asm volatile ( "inl %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

void out32(uint16_t port,uint32_t val)
{
asm volatile ( "outl %0, %1" : : "a"(val), "Nd"(port) );



 }	 
