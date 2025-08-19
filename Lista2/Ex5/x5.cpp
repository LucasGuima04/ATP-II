#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    char linha[256];
    char copia_linha[256];
    char palavra[256];
    char *token;
    char *delimitador = " \t\n,.!?";
    arquivo = fopen("texto.txt","r");

    if(arquivo == NULL){
        printf("Erro ao iniciar o arquivo!");
        exit(1);
    }


    printf("Digite a palavra que procura: \n");
    gets(palavra);

    printf("\nBuscando por '%s' no arquivo...\n\n", palavra);
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        strcpy(copia_linha, linha);
        
        token = strtok(copia_linha, delimitador);
        
        // Loop interno para percorrer os tokens da linha
        while (token != NULL) {
            // Compara o token com a palavra buscada, ignorando maiúsculas/minúsculas
            if (strcasecmp(token, palavra) == 0) {
                // Se a palavra for encontrada, imprime a linha original
                printf("Palavra encontrada!\nLinha: %s", linha);
                break; // Sai do loop interno e vai para a próxima linha do arquivo
            }
            
            // Pega o próximo token da linha
            token = strtok(NULL, delimitador);
        }
    }
    fclose(arquivo);
    return 0;
}