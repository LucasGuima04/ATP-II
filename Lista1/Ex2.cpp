#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];

    printf("Digite uma frase: \n");
    gets(frase);

    int tamanho = strlen(frase);

    for(int i=tamanho;i>=0;i--){
        printf("%c",frase[i]);
    }
    return 0;
}