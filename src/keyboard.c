#include"keyboard.h"
#include"isr.h"
#include"screen.h"
#include"port.h"


void keyboard_callback(registers_t regs)
{
	uint8_t key;
	char *foo="keyboard 0x00";
	
	char *hex = "0123456789ABCDEF";
	//monitor_write("keyboard interrupt");

		key=inb(0x60);
	if(key<0x80)
	{
	//monitor_write32hex(regs.int_no);


	foo[11]=hex[(key>>4) & 0x0F];
	foo[12]=hex[key&0x0F];
	
	switch(key)
	{
		case 0x1E:
			monitor_write("a");
			break;
		case 0x30:
			monitor_write("b");
			break;
		case 0x2E:
			monitor_write("c");
			break;
		case 0x20:
			monitor_write("d");
			break;
		case 0x12:
			monitor_write("e");
			break;
		case 0x21:
			monitor_write("f");
			break;
		case 0x22:
			monitor_write("g");
			break;
		case 0x23:
			monitor_write("h");
			break;
		case 0x17:
			monitor_write("i");
			break;
		case 0x24:
			monitor_write("j");
			break;
		case 0x25:
			monitor_write("k");
			break;
		case 0x26:
			monitor_write("l");
			break;
		case 0x32:
			monitor_write("m");
			break;
		case 0x31:
			monitor_write("n");
			break;
		case 0x18:
			monitor_write("o");
			break;
		case 0x10:
			monitor_write("q");
			break;
		case 0x13:
			monitor_write("r");
			break;
		case 0x1f:
			monitor_write("s");
			break;
		case 0x14:
			monitor_write("t");
			break;
		case 0x16:
			monitor_write("u");
			break;
		case 0x2f:
			monitor_write("v");
			break;
		case 0x11:
			monitor_write("w");
			break;
		case 0x2d:
			monitor_write("x");
			break;
		case 0x15:
			monitor_write("y");
			break;
		case 0x2c:
			monitor_write("z");
			break;
		case 0x19:
			monitor_write("p");
			break;
		case 0x02:
			monitor_write("1");
			break;
		case 0x03:
			monitor_write("2");
			break;
		case 0x04:
			monitor_write("3");
			break;
		case 0x05:
			monitor_write("4");
			break;
		case 0x06:
			monitor_write("5");
			break;
		case 0x07:
			monitor_write("6");
			break;
		case 0x08:
			monitor_write("7");
			break;
		case 0x09:
			monitor_write("8");
			break;
		case 0x0A:
			monitor_write("9");
			break;
		case 0x0B:
			monitor_write("0");
			break;

		case 0x0E:
			monitor_write("\b");
			break;
		case 0x1C:
			process_buf();
			break;
		

		






		case 0x45:
			break;
		case 0xC5:
			break;
		default:
			monitor_write(foo);
			break;
	}
	}

			
}

void init_keyboard()
{

	register_interrupt_handler(33,&keyboard_callback);

}
