#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estrutura para representar um Hóspede
typedef struct hospede {
    char nome[100];
    float pesoEntrada;   // em gramas [cite: 6]
    float pesoSaida;     // em gramas [cite: 9]
    int diasTratamento;
    int caloriasDiarias; // Valor único que se repete para os dias
    int ficha;           // Número da ficha [cite: 8]
    bool alta;           // true se o paciente recebeu alta, false caso contrário 
    struct hospede *proximo;
} Hospede;

// Variáveis globais para gerenciar a lista e o contador
Hospede *head = NULL;
int numeroHospedes = 0;
const int MAX_HOSPEDES = 20; // Capacidade máxima de 20 internos 
int proximaFicha = 1; // A ordem de armazenamento do número da ficha começa em 1 [cite: 16]

// Função para cadastrar um novo hóspede 
void cadastrarHospede() {
    if (numeroHospedes >= MAX_HOSPEDES) {
        printf("Lotação máxima atingida. Não é possível cadastrar mais hóspedes.\n");
        return;
    }

    Hospede *novoHospede = (Hospede *)malloc(sizeof(Hospede));
    if (novoHospede == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    printf("--- Cadastro de Hóspede ---\n");

    printf("Nome: ");
    scanf(" %[^\n]", novoHospede->nome); // Lê a linha inteira, incluindo espaços

    printf("Peso ao entrar (g): ");
    scanf("%f", &novoHospede->pesoEntrada);

    printf("Qtde Dias Tratamento (max 30): ");
    scanf("%d", &novoHospede->diasTratamento);

    printf("Quantidade de calorias que podem ser ingeridas por dia: ");
    scanf("%d", &novoHospede->caloriasDiarias);

    // Inicialização dos dados
    novoHospede->ficha = proximaFicha++;
    novoHospede->pesoSaida = 0.0;
    novoHospede->alta = false;
    novoHospede->proximo = NULL;

    // Adiciona o novo hóspede ao final da lista
    if (head == NULL) {
        head = novoHospede;
    } else {
        Hospede *temp = head;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoHospede;
    }

    numeroHospedes++;
    printf("Hóspede '%s' cadastrado com sucesso. Ficha n° %d.\n", novoHospede->nome, novoHospede->ficha);
}

// Função para dar alta a um hóspede 
void darAlta() {
    int numeroFicha;
    printf("--- Dar Alta a Hóspede ---\n");
    printf("Digite o número da ficha do paciente: ");
    scanf("%d", &numeroFicha);

    Hospede *hospedeAtual = head;
    while (hospedeAtual != NULL && hospedeAtual->ficha != numeroFicha) {
        hospedeAtual = hospedeAtual->proximo;
    }

    if (hospedeAtual == NULL) {
        printf("Hóspede com ficha n° %d não encontrado.\n", numeroFicha);
    } else {
        if (hospedeAtual->alta) {
            printf("O hóspede com ficha n° %d já recebeu alta.\n", numeroFicha);
            return;
        }

        printf("Hóspede encontrado: %s\n", hospedeAtual->nome);
        printf("Digite o peso ao sair (g): ");
        scanf("%f", &hospedeAtual->pesoSaida);

        // Marca a ficha que o paciente teve alta 
        hospedeAtual->alta = true;

        // Calcular a perda de peso em quilos 
        float perdaPeso = (hospedeAtual->pesoEntrada - hospedeAtual->pesoSaida) / 1000.0;
        printf("O paciente perdeu %.2f kg.\n", perdaPeso);

        printf("Alta registrada para o hóspede com ficha n° %d.\n", numeroFicha);
    }
}

// Função para consultar os dados de um hóspede
void consultarHospede() {
    int numeroFicha;
    printf("--- Consultar Hóspede ---\n");
    printf("Digite o número da ficha do paciente: ");
    scanf("%d", &numeroFicha);

    Hospede *hospedeAtual = head;
    while (hospedeAtual != NULL && hospedeAtual->ficha != numeroFicha) {
        hospedeAtual = hospedeAtual->proximo;
    }

    if (hospedeAtual == NULL) {
        printf("Hóspede com ficha n° %d não encontrado.\n", numeroFicha);
    } else {
        printf("\n--- Dados do Hóspede (Ficha n° %d) ---\n", hospedeAtual->ficha);
        printf("Nome: %s\n", hospedeAtual->nome);
        printf("Peso ao entrar: %.2f g\n", hospedeAtual->pesoEntrada);
        printf("Peso ao sair: %.2f g\n", hospedeAtual->pesoSaida);
        printf("Qtde Dias Tratamento: %d dias\n", hospedeAtual->diasTratamento);
        printf("Calorias diárias: %d\n", hospedeAtual->caloriasDiarias);
        printf("Status: %s\n", hospedeAtual->alta ? "Com alta" : "Em tratamento");
        printf("------------------------------------------\n");
    }
}

// Função principal 
int main() {
    int opcao;

    do {
        printf("\n--- Spa Rei Momo - Menu Principal ---\n");
        printf("1. Cadastrar novo hóspede\n");
        printf("2. Dar alta a paciente\n");
        printf("3. Consultar hóspede por ficha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarHospede();
                break;
            case 2:
                darAlta();
                break;
            case 3:
                consultarHospede();
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4); // O programa deve permitir cadastrar ou dar baixa em pacientes enquanto o usuário não desejar encerrar a execução 

    // Libera a memória da lista encadeada antes de sair
    Hospede *hospedeAtual = head;
    Hospede *proximoHospede;
    while (hospedeAtual != NULL) {
        proximoHospede = hospedeAtual->proximo;
        free(hospedeAtual);
        hospedeAtual = proximoHospede;
    }

    return 0;
}