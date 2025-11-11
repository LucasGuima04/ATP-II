#include <stdio.h>
#include <stdlib.h>

int potencia(int base,int expoente){
    if(expoente == 0){
        return 1;
    }else{
    return(base*potencia(base,expoente - 1));
    }
}

int main(){
    int res = potencia(10,3);

    printf("%d",res);
    return 0;
}