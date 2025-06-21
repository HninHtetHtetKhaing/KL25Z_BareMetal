MEMORY {
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 128K  /* KL25Z128 Flash */
    RAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 16K   /* KL25Z128 RAM */
}

SECTIONS {
    .text : {
        *(.vectors)    /* Interrupt vector table */
        *(.text*)      /* Code */
    } > FLASH

    .data : { *(.data*) } > RAM
    .bss  : { *(.bss*)  } > RAM
}
