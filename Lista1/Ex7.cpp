#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

int main(){
    char frase[100];

    printf("Digite uma frase: \n");
    gets(frase);

    int tam1 = strlen(frase);

    for(int i = 0;i <= tam1;i++)
        frase[i] = toUpper(frase[i]);

    printf("A frase: %s",frase);

    return 0;
}