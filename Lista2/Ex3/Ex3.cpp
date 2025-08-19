#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo;
    char linha[100];
    int contador = 0;

    arquivo = fopen("lista_nomes.txt","r");

    if(arquivo == NULL){
        printf("Erro ao iniciar o arquivo!");
        exit(1);
    }

    while(fgets(linha,sizeof(linha),arquivo) != NULL){
        contador++;
    }
    printf("O seu arquivo tem %d linhas",contador);

    fclose(arquivo);
    return 0;
}