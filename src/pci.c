#include "pci.h"


uint32_t Read(uint16_t bus,uint16_t device,uint16_t function,uint32_t regsiteroffset){
	uint32_t result;

	uint32_t id = 
		0x1 << 31 
		| ((bus & 0xFF) << 16)
		| ((device & 0x1F) << 11)
		| ((function & 0x07) << 8)
		| (regsiteroffset & 0xFC);
	

	out32(COMMAND_PORT,id);
	result = in32(DATA_PORT);
	//monitor_write_hex(id);
	//monitor_write("\n");


	
	return result >> (8 * (regsiteroffset % 4));


}



void Write(uint16_t bus,uint16_t device,uint16_t function,uint32_t regsiteroffset,uint32_t value);

uint8_t DeviceHasFunctions(uint16_t bus,uint16_t device)
{
	return Read(bus,device,0,0x0E)&(1<<7);
}

void selectdriver()
{
	int bus,device,function;
	 pci_des pci_data;





	
	

	for(bus = 0;bus < 8;bus++)
	{
		for(device = 0;device <32 ; device++)
		{
			int numFunctions = DeviceHasFunctions(bus,device) ? 8:1;
			//monitor_write_hex(numFunctions);
			//
			//monitor_write("\n");
			for (function = 0;function <numFunctions ;function++)
			{
				 pci_des pci_data;
				pci_data=Get_Pci_Device_data(bus,device,function);
				if(pci_data.vendor_id ==0x0000 ||pci_data.vendor_id == 0xFFFF){
					continue;
				}




				monitor_write("pci bus ");
				monitor_write_hex(bus & 0xFF);
				monitor_write(", device");
				monitor_write_hex(device & 0xFF);
				monitor_write(",function ");
				monitor_write_hex(function & 0xFF);
				monitor_write("vendor= ");
				monitor_write_hex((pci_data.vendor_id &0xFF00)>>8);
				monitor_write_hex(pci_data.vendor_id &0xFF);
				//monitor_write_hex(pci_data.vendor_id);

				monitor_write(",device id ");
				monitor_write_hex((pci_data.device_id &0xFF00)>>8);
				monitor_write_hex(pci_data.device_id &0xFF);
				//monitor_write_hex(pci_data.device_id);
				monitor_write("\n");
			}
		}
	}

		 
	pci_data=Get_Pci_Device_data(0x00,0x14,0x03);
	monitor_write_hex(pci_data.vendor_id);
	monitor_write("device=");
	monitor_write_hex(pci_data.device_id);
	
	
}


pci_des Get_Pci_Device_data(bus,device,function)
{

	pci_des pci_data;

	pci_data.bus=bus;
	pci_data.device=device;
	pci_data.function=function;

	pci_data.vendor_id = Read(bus,device,function,0x00);
	pci_data.device_id = Read(bus,device,function,0x02);

	pci_data.class_id = Read(bus,device,function,0x0b);
	pci_data.subclass_id = Read(bus,device,function,0x0a);
	pci_data.interface_id = Read(bus,device,function,0x09);

	pci_data.revision = Read(bus,device,function,0x08);
	pci_data.interrupt = Read(bus,device,function,0x3c);

	return pci_data;
}









