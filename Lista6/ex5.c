#include <stdio.h>
#include <stdlib.h>

int verifyPrimo(int n,int div){
    //0 -> não é primo
    //1 -> é primo
    if(n<=1){
        return 0;
    }
    if(div*div > n){
        return 1;
    }
    if(n % div == 0){
        return 0;
    }
    return verifyPrimo(n, div+1);
}

int main(){
    if(verifyPrimo(9763,2)){
        printf("e primo\n");
    }else{
        printf("nao primo\n");
    }
    return 0;
}