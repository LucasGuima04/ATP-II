#include <stdio.h>


double soma_serie(int n) {
    // --- CASO BASE ---
    // Quando n é 1, chegámos ao primeiro termo da série.
    if (n == 1) {
        return 1.0;
    }

    // --- PASSO RECURSIVO ---
    // Se 'n' é par, somamos o inverso de n (+ 1.0/n) ao resultado anterior.
    if (n % 2 == 0) {
        return soma_serie(n - 1) + 1.0 / n;
    }
    // Se 'n' é ímpar (e maior que 1), subtraímos o inverso de n (- 1.0/n).
    else {
        return soma_serie(n - 1) - 1.0 / n;
    }
}

// Função main para testar (opcional, mas recomendada para veres a funcionar)
int main() {
    int n_termos;
    printf("Digite o valor de n: ");
    scanf("%d", &n_termos);

    if (n_termos >= 1) {
        double resultado = soma_serie(n_termos);
        printf("A soma dos %d primeiros termos é: %f\n", n_termos, resultado);
    } else {
        printf("Por favor, insira um n maior ou igual a 1.\n");
    }

    return 0;
}