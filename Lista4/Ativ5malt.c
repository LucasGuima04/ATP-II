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

void excluir_aluno(No** lista, int matricula){
    No* atual = *lista;
    No* anterior = NULL;

    // 1. Percorre a lista até encontrar o aluno ou chegar ao fim.
    while(atual != NULL && atual->nMatricula != matricula){
        anterior = atual;
        atual = atual->prox;
    }

    // 2. Se 'atual' for NULL, o aluno não foi encontrado.
    if(atual == NULL){
        printf("\nAluno com matricula %d nao encontrado.\n\n", matricula);
        return; // Sai da função
    }

    // 3. Se 'anterior' for NULL, significa que o nó a ser removido é o primeiro.
    if(anterior == NULL){
        *lista = atual->prox; // A lista agora começa no próximo elemento.
    } else {
        // 4. Se for um nó do meio ou do fim, o anterior aponta para o próximo do atual.
        anterior->prox = atual->prox;
    }

    // 5. Libera a memória do nó removido.
    free(atual);
    printf("\nAluno com matricula %d removido com sucesso!\n\n", matricula);
}

int main(){
    No *lista = NULL;
    int opc = 0;
    char nome[100];
    int matricula = 0;
    do{
    printf("Escolha a opcao desejada:\n");
    printf("(1) Adicionar aluno\n");
    printf("(2) Imprimir Lista\n");
    printf("(3) Remover aluno\n");
    printf("(4) Finalizar\n");
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
        printf("Digite o n de matricula do aluno: ");
        scanf("%d",&matricula);
        excluir_aluno(&lista,matricula);
        break;
    case 4:
        liberar(lista);
        printf("Sucesso!");
        break;
    }
    }while(opc != 4);

    return 0;
}
