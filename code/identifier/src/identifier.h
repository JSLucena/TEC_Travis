#include<stdio.h>

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