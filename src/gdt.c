#include "gdt.h"
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void isr32();
extern void isr33();
extern void isr34();
extern void isr35();
extern void isr36();
extern void isr37();
extern void isr38();
extern void isr39();
extern void isr40();
extern void isr41();
extern void isr42();
extern void isr43();
extern void isr44();
extern void isr45();
extern void isr46();
extern void isr47();
extern void isr80();




void init_descriptor_tables()
{
   // Initialise the global descriptor table.
   init_gdt();
   init_idt();
   
}

static void init_gdt()
{
   gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
   gdt_ptr.base  = (uint32_t)&gdt_entries;

   gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
   gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
   gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
   gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
   gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

   gdt_flush((uint32_t)&gdt_ptr);
}

// Set the value of one GDT entry.
static void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
   gdt_entries[num].base_low    = (base & 0xFFFF);
   gdt_entries[num].base_middle = (base >> 16) & 0xFF;
   gdt_entries[num].base_high   = (base >> 24) & 0xFF;

   gdt_entries[num].limit_low   = (limit & 0xFFFF);
   gdt_entries[num].granularity = (limit >> 16) & 0x0F;

   gdt_entries[num].granularity |= gran & 0xF0;
   gdt_entries[num].access      = access;
}


static void init_idt()
{
   idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
   idt_ptr.base  = (uint32_t)&idt_entries;
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  outb(0x21, 0x20);
  outb(0xA1, 0x28);
  outb(0x21, 0x04);
  outb(0xA1, 0x02);
  outb(0x21, 0x01);
  outb(0xA1, 0x01);
  outb(0x21, 0x0);
  outb(0xA1, 0x0);

   //memset(&idt_entries, 0, sizeof(idt_entry_t)*256);
 

  idt_set_gate( 0, (uint32_t)isr0 , 0x08, 0x8E);
  idt_set_gate( 1, (uint32_t)isr1 , 0x08, 0x8E);
  idt_set_gate( 2, (uint32_t)isr2 , 0x08, 0x8E);
  idt_set_gate( 3, (uint32_t)isr3 , 0x08, 0x8E);
  idt_set_gate( 4, (uint32_t)isr4 , 0x08, 0x8E);
  idt_set_gate( 5, (uint32_t)isr5 , 0x08, 0x8E);
  idt_set_gate( 6, (uint32_t)isr6 , 0x08, 0x8E);
  idt_set_gate( 7, (uint32_t)isr7 , 0x08, 0x8E);
  idt_set_gate( 8, (uint32_t)isr8 , 0x08, 0x8E);
  idt_set_gate( 9, (uint32_t)isr9 , 0x08, 0x8E);
  idt_set_gate( 10, (uint32_t)isr10 , 0x08, 0x8E);
  idt_set_gate( 11, (uint32_t)isr11 , 0x08, 0x8E);
  idt_set_gate( 12, (uint32_t)isr12 , 0x08, 0x8E);
  idt_set_gate( 13, (uint32_t)isr13 , 0x08, 0x8E);
  idt_set_gate( 14, (uint32_t)isr14 , 0x08, 0x8E);
  idt_set_gate( 15, (uint32_t)isr15 , 0x08, 0x8E);
  idt_set_gate( 16, (uint32_t)isr16, 0x08, 0x8E);
  idt_set_gate( 17, (uint32_t)isr17, 0x08, 0x8E);
  idt_set_gate( 18, (uint32_t)isr18 , 0x08, 0x8E);
  idt_set_gate( 19, (uint32_t)isr19 , 0x08, 0x8E);
  idt_set_gate( 20, (uint32_t)isr20 , 0x08, 0x8E);
  idt_set_gate( 21, (uint32_t)isr21 , 0x08, 0x8E);
  idt_set_gate( 22, (uint32_t)isr22 , 0x08, 0x8E);
  idt_set_gate( 23, (uint32_t)isr23, 0x08, 0x8E);
  idt_set_gate( 24, (uint32_t)isr24 , 0x08, 0x8E);
  idt_set_gate( 25, (uint32_t)isr25 , 0x08, 0x8E);
  idt_set_gate( 26, (uint32_t)isr26 , 0x08, 0x8E);
  idt_set_gate( 27, (uint32_t)isr27 , 0x08, 0x8E);
  idt_set_gate( 28, (uint32_t)isr28 , 0x08, 0x8E);
  idt_set_gate( 29, (uint32_t)isr29 , 0x08, 0x8E);
  idt_set_gate( 30, (uint32_t)isr30 , 0x08, 0x8E);
  idt_set_gate(31, (uint32_t)isr31, 0x08, 0x8E);

  idt_set_gate(32, (uint32_t)isr32, 0x08, 0x8E);
  idt_set_gate(33, (uint32_t)isr33, 0x08, 0x8E);
  idt_set_gate(34, (uint32_t)isr34, 0x08, 0x8E);
  idt_set_gate(35, (uint32_t)isr35, 0x08, 0x8E);
  idt_set_gate(36, (uint32_t)isr36, 0x08, 0x8E);
  idt_set_gate(37, (uint32_t)isr37, 0x08, 0x8E);
  idt_set_gate(38, (uint32_t)isr38, 0x08, 0x8E);
  idt_set_gate(39, (uint32_t)isr39, 0x08, 0x8E);
  idt_set_gate(40, (uint32_t)isr40, 0x08, 0x8E);
  idt_set_gate(41, (uint32_t)isr41, 0x08, 0x8E);
  idt_set_gate(42, (uint32_t)isr42, 0x08, 0x8E);
  idt_set_gate(43, (uint32_t)isr43, 0x08, 0x8E);
  idt_set_gate(44, (uint32_t)isr44, 0x08, 0x8E);
  idt_set_gate(45, (uint32_t)isr45, 0x08, 0x8E);
  idt_set_gate(46, (uint32_t)isr46, 0x08, 0x8E);
  idt_set_gate(47, (uint32_t)isr47, 0x08, 0x8E);
  idt_set_gate(80, (uint32_t)isr80, 0x08, 0x8E);





   idt_flush((uint32_t)&idt_ptr);
}

static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
   idt_entries[num].base_lo = base & 0xFFFF;
   idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

   idt_entries[num].sel     = sel;
   idt_entries[num].always0 = 0;
   // We must uncomment the OR below when we get to using user-mode.
   // It sets the interrupt gate's privilege level to 3.
   idt_entries[num].flags   = flags;
}
