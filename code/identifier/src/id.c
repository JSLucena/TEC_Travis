#include <stdio.h>
int valid_s(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[]) {
  char achar;
  int   valid_id;
  printf("Identificador: ");
  achar = *(ch++);
  valid_id = valid_s(achar);
  achar = *(ch++);
  while(achar != '\n') {
    if(!(valid_f(achar))) {
      valid_id = 0;
    }
    achar = *(ch++);
  }
  if (valid_id && (length >= 1) && (length < 6)) {
    printf("Valido\n");
    return 0;
  }
  else {
    printf("Invalido\n");
    return 1;
  }
}