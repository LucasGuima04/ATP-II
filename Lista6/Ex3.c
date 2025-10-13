#include <stdlib.h>
#include <stdio.h>

int somaInteiros(int n){
    if(n<1){
        printf("Erro! Use um numero inteiro positivo.\n");
        exit(1);
    } else if (n == 1){
        return n;
    }
    return(n+somaInteiros(n-1));
}

int main(){
    int n,total;
    printf("Digite um bagulho ae: ");
    scanf("%d",&n);

    total=somaInteiros(n);
    printf("A soma: %d",total);

    return 0;
}