#include <stdio.h>
#include <stdlib.h>

int mdc(int a,int b){
    if (b == 0){
        return a;
    }else{
        return mmc(b,a%b);
    }
}

int main(){
    printf("o mmc de 60 e 72: %d",mmc(60,72));
    return 0;
}