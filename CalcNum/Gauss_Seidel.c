/**
 * ================================================
 * Resolucao de Sistemas Lineares com Gauss-Seidel
 * ================================================
 *
 * Como o programa funciona:
 *
 * 1.  Leitura dos Dados: O programa inicia lendo um arquivo "equacoes.txt". A
 * primeira linha deve conter um inteiro 'n', que e o numero de equacoes.
 * As 'n' linhas seguintes devem conter os coeficientes da matriz aumentada
 * [A|b], onde cada linha representa uma equacao.
 *
 * 2.  Alocacao Dinamica: Com base no valor 'n', o programa aloca memoria
 * dinamicamente para todas as matrizes (Aumentada, L, R) e vetores
 * (b_normalizado, solucoes) necessarios. Isso torna o codigo flexivel para
 * sistemas de qualquer tamanho.
 *
 * 3.  Geracao do Relatorio: Um arquivo "resultado.txt" e criado para documentar
 * todo o processo de resolucao. O relatorio e dividido em 4 passos:
 *
 * - Passo 1: Exibe a Matriz Aumentada original lida do arquivo.
 *
 * - Passo 2: Mostra as matrizes L, R e o vetor b' que sao usados na formula
 * iterativa. Estes sao calculados dividindo os elementos da matriz
 * original pelos elementos da diagonal principal.
 *
 * - Passo 3: Apresenta as equacoes de iteracao de forma clara, mostrando
 * como cada variavel x_i sera calculada em cada passo.
 *
 * - Passo 4: Executa o processo iterativo de Gauss-Seidel. Comecando com
 * uma solucao inicial de zeros, o programa calcula novas aproximacoes
 * em cada iteracao, mostrando o vetor solucao e o erro relativo.
 *
 * 4.  Criterio de Parada: As iteracoes continuam ate que o erro relativo,
 * calculado pela norma do maximo (||x_k - x_{k-1}|| / ||x_k||), seja
 * menor que a tolerancia definida (5 * 10^-3).
 *
 * 5.  Limpeza: Ao final da execucao, toda a memoria alocada dinamicamente
 * e liberada para evitar vazamentos de memoria.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // Para a funcao fabs() que calcula o valor absoluto
#include <string.h> // Para a funcao memcpy()

// Funcao para imprimir uma matriz formatada no arquivo de saida
void imprimirMatriz(FILE* saida, float** matriz, int linhas, int colunas, const char* titulo);

// Funcao para imprimir um vetor formatado no arquivo de saida
void imprimirVetor(FILE* saida, float* vetor, int n, const char* titulo);

// Funcao para calcular a norma do maximo (norma infinita) de um vetor
float calcularNormaMaximo(float* vetor, int n);

// --- Funcao Principal ---
int main() {
    FILE* arquivoEntrada = fopen("equacoes.txt", "r");
    FILE* arquivoSaida = fopen("resultado.txt", "w");

    // Verifica se os arquivos foram abertos com sucesso
    if (arquivoEntrada == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'equacoes.txt'.\n");
        return 1;
    }
    if (arquivoSaida == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo 'resultado.txt'.\n");
        fclose(arquivoEntrada);
        return 1;
    }

    // --- Leitura do Tamanho do Sistema e Alocacao de Memoria ---
    int n;
    fscanf(arquivoEntrada, "%d", &n);

    // Alocacao dinamica da matriz aumentada [A|b]
    float** matrizAumentada = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        matrizAumentada[i] = (float*)malloc((n + 1) * sizeof(float));
    }

    // Leitura dos coeficientes da matriz aumentada
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            fscanf(arquivoEntrada, "%f", &matrizAumentada[i][j]);
        }
    }

    // --- PASSO 1: Mostrar a matriz aumentada original ---
    imprimirMatriz(arquivoSaida, matrizAumentada, n, n + 1, "--- Passo 1: Matriz Aumentada Original [A|b] ---");

    // --- PASSO 2: Mostrar as matrizes L, R e o vetor b normalizado ---
    fprintf(arquivoSaida, "\n--- Passo 2: Matrizes L, R e Vetor b' (normalizados pela diagonal principal) ---\n");

    // Alocacao das matrizes L e R e do vetor b'
    float** matrizL = (float**)calloc(n, sizeof(float*));
    float** matrizR = (float**)calloc(n, sizeof(float*));
    float* vetorB_norm = (float*)calloc(n, sizeof(float));
    for (int i = 0; i < n; i++) {
        matrizL[i] = (float*)calloc(n, sizeof(float));
        matrizR[i] = (float*)calloc(n, sizeof(float));
    }
    
    // Preenchimento das matrizes L, R e do vetor b'
    for (int i = 0; i < n; i++) {
        // O vetor b' e o vetor b dividido pela diagonal principal de A
        vetorB_norm[i] = matrizAumentada[i][n] / matrizAumentada[i][i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // Diagonal principal e zero em L e R
            float valorNormalizado = matrizAumentada[i][j] / matrizAumentada[i][i];
            if (j < i) { // Parte triangular inferior -> Matriz L
                matrizL[i][j] = valorNormalizado;
            } else { // Parte triangular superior -> Matriz R
                matrizR[i][j] = valorNormalizado;
            }
        }
    }

    imprimirMatriz(arquivoSaida, matrizL, n, n, "Matriz L");
    imprimirMatriz(arquivoSaida, matrizR, n, n, "Matriz R");
    imprimirVetor(arquivoSaida, vetorB_norm, n, "Vetor b'");

    // --- PASSO 3: Mostrar as equacoes iterativas ---
    fprintf(arquivoSaida, "\n--- Passo 3: Equacoes Iterativas de Gauss-Seidel ---\n");
    fprintf(arquivoSaida, "A formula para cada variavel x[i] na iteracao (k) e:\n\n");

    for (int i = 0; i < n; i++) {
        fprintf(arquivoSaida, "x%d(k) = (1 / %.5f) * [ %.5f ", i + 1, matrizAumentada[i][i], matrizAumentada[i][n]);
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            // No metodo de Gauss-Seidel, usamos os valores ja atualizados (k) para j < i
            // e os valores da iteracao anterior (k-1) para j > i.
            const char* iteracao = (j < i) ? "(k)" : "(k-1)";
            fprintf(arquivoSaida, "- (%.5f * x%d%s) ", matrizAumentada[i][j], j + 1, iteracao);
        }
        fprintf(arquivoSaida, "]\n");
    }

    // --- PASSO 4: Processo Iterativo de Gauss-Seidel ---
    fprintf(arquivoSaida, "\n--- Passo 4: Sequencia de Aproximacoes da Solucao ---\n\n");
    
    // Alocacao dos vetores para a solucao
    float* x_atual = (float*)calloc(n, sizeof(float));
    float* x_anterior = (float*)calloc(n, sizeof(float));
    float* diferenca = (float*)calloc(n, sizeof(float));

    float erro_relativo = 1.0; // Inicia com um erro grande para garantir a entrada no loop
    const float tolerancia = 5e-4; // Criterio de parada: 5 * 10^-4
    int iteracao = 0;
    int max_iteracoes = 100; // Um limite para evitar loops infinitos

    fprintf(arquivoSaida, "%-10s", "Iteracao");
    for(int i = 0; i < n; i++){
        fprintf(arquivoSaida, "%-15s", "x_i");
    }
    fprintf(arquivoSaida, "%-20s\n", "Erro Relativo");
    
    // Loop principal das iteracoes
    while (erro_relativo > tolerancia && iteracao < max_iteracoes) {
        iteracao++;
        // Copia a solucao atual para o vetor anterior antes de calcular a nova
        memcpy(x_anterior, x_atual, n * sizeof(float));

        // Calcula os novos valores de x
        for (int i = 0; i < n; i++) {
            float soma = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    soma += matrizAumentada[i][j] * x_atual[j];
                }
            }
            x_atual[i] = (matrizAumentada[i][n] - soma) / matrizAumentada[i][i];
        }

        // Calcula o erro relativo
        for (int i = 0; i < n; i++) {
            diferenca[i] = x_atual[i] - x_anterior[i];
        }

        float norma_diff = calcularNormaMaximo(diferenca, n);
        float norma_atual = calcularNormaMaximo(x_atual, n);
        
        // Evita divisao por zero se a solucao for o vetor nulo
        if (norma_atual < 1e-9) { 
            erro_relativo = norma_diff;
        } else {
            erro_relativo = norma_diff / norma_atual;
        }
        
        // Imprime os resultados da iteracao atual
        fprintf(arquivoSaida, "%-10d", iteracao);
        for(int i = 0; i < n; i++){
            fprintf(arquivoSaida, "%-15.5f", x_atual[i]);
        }
        fprintf(arquivoSaida, "%-20.5f\n", erro_relativo);
    }
    
    if (iteracao == max_iteracoes) {
        fprintf(arquivoSaida, "\nAVISO: O metodo nao convergiu em %d iteracoes.\n", max_iteracoes);
    }


    // --- Liberacao da Memoria Alocada ---
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    for (int i = 0; i < n; i++) {
        free(matrizAumentada[i]);
        free(matrizL[i]);
        free(matrizR[i]);
    }
    free(matrizAumentada);
    free(matrizL);
    free(matrizR);
    free(vetorB_norm);
    free(x_atual);
    free(x_anterior);
    free(diferenca);

    printf("Processo concluido! Verifique o arquivo 'resultado.txt' para o passo a passo da solucao.\n");

    return 0;
}

/**
 * Imprime uma matriz no arquivo de saida com formatacao.
 * @param saida Ponteiro para o arquivo de saida.
 * @param matriz A matriz a ser impressa.
 * @param linhas Numero de linhas da matriz.
 * @param colunas Numero de colunas da matriz.
 * @param titulo Um titulo para a matriz.
 */
void imprimirMatriz(FILE* saida, float** matriz, int linhas, int colunas, const char* titulo) {
    fprintf(saida, "\n%s:\n", titulo);
    for (int i = 0; i < linhas; i++) {
        fprintf(saida, "| ");
        for (int j = 0; j < colunas; j++) {
            fprintf(saida, "%10.5f ", matriz[i][j]);
        }
        fprintf(saida, "|\n");
    }
}

/**
 * Imprime um vetor no arquivo de saida com formatacao.
 * @param saida Ponteiro para o arquivo de saida.
 * @param vetor O vetor a ser impresso.
 * @param n O tamanho do vetor.
 * @param titulo Um titulo para o vetor.
 */
void imprimirVetor(FILE* saida, float* vetor, int n, const char* titulo) {
    fprintf(saida, "\n%s:\n", titulo);
    for (int i = 0; i < n; i++) {
        fprintf(saida, "| %10.5f |\n", vetor[i]);
    }
}

/**
 * Calcula a norma do maximo (infinita) de um vetor.
 * A norma do maximo e simplesmente o maior valor absoluto entre os elementos do vetor.
 * @param vetor O vetor para o qual a norma sera calculada.
 * @param n O tamanho do vetor.
 * @return O valor da norma do maximo.
 */
float calcularNormaMaximo(float* vetor, int n) {
    float max = 0.0;
    for (int i = 0; i < n; i++) {
        if (fabs(vetor[i]) > max) {
            max = fabs(vetor[i]);
        }
    }
    return max;
}