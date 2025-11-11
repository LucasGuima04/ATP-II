#include <stdio.h>
#include <stdlib.h>

int mdc(int a,int b){
    if (b == 0){
        return a;
    }else{
        return mdc(b,a%b);
    }
}

int mdcArray(int numeros[], int tamanho, int indice) {
    // --- CASO BASE ---
    if (indice == tamanho - 1) {
        return numeros[indice];
    }
    // --- PASSO RECURSIVO ---
    return mdc(numeros[indice], mdcArray(numeros, tamanho, indice + 1));
}

int main() {
    int quantidade;

    printf("--- Calculadora de MDC para N numeros (Recursiva) ---\n");
    printf("Quantos numeros deseja inserir? (Minimo 2): ");
    scanf("%d", &quantidade);

    if (quantidade < 2) {
        printf("Precisa de pelo menos 2 numeros para calcular o MDC.\n");
        return 1; // Sai do programa com erro
    }

    // Cria um array com o tamanho que o utilizador pediu (VLA - Variable Length Array)
    // Nota: Em compiladores C muito antigos, isto pode não funcionar.
    // Nesses casos, teria de definir um tamanho fixo máximo, ex: int numeros[100];
    int numeros[quantidade];

    for (int i = 0; i < quantidade; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Chamamos a função começando do índice 0
    int resultado_final = mdcArray(numeros, quantidade, 0);

    printf("O MDC de todos os numeros inseridos é: %d\n", resultado_final);

    return 0;
}