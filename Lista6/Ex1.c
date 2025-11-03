#include <stdio.h>
#include <stdlib.h>

void printDigitos(int num){
    if(num<10){
        printf("%d",num);
        return;
    }
    printDigitos(num/10);
    printf("|");
    printf("%d",num%10);
}

int main(){
    int num;
    scanf("%d",&num);
    printDigitos(num);

    return 0;
}