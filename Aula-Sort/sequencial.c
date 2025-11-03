#include <stdio.h>
#include <stdlib.h>

#define N 20

int sequentialSearch(int arr[], int n, int key, int *steps) {
    *steps = 0;
    for (int i = 0; i < n; i++) {
        (*steps)++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int sequentialSearchOrdered(int arr[], int n, int key, int *steps) {
    *steps = 0;
    for (int i = 0; i < n; i++) {
        (*steps)++;
        if (arr[i] == key) {
            return i;
        }
        
        (*steps)++;
        if (arr[i] > key) {
            return -1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key, int *steps) {
    *steps = 0;
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        (*steps)++;
        if (arr[mid] == key) {
            return mid;
        }
        
        (*steps)++;
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    int unsortedArr[N] = {150, 88, 220, 55, 421, 199, 300, 22, 111, 350, 277, 18, 180, 251, 400, 77, 120, 333, 200, 101};
    int sortedArr[N]   = {18, 22, 55, 77, 88, 101, 111, 120, 150, 180, 199, 200, 220, 251, 277, 300, 333, 350, 400, 421};
    
    int key;
    int steps;
    int result;

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &key);
    printf("\n");

    printf("--- Testando Busca Sequencial (Lista Desordenada) ---\n");
    printf("Vetor: ");
    printArray(unsortedArr, N);
    result = sequentialSearch(unsortedArr, N, key, &steps);
    if (result != -1) {
        printf("Numero %d encontrado na posicao %d em %d passos.\n", key, result, steps);
    } else {
        printf("Numero %d NAO encontrado. Total de %d passos.\n", key, steps);
    }
    printf("\n");

    printf("--- Testando Busca Sequencial (Lista Ordenada) ---\n");
    printf("Vetor: ");
    printArray(sortedArr, N);
    result = sequentialSearchOrdered(sortedArr, N, key, &steps);
    if (result != -1) {
        printf("Numero %d encontrado na posicao %d em %d passos.\n", key, result, steps);
    } else {
        printf("Numero %d NAO encontrado. Total de %d passos.\n", key, steps);
    }
    printf("\n");

    printf("--- Testando Busca Binaria (Lista Ordenada) ---\n");
    printf("Vetor: ");
    printArray(sortedArr, N);
    result = binarySearch(sortedArr, N, key, &steps);
    if (result != -1) {
        printf("Numero %d encontrado na posicao %d em %d passos.\n", key, result, steps);
    } else {
        printf("Numero %d NAO encontrado. Total de %d passos.\n", key, steps);
    }
    printf("\n");

    return 0;
}