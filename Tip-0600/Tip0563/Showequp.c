#include <stdio.h>
#include <bios.h>

void main(void)
 {
   struct Equip 
	 {
     unsigned floppy_available:1;
     unsigned coprocessor_available:1;
     unsigned system_memory:2;
     unsigned video_memory:2;
     unsigned floppy_disk_count:2;
     unsigned unused_1:1;
     unsigned serial_port_count:3;
     unsigned game_adapter_available:1;
     unsigned unused_2:1;
     unsigned printer_count:2;
   };

   union Equipment 
	 {
     unsigned list;
     struct Equip list_bits;
   } equip;

   equip.list = _bios_equiplist();

   if (equip.list_bits.coprocessor_available)
     printf("Math coprocessor available\n");
   else
     printf("No math coprocessor\n");

   printf("System board memory %d\n", 
      (equip.list_bits.system_memory + 1) * 16);

   printf("Number of floppies %d\n", 
      equip.list_bits.floppy_disk_count + 1);

   printf("Number of printers %d\n",
      equip.list_bits.printer_count);

   printf("Number of serial ports %d\n",
      equip.list_bits.serial_port_count);
 }


