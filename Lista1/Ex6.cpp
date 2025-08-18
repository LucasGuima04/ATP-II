#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removerEspacos(char *str) {
  int i, j = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ') {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
}