#include <stdio.h>

// Função recursiva para resolver o problema da Torre de Hanói
void torreDeHanoi(int n, char pino_origem, char pino_destino, char pino_auxiliar) {
    // Caso base: se houver apenas um disco, mova-o diretamente
    if (n == 1) {
        printf("Mover disco 1 do pino %c para o pino %c\n", pino_origem, pino_destino);
        return; // Encerra a chamada da função
    }

    // Passo 1: Mover n-1 discos do pino de origem para o pino auxiliar,
    // usando o pino de destino como auxiliar temporário.
    torreDeHanoi(n - 1, pino_origem, pino_auxiliar, pino_destino);

    // Passo 2: Mover o disco maior (n) que restou do pino de origem para o destino.
    printf("Mover disco %d do pino %c para o pino %c\n", n, pino_origem, pino_destino);

    // Passo 3: Mover os n-1 discos do pino auxiliar para o pino de destino,
    // usando o pino de origem como auxiliar temporário.
    torreDeHanoi(n - 1, pino_auxiliar, pino_destino, pino_origem);
}

// Função principal que inicia o programa
int main() {
    int numeroDeDiscos;

    // Pede ao usuário para inserir o número de discos
    printf("Digite o numero de discos: ");
    scanf("%d", &numeroDeDiscos);

    printf("\nOs passos para resolver a Torre de Hanoi com %d discos sao:\n", numeroDeDiscos);
    
    // Chama a função recursiva com os pinos iniciais
    // A = Origem, C = Destino, B = Auxiliar
    torreDeHanoi(numeroDeDiscos, 'A', 'C', 'B');

    return 0;
}