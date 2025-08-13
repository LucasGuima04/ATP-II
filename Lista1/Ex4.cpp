#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removerEspacos(char *str) {
  int i, j = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ') {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
}

int main(){
    char frase[100];
    char temp[100];
    
    printf("Digite uma frase: \n");
    gets(frase);

    strlwr(frase);
    removerEspacos(frase);
    strcpy(temp,frase);
    strrev(frase);
    
    //printf("%s\n", frase);

    if(strcmp(frase,temp) == 0){
        printf("A frase e um palindromo!");
    } else{
        printf("A frase nao e um palindromo!");
    }

    return 0;
}