MEMORY {
  drom   (rw)   : ORIGIN = 0X3ff90000, LENGTH = 64k
  irom   (rwx)  : ORIGIN = 0x40000000, LENGTH = 384k

  cache0 (rwx)  : ORIGIN = 0x40070000, LENGTH = 32k
  cache1 (rwx)  : ORIGIN = 0x40078000, LENGTH = 32k
  iram   (rwx)  : ORIGIN = 0x40080400, LENGTH = 127k
  dram   (rw)   : ORIGIN = 0x3ffb0000, LENGTH = 320k

  dflash (rw)   : ORIGIN = 0X3f400000, LENGTH = 1024k
  psram  (rw)   : ORIGIN = 0X3f800000, LENGTH = 1024k
  iflash (rwx)  : ORIGIN = 0X400c2000, LENGTH = 11512k
}

_eram = ORIGIN(dram) + LENGTH(dram);
ENTRY(_main)

SECTIONS {
  /* .vectors  : { KEEP(*(.vectors))   } > iram */
  .text     : { *(.text*) *(.text)  } > iram

  .data : {
    . = ALIGN(4);
    _sdata = .;
    *(.data)
    *(.data*)
    *(.rodata)
    *(.rodata*)
    *(.gnu.linkonce.r.*)
    *(.rodata1)
    . = ALIGN(4);
    _edata = .;
  } > dram

  .bss : {
    . = ALIGN(4);
    _sbss = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > dram

  . = ALIGN(4);
  PROVIDE(end = .);
  PROVIDE(_end = .);

  /*
  /DISCARD/ : { *(.debug) *(.debug*) *(.xtensa.*) *(.comment) }
  */
}

PROVIDE(memcpy = 0x4000c2c8);
PROVIDE(printf = 0x40007d54);