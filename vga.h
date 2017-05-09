#include "arrays.h"
#include "io.h"

void terminalScrollUp(); // declared here for ordering below


// deal with the cursor
unsigned short cursorX = 0;
unsigned short cursorY = 0;

void putCursorByLength(unsigned short pos) {
  outb(0x3D4, 14);
  outb(0x3D5, ((pos >> 8) & 0x00FF));
  outb(0x3D4, 15);
  outb(0x3D5, pos & 0x00FF);
}

void putCursor(unsigned short x, unsigned short y) {
  putCursorByLength(x + (80 * y));
  cursorX = x;
  cursorY = y;
}

// read things from the screen
char readCharByLength(int pos) {
  char *fb = (char *) 0x000B8000;
  return fb[2*pos];
}

char readChar(int x, int y) {
  return readCharByLength(x + (80 * y));
}

// write things to the framebuffer
void writeCharByLength(unsigned int i, char c, unsigned char fg, unsigned char bg) {
  char *fb = (char *) 0x000B8000;
  fb[2*i] = c;
  fb[2*i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void writeChar(char c, unsigned char fg, unsigned char bg) {
  if (c == '\n') {
    cursorX = 0;
    cursorY++;
    if (cursorY == 25) {
      terminalScrollUp();
    }
  } else if (c == '\b') {
    if (cursorX == 0) {
      cursorX = 80;
      cursorY--;
    } else {
      cursorX--;
    }
    writeChar(' ', 0, 0);
    if (cursorX == 0) {
      cursorX = 80;
      cursorY--;
    } else {
      cursorX--;
    }
  } else {
    cursorX++;
    writeCharByLength(cursorX + (80 * cursorY) - 1, c, fg, bg);
  }
  if (cursorX == 80) {
    cursorX = 0;
    cursorY++;
    if (cursorY == 25) {
      terminalScrollUp();
    }
  }
  putCursor(cursorX, cursorY);
}

void writeString(char* str,unsigned char fg, unsigned char bg) {
  unsigned int i = 0;
  while (i < length(str)) {
    writeChar(str[i], fg, bg);
    i++;
  }
}

void clear() {
  int i = 0;
  while (i < 24) {
    terminalScrollUp();
    i++;
  }
  putCursor(0,0);
}

void terminalScrollUp() {
  char *fb = (char *) 0x000B8000;
  int i = 0;
  while (i < 160*25) {
    fb[i] = fb[i + 160];
    i++;
  }
  i = 160*24;
  while (i < 160) {
    fb[i] = 0;
  }
  cursorX = 0;
  cursorY = 24;
  putCursor(cursorX, cursorY);
}
