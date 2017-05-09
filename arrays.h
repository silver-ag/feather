// functions for dealing with array strings

unsigned int length(char arr[]) {
  unsigned int i = 0;
  while (arr[i]) {
    i++;
  }
  return i;
}

int strcmp(char str1[], char str2[]) {
  unsigned int i = 0;
  if (length(str1) != length(str2)) {
    return 0;
  }
  while (i < length(str1) - 1) {
    if (str1[i] != str2[i]) {
      return 0;
    }
    i++;
  }
  return 1;
}
