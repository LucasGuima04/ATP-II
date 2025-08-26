#include <stdio.h>
#include <stdlib.h>

int main(){
    struct no
    {
        int info;
        struct no *prox;
    };
    struct no *p;
    int valor;
    p = NULL;

    scanf("%d",&valor);

    if(p == NULL){
        p=(struct no *)malloc(sizeof(struct no));
    }
    p->info = valor;
    p->prox = NULL;

}