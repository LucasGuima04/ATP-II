#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

struct no *questao3(struct no *L1, struct no *L2) {
    // Se a primeira lista for vazia, o resultado é a segunda lista.
    if (L1 == NULL) {
        return L2;
    }
    // Se a segunda lista for vazia, o resultado é a primeira lista.
    if (L2 == NULL) {
        return L1;
    }

    // Ponteiros para percorrer L1 e L2.
    struct no *p1 = L1;
    struct no *p2 = L2;

    // Ponteiros para guardar as próximas posições antes de "religar" os nós.
    struct no *prox1 = NULL;
    struct no *prox2 = NULL;

    // O loop continua enquanto ainda tivermos nós em AMBAS as listas para intercalar.
    while (p1 != NULL && p2 != NULL) {
        // 1. Guarda os próximos nós de cada lista.
        prox1 = p1->prox;
        prox2 = p2->prox;

        // 2. O próximo do nó atual de L1 aponta para o nó atual de L2.
        p1->prox = p2;
        
        // 3. Se o resto de L1 não for nulo, o próximo de L2 aponta para ele.
        //    Isso garante que, se L1 for a lista mais curta, não vamos
        //    ligar o último nó de L2 a um local inválido (NULL).
        if (prox1 != NULL) {
           p2->prox = prox1;
        }

        // 4. Avança os ponteiros para os próximos nós que devem ser processados.
        p1 = prox1;
        p2 = prox2;
    }

    // A nova lista começa em L1, então retornamos seu ponteiro original.
    return L1;
}