#include <stdio.h>
#include <string.h>

void inverterStringRecursivo(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    inverterStringRecursivo(str, inicio + 1, fim - 1);
}

int main() {
    // Definimos uma string com tamanho suficiente para o exemplo
    char minhaString[100] = "Exemplo de Recursao";

    printf("--- Inversor de String (Recursivo In-Place) ---\n");

    // 1. Mostrar a string original antes da modificação
    printf("String ANTES: \"%s\"\n", minhaString);

    // 2. Calcular os índices iniciais
    // O índice de início é 0 (primeiro caracter).
    // O índice de fim é o tamanho da string menos 1 (último caracter visível).
    // Usamos strlen() para obter o tamanho atual da string.
    int tamanho = strlen(minhaString);
    
    // Só chamamos a inversão se a string tiver conteúdo
    if (tamanho > 0) {
        inverterStringRecursivo(minhaString, 0, tamanho - 1);
    }

    // 3. Mostrar a string após a modificação recursiva
    printf("String DEPOIS: \"%s\"\n", minhaString);

    return 0;
}