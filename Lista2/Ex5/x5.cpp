#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    char linha[100];
    int j = 0;
    char palavra[100];
    char *token;
    char *delimitador = " ";
    arquivo = fopen("texto.txt","r");

    if(arquivo == NULL){
        printf("Erro ao iniciar o arquivo!");
        exit(1);
    }


    printf("Digite a palavra que procura: \n");
    gets(palavra);

    while (fgets(linha,sizeof(linha),arquivo) != NULL){
        token = strtok(linha, delimitador);
            while (token != NULL) {
                if(strcmp(token,palavra) == 0){
                    printf("%s\n",linha);
                }
                token = strtok(NULL, delimitador);
            }
    }

    fclose(arquivo);
    return 0;

}