#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[100];
    int nMatricula;
    struct no *prox;
} No;

int num = 1;

void adicionar_no(No **lista,char nome[100]){
    if(num>10){
        printf("Numero maximo de matriculas (10) atingido!\n");
        return;
    }
    struct no *novo = (No*)malloc(sizeof(No)); //Alocar na memoria o espaço para o novo 'bloco' da lista
    if(novo == NULL){ //verificar se "novo" foi alocado com sucesso
        printf("Erro ao alocar memoria!\n");
        return;
    }
    strcpy(novo->nome,nome); //pegar o valor da variavel da função e copiar para a variavel da lista
    novo->nMatricula = num;
    novo->prox = NULL; //como o novo será o ultimo valor da lista tem que colocar que o prox sera null para saber quando é o fim da lista
    
    num++;

    if(*lista == NULL){ //caso seja o primeiro elemento o endereço de memoria da lista recebe a nova informação do struct 'no'
        *lista = novo;
    }else{
        struct no *atual = *lista; //casa não seja o primeiro ele percorre a lista até o final e coloca a nova informação por ultimo
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void liberar_lista(No *lista){
    struct no* atual = lista;
    while(atual->prox != NULL){
        struct no *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

void imprimir_lista(No *lista){
    No* atual = lista;
    printf("---------Lista---------\n");
    while (atual != NULL){
        printf("N: %-2d Nome:%s\n",atual->nMatricula,atual->nome);
        atual = atual->prox;
    }
    printf("\n");
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
        adicionar_no(&lista, nome);
        printf("\n");
        break;
    case 2:
        imprimir_lista(lista);
        break;
    case 3:
        liberar_lista(lista);
        printf("Sucesso!");
        break;
    }
    }while(opc != 3);

    return 0;
}