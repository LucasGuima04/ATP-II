#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char frase[100], frase2[100];
    
    printf("Digite uma frase: \n");
    gets(frase);

    printf("Digite outra frase: \n");
    gets(frase2);

    int tam1 = strlen(frase);
    int tam2 = strlen(frase2);
    
    if(tam1 == tam2){
        printf("Frases sao do mesmo tamnho!");
    }else if(tam1 > tam2){
        printf("A primeira frase e maior!");
    }else{
        printf("A segunda frase e maior!");
    }

    return 0;
}