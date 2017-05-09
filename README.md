# feather
a particularly hackable operating system.
very much work in progress. Eventually, the kernel will implement a lisp-like scripting language (or possibly an already existing lisp) and load a core script to do everything that doesn't have to be in the kernel.

### requirements
building feather requires gcc, ld, nasm and grub2. You could probably substitute another c compiler and linker if you modify build.sh to use them. Replacing nasm would be slightly less simple, since some its preprocessor functions are used. If you're using linux you almost certainly have gcc and ld already. In some distro's package management grub2 is just called grub, and grub is called grub-legacy or something.

### installation
run
```
./build.sh
```
to generate `feather.iso`. It is very strongly recommended that you only run feather in a virtual machine, especially at this stage.
