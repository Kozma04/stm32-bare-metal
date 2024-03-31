ENTRY(_reset);
MEMORY {
  FLASH(rx)  : ORIGIN = 0x08000000, LENGTH = 64k
  SRAM1(rwx) : ORIGIN = 0x20010000, LENGTH = 240k
  SRAM2(rwx) : ORIGIN = 0x2004c000, LENGTH = 16k
  DTCM(rw)   : ORIGIN = 0x20000000, LENGTH = 64k 
}
_estack     = ORIGIN(SRAM2) + LENGTH(SRAM2);    /* stack points to end of SRAM2 */

SECTIONS {
  .vectors  : { KEEP(*(.vectors)) }   > FLASH
  .text     : { *(.text*) }           > FLASH
  .rodata   : { *(.rodata*) }         > FLASH

  .data : {
    _sdata = .;   /* .data section start */
    *(.first_data)
    *(.data SORT(.data.*))
    _edata = .;  /* .data section end */
  } > SRAM1 AT > FLASH
  _sidata = LOADADDR(.data);

  .bss : {
    _sbss = .;              /* .bss section start */
    *(.bss SORT(.bss.*) COMMON)
    _ebss = .;              /* .bss section end */
  } > SRAM1

  . = ALIGN(8);
  _end = .;     /* for cmsis_gcc.h  */
 
  .ARM.attributes 0 : { *(.ARM.attributes) }
}