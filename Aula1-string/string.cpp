#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca de string

int main(){
    char nome[] = {'l','u','c','a','s','\0'};
    char nome2[] = "Lucas";

    char vet1[10],vet2[10];
    strcpy(vet1,"Lucas");
    strcpy(vet1,vet2);

    //scanf lê até o espaço, gets lê até o final da string

    //copiar
    strcpy(vet1,vet2);
    strncpy(vet1,vet2,1); //n primeiros

    //concatenar
    strcat(vet1,vet2);

    //comparar
    strcmp(vet1,vet2);
}