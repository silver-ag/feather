#include "vga.h"
#include "repl.h"
#include "keyboard.h"

char tag_info[6] = "[INFO]";
char start[31] = " starting interactive mode...\n";

void kmain() {
  clear();
  writeString(tag_info, 0, 2);
  writeString(start, 0, 7);
  char c = ' ', pc, line[1024];
  int j = 0;
  while(1) {
    pc = c;
    c = inb(0x60);
    if (c != pc) {
      char k = convertScancode(c);
      if (k != '\x00') {
        writeChar(k, 0, 7);
        if (k != '\n' && k != '\b') {
          line[j] = k;
          line[j+1] = '\x00';
          j++;
        } else if (k == '\b') {
          j--;
          line[j] = '\x00';
        } else if (k == '\n') {
          if (parse(line) == "\x00") {
            writeChar('!', 0, 6);
          } else {
            writeChar('.', 0, 7);
          }
          writeChar('\n', 0, 7);
          line[0] = '\x00';
          j = 0;
        }
      }
    }
  }
  for (;;);
}
