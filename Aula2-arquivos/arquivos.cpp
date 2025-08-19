#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("teste.txt","r"); //Abre para leitura r->read
    //w -> Escrita |a -> append |r+ -> leitura+escrita |b -> binario

    //rewind(Arquivo)-> cursor para o inicio do arquivo
    //fseek(Arquivo, 10, seek_set); 10 bytes do inicio 
    //(seek_end) -> fim (seek_cur) -> posição atual

    if(arquivo == NULL){
        printf("Erro ao abrir/criar arquivo!\n"); //Teste de criação
        exit(1);
    }
    //Operações com arquivo...
    fclose(arquivo);
    return 0;
}