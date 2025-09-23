#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char frase[100];
    struct no *prox;
} No;

void adicionar_no(No **lista,char frase[100]){
    No *novo = (No*)malloc(sizeof(No)); //Alocar na memoria o espaço para o novo 'bloco' da lista
    strcpy(novo->frase,frase); //pegar o valor da variavel da função e copiar para a variavel da lista
    novo->prox = NULL; //como o novo será o ultimo valor da lista tem que colocar que o prox sera null para saber quando é o fim da lista

    if(*lista == NULL){ //caso seja o primeiro elemento o endereço de memoria da lista recebe a nova informação do struct 'no'
        *lista = novo;
    }else{
        No *atual = *lista; //casa não seja o primeiro ele percorre a lista até o final e coloca a nova informação por ultimo
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

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

void duplica_lista(No *lista){
    No* atual = lista;
    while(atual != NULL){
        No* novo = (No*)malloc(sizeof(No));
        strcpy(novo->frase, atual->frase);
        novo ->prox = atual->prox;
        atual->prox = novo;
        atual = novo->prox;
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
        adicionar_no(&lista,frase);
    }

    imprimir_lista(lista);
    liberar_lista(lista);

    return 0;
}