nasm -f elf32 start.asm
nasm -f elf32 io.asm
gcc -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -c main.c -o main.o
ld -n -Tlink.ld -melf_i386 start.o main.o io.o -o kernel
cp kernel isodir/boot
grub-mkrescue -o feather.iso isodir
