 global loader                   ; the entry symbol for ELF

    MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
    FLAGS        equ 0x0            ; multiboot flags
    CHECKSUM     equ -MAGIC_NUMBER  ; calculate the checksum
    KERNEL_STACK_SIZE equ 8192                  ; size of stack in bytes
                                    ; (magic number + checksum + flags should equal 0)

    section .bss
    align 4                                     ; align at 4 bytes
    kernel_stack:                               ; label points to beginning of memory
        resb KERNEL_STACK_SIZE                  ; reserve stack for the kernel

    section .multiboot
    align 4
        dd MAGIC_NUMBER             ; write the magic number to the machine code,
        dd FLAGS                    ; the flags,
        dd CHECKSUM                 ; and the checksum

    section .text:                  ; start of the text (code) section
    align 4                         ; the code must be 4 byte aligned


    loader:                         ; the loader label (defined as entry point in linker script)
        mov esp, kernel_stack + KERNEL_STACK_SIZE
	extern kmain
        call kmain
    .loop:
        jmp .loop                   ; loop forever
