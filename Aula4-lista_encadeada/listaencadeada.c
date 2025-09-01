#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor[100];
    struct no *proximo;
} No;

No* iniciar_lista() {
    return NULL;
}

void adicionar_no(No **lista, char valor[100]) {
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->valor, valor);
    novo->proximo = NULL;

    // Se a lista está vazia, o novo nó se torna o primeiro.
    if (*lista == NULL) {
        *lista = novo;
    } else {
        // Se não, percorre a lista até o final para adicionar o novo nó.
        No *atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Imprimir agora percorre a lista até o final.
void imprimir_lista(No *lista) {
    if (lista == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("--- Conteudo da Lista ---\n");
    No *atual = lista;
    while (atual != NULL) {
        printf("- %s\n", atual->valor);
        atual = atual->proximo;
    }
    printf("-------------------------\n");
}

void liberar_lista_nova(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}


int main() {
    No* minha_lista = iniciar_lista(); // minha_lista agora é NULL

    adicionar_no(&minha_lista, "Abacaxi");
    adicionar_no(&minha_lista, "Banana");
    adicionar_no(&minha_lista, "Cereja");

    imprimir_lista(minha_lista);
    
    liberar_lista_nova(minha_lista);

    return 0;
}