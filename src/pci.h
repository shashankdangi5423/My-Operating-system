#include "types.h"
#include "port.h"
#include "screen.h"

#define DATA_PORT 0xCFC
#define COMMAND_PORT 0XCF8


typedef struct pci_device_description
{
	uint32_t portBase;
	uint32_t interrupt;

	uint16_t bus;
	uint16_t device;
	uint16_t function;

	uint16_t vendor_id;
	uint16_t device_id;

	uint8_t class_id;
	uint8_t subclass_id;
	uint8_t interface_id;

	uint8_t revision;
}pci_des;





uint32_t Read(uint16_t bus,uint16_t device,uint16_t function,uint32_t regsiteroffset);

void Write(uint16_t bus,uint16_t device,uint16_t function,uint32_t regsiteroffset,uint32_t value);

void selectdriver();
pci_des Get_Pci_Device_data(bus,device,function);

uint8_t DeviceHasFunctions(uint16_t bus,uint16_t device);
