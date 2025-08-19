#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *aqv1,*aqv2,*aqv3;
    char linha[256];

    //Inicializar/criar os arquivos
    aqv1 = fopen("text1.txt","r");
    aqv2 = fopen("text2.txt","r");
    aqv3 = fopen("text3.txt","w");

    //Verificação de erro de abertura do arquivo
    if(aqv1 == NULL && aqv2 == NULL && aqv3 == NULL){
        printf("Erro ao iniciar algum arquivo!");
        exit(1);
    }

    printf("Concatenando arquivos...");

    while(fgets(linha,sizeof(linha),aqv1) != NULL){
        fprintf(aqv3,"%s",linha);
    }
    fprintf(aqv3,"\n");
    while(fgets(linha,sizeof(linha),aqv2) != NULL){
        fprintf(aqv3,"%s",linha);
    }

    fclose(aqv1);
    fclose(aqv2);
    fclose(aqv3);
    return 0;
}