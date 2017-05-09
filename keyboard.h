int shift = 0;

char convertScancode(unsigned char c) {
  if (c == '\x3a' && !shift) {
    shift = 1;
    return '\x00';
  }
  if (c == '\x3a' && shift) {
    shift = 0;
    return '\x00';
  }
  if (c == '\x2a' || c == '\x36') {
    return '\x00';
  }
  if (!shift) {
    if (c < 129) {
      if (c == '\x10') { return 'q'; }
      if (c == '\x11') { return 'w'; }
      if (c == '\x12') { return 'e'; }
      if (c == '\x13') { return 'r'; }
      if (c == '\x14') { return 't'; }
      if (c == '\x15') { return 'y'; }
      if (c == '\x16') { return 'u'; }
      if (c == '\x17') { return 'i'; }
      if (c == '\x18') { return 'o'; }
      if (c == '\x19') { return 'p'; }
      if (c == '\x1e') { return 'a'; }
      if (c == '\x1f') { return 's'; }
      if (c == '\x20') { return 'd'; }
      if (c == '\x21') { return 'f'; }
      if (c == '\x22') { return 'g'; }
      if (c == '\x23') { return 'h'; }
      if (c == '\x24') { return 'j'; }
      if (c == '\x25') { return 'k'; }
      if (c == '\x26') { return 'l'; }
      if (c == '\x2c') { return 'z'; }
      if (c == '\x2d') { return 'x'; }
      if (c == '\x2e') { return 'c'; }
      if (c == '\x2f') { return 'v'; }
      if (c == '\x30') { return 'b'; }
      if (c == '\x31') { return 'n'; }
      if (c == '\x32') { return 'm'; }
      if (c == '\x39') { return ' '; }
      if (c == '\x02') { return '1'; }
      if (c == '\x03') { return '2'; }
      if (c == '\x04') { return '3'; }
      if (c == '\x05') { return '4'; }
      if (c == '\x06') { return '5'; }
      if (c == '\x07') { return '6'; }
      if (c == '\x08') { return '7'; }
      if (c == '\x09') { return '8'; }
      if (c == '\x0a') { return '9'; }
      if (c == '\x0b') { return '0'; }
      if (c == '\x0c') { return '-'; }
      if (c == '\x0d') { return '='; }
      if (c == '\x1a') { return '['; }
      if (c == '\x1b') { return ']'; }
      if (c == '\x27') { return ';'; }
      if (c == '\x28') { return '\''; }
      if (c == '\x29') { return '`'; }
      if (c == '\x2b') { return '\\'; }
      if (c == '\x33') { return ','; }
      if (c == '\x34') { return '.'; }
      if (c == '\x35') { return '/'; }
      if (c == '\x1c') { return '\n'; }
      if (c == '\x0e') { return '\b'; }
      return '?';
    }
  } else {
    if (c < 129) {
      if (c == '\x10') { return 'Q'; }
      if (c == '\x11') { return 'W'; }
      if (c == '\x12') { return 'E'; }
      if (c == '\x13') { return 'R'; }
      if (c == '\x14') { return 'T'; }
      if (c == '\x15') { return 'Y'; }
      if (c == '\x16') { return 'U'; }
      if (c == '\x17') { return 'I'; }
      if (c == '\x18') { return 'O'; }
      if (c == '\x19') { return 'P'; }
      if (c == '\x1e') { return 'A'; }
      if (c == '\x1f') { return 'S'; }
      if (c == '\x20') { return 'D'; }
      if (c == '\x21') { return 'F'; }
      if (c == '\x22') { return 'G'; }
      if (c == '\x23') { return 'H'; }
      if (c == '\x24') { return 'J'; }
      if (c == '\x25') { return 'K'; }
      if (c == '\x26') { return 'L'; }
      if (c == '\x2c') { return 'Z'; }
      if (c == '\x2d') { return 'X'; }
      if (c == '\x2e') { return 'C'; }
      if (c == '\x2f') { return 'V'; }
      if (c == '\x30') { return 'B'; }
      if (c == '\x31') { return 'N'; }
      if (c == '\x32') { return 'M'; }
      if (c == '\x39') { return ' '; }
      if (c == '\x02') { return '!'; }
      if (c == '\x03') { return '@'; }
      if (c == '\x04') { return '#'; }
      if (c == '\x05') { return '$'; }
      if (c == '\x06') { return '%'; }
      if (c == '\x07') { return '^'; }
      if (c == '\x08') { return '&'; }
      if (c == '\x09') { return '*'; }
      if (c == '\x0a') { return '('; }
      if (c == '\x0b') { return ')'; }
      if (c == '\x0c') { return '_'; }
      if (c == '\x0d') { return '+'; }
      if (c == '\x1a') { return '{'; }
      if (c == '\x1b') { return '}'; }
      if (c == '\x27') { return ':'; }
      if (c == '\x28') { return '"'; }
      if (c == '\x29') { return '|'; }
      if (c == '\x2b') { return '~'; }
      if (c == '\x33') { return '<'; }
      if (c == '\x34') { return '>'; }
      if (c == '\x35') { return '?'; }
      if (c == '\x1c') { return '\n'; }
      if (c == '\x0e') { return '\b'; }
      return '?';
    }
  }
  return '\x00';
}
