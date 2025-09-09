#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char frase[100];
    struct no *prox;
} No;

void insere_inic(struct no** atual, char frase[100]){
    No* aux = (No*)malloc(sizeof(No));
    strcpy(aux->frase,frase);
    aux->prox = *atual;
    *atual = aux;
};

void liberar_lista(No *lista){
    No* atual = lista;
    while(atual->prox != NULL){
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

void imprimir_lista(No *lista){
    No* atual = lista;
    printf("---------Lista---------\n");
    while (atual != NULL){
        printf("%s\n",atual->frase);
        atual = atual->prox;
    }
}

int main(){
    int valor;
    No* lista = NULL;
    printf("Quantos elementos deseja na lista?\n");
    scanf("%d",&valor);

    printf("\nDigite: \n");
    for(int i=0;i<valor;i++){
        char frase[100];
        scanf("%s",frase);
        insere_inic(&lista,frase);
    }

    imprimir_lista(lista);
    liberar_lista(lista);

    return 0;
}