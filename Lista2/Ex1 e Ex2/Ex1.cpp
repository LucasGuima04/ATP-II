#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo;
    char nome[100];

    arquivo = fopen("lista_nomes.txt","w");

    if(arquivo == NULL){
        printf("Erro ao iniciar o arquivo!");
        exit(1);
    }

    printf("Digite os nomes da lista: \n");
    for(int i=0;i<5;i++){
        gets(nome);
        fprintf(arquivo,"%s\n",nome);
    }

    fclose(arquivo);
    return 0;
}