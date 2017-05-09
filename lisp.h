char* lisp_print(char** argv) { // print function. print any number of args, returns nil
  int i = 1;
  while (argv[i][0]) {
    writeString(argv[i], 0, 7);
    i++;
  }
  return "\x00";
}

char* lisp_id(char** argv, int argn) { // identity function. takes one argument and rturns it
  if (argn == 1) {
    writeString("Error: no arguments to id\n", 0, 4);
    return "\x00";
  } else if (argn > 2) {
    writeString("Error: too many arguments to id\n", 0, 4);
    return "\x00";
  } else {
    return argv[1];
  }
}
