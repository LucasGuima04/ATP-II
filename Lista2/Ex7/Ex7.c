#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOME 50
#define ARQUIVO_ALUNOS "alunos.bin"


struct Aluno {
    char nome[MAX_NOME];
    int idade;
    float nota;
};
void adicionarAluno() {
    struct Aluno aluno;
    FILE *arquivo;
    printf("Nome do aluno: ");
    scanf(" %[^\n]", aluno.nome);;
    printf("Idade: ");
    scanf("%d", &aluno.idade);
    printf("Nota: ");
    scanf("%f", &aluno.nota);
    arquivo = fopen(ARQUIVO_ALUNOS, "ab");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fwrite(&aluno, sizeof(struct Aluno), 1, arquivo);
    fclose(arquivo);
    printf("Aluno adicionado com sucesso!\n");
}
void listarAlunos() {
    struct Aluno aluno;
    FILE *arquivo;
    arquivo = fopen(ARQUIVO_ALUNOS, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }  
    printf("\nLista de Alunos:\n");
    while (fread(&aluno, sizeof(struct Aluno), 1, arquivo) == 1) {
        printf("Nome: %s, Idade: %d, Nota: %.2f\n", aluno.nome,
        aluno.idade, aluno.nota);
    }
    fclose(arquivo);
}
void buscarAluno() {
    struct Aluno aluno;
    FILE *arquivo;
    char nomeBusca[MAX_NOME];
    int encontrado = 0;
    printf("Digite o nome do aluno para buscar: ");
    scanf(" %[^\n]", nomeBusca);
    arquivo = fopen(ARQUIVO_ALUNOS, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    while (fread(&aluno, sizeof(struct Aluno), 1, arquivo) == 1) {
        if (strcmp(aluno.nome, nomeBusca) == 0) {
            printf("Aluno encontrado:\n");
            printf("Nome: %s, Idade: %d, Nota: %.2f\n", aluno.nome,
            aluno.idade, aluno.nota);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno nao encontrado.\n");
    }
    fclose(arquivo);
}
int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Buscar aluno\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
            adicionarAluno();
            break;
            case 2:
            listarAlunos();
            break;
            case 3:
            buscarAluno();
            break;
            case 4:
            printf("Saindo...\n");
            break;
            default:
            printf("Opcao invalida!\n");
        }
} while (opcao != 4);
    return 0;
}