#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int num;
    printf ("qual o tamanho da sequencia de fibonacci: \n");
    scanf("%d",&num);
    printf("0 ");
    for(int i = 1; i<=num ;i++)
    printf("%d ",fibonacci(i));
}