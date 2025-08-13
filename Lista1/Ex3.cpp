#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char frase[100];

    printf("Digite uma frase: \n");
    gets(frase);

    int tamanho = strlen(frase);
    frase[tamanho] = tolower(frase[tamanho]);

    int contador = 0 ;
    for(int i=0;i<=tamanho;i++){
        if(frase[i] == 'a'|| frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o'|| frase[i] == 'u'){
            contador++;
        }
    }

    printf("A frase tem %d vogais!",contador);

    return 0;
}
