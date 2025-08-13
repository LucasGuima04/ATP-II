#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];

    printf("Digite uma frase!\n");
    gets(frase);

    int tamanho = strlen(frase);
    printf("o tamanho da sua frase e de %d caracteres!", tamanho);

    return 0;
}