#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo;
    char linha[100];

    arquivo = fopen("lista_nomes.txt","r");

    if(arquivo == NULL){
        printf("Erro ao iniciar o arquivo!");
        exit(1);
    }


    printf("Os nomes sao: \n");
    while(fgets(linha,sizeof(linha),arquivo) != NULL){
        printf("%s", linha);
    }

    fclose(arquivo);
    return 0;
}