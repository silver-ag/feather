#include "lisp.h"

char* parse(char expr[]);

int argn(char** expr) {
  int i = 0;
  while (i < 64) {
    if (expr[i] == "\x00") {
      return i;
    }
    i++;
  }
  return 2;
}

char* evaluate(char** expr) {
  int i = 0;
  while (i < argn(expr)) {
    if (expr[i][0] == '(') {
      expr[i] = parse(expr[i]);
    }
    i++;
  }
  if (strcmp(expr[0], "print")) {
    return lisp_print(expr);
  } else if (strcmp(expr[0], "id")) {
    return lisp_id(expr, argn(expr));
  } else {
    writeString(expr[0], 0, 6);
    writeChar('\n', 0, 6);
  }
  return "\x00";
}

char* parse(char expr[]) {
  unsigned int i = 0;
  int brackets = 0;
  while (i < length(expr)) { // before parsing, check the brackets add up
    if (expr[i] == '(') {
      brackets++;
    } else if (expr[i] == ')') {
      brackets--;
    }
    if (brackets == 0 && i < length(expr) - 1) {
      return "\x00";
    }
    i++;
  }
  if (brackets != 0) {
    return "\x00";
  }
  if (expr[0] != '(') {
    return "\x00";
  }
  if (expr[length(expr) - 1] != ')') {
    return "\x00";
  }
  i = 1;
  char** exprArray;
  exprArray[0][0] = '\x00';
  exprArray[1][0] = '\x00';
  int j = 0, k = 0, quotes = 0;
  while (i < length(expr) - 1) { // transpose onto a c array
    if (expr[i] == ' ' && brackets == 0 && quotes == 0) {
      if (expr[i-1] != ' ') {
        j++;
        exprArray[j+1][0] = '\x00';
        k = 0;
      }
    } else {
      if (expr[i] == '(') {
        brackets++;
      } else if (expr[i] == ')') {
        brackets--;
      }
      if (expr[i] == '"') {
        if (quotes == 1) {
          quotes = 0;
        } else {
          quotes = 1;
        }
      }
      exprArray[j][k] = expr[i];
      exprArray[j][k+1] = '\x00';
      k++;
    }
    i++;
  }
  int l = 0;
  while (l < j) {
    if (exprArray[l][0] == '(') {
      exprArray[l] = parse(exprArray[l]);
    }
    l++;
  }
  return evaluate(exprArray);
}
