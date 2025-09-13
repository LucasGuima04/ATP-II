#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
    char nome[100];
    int nMatricula;
    struct no *prox;
} No;

int num = 1;

void insere_inic(No** lista, char nome[100]){
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->nome,nome);
    novo->nMatricula = num;
    novo->prox = *lista;
    *lista = novo;
    num++;
};

void imprimir(No *lista){
    No* atual = lista;
    while(atual != NULL){
        printf("N: %-2d Nome:%s|\n",atual->nMatricula,atual->nome);
        atual = atual->prox;
    }
    printf("\n");
}

void liberar(No *lista){
    No* atual = lista;
    while(atual->prox != NULL){
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main(){
    No* lista = NULL;
    int opc = 0;
    char nome[100];
    do{
    printf("Escolha a opcao desejada:\n");
    printf("(1) Adicionar aluno\n");
    printf("(2) Imprimir Lista\n");
    printf("(3) Finalizar\n");
    printf("Opcao: ");
    scanf("%d", &opc);

    while (getchar() != '\n');

    switch (opc){
    case 1:
        printf("Digite o nome do aluno: ");
        fgets(nome, 100, stdin);
        nome[strcspn(nome, "\n")] = 0;
        insere_inic(&lista, nome);
        printf("\n");
        break;
    case 2:
        imprimir(lista);
        break;
    case 3:
        liberar(lista);
        printf("Sucesso!");
        break;
    }
    }while(opc != 3);

    return 0;
}
