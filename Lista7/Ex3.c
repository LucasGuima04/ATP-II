#include <stdio.h>

/*
 * Função de Ackermann Recursiva.
 * Tradução direta das regras matemáticas.
 */
int ackermann(int m, int n) {
    // Regra 1: Se m é zero, retorna n + 1
    if (m == 0) {
        return n + 1;
    }
    // Regra 2: Se m > 0 e n é zero, retorna A(m-1, 1)
    else if (n == 0) {
        return ackermann(m - 1, 1);
    }
    // Regra 3: Se m > 0 e n > 0, retorna A(m-1, A(m, n-1))
    else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int m, n;

    printf("--- Função de Ackermann ---\n");
    printf("AVISO: Valores de m >= 4 podem travar o programa!\n");
    printf("Digite o valor de m (recomendado 0 a 3): ");
    scanf("%d", &m);
    printf("Digite o valor de n (recomendado 0 a 10): ");
    scanf("%d", &n);

    if (m < 0 || n < 0) {
        printf("Por favor, usa apenas números não negativos.\n");
    } else {
        printf("Calculando... (isto pode demorar para m=3, n>10)\n");
        int resultado = ackermann(m, n);
        printf("Resultado de A(%d, %d) = %d\n", m, n, resultado);
    }

    return 0;
}