#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void SelectSort(int arr[], int n, int *steps) {
    int i, j, min_idx;
    *steps = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*steps)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        
        if (min_idx != i) {
            (*steps)++;
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

void Merge(int X[], int l, int m, int n, int Z[], int *steps) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= n) {
        (*steps)++;
        if (X[i] <= X[j]) {
            Z[k] = X[i];
            i++;
        } else {
            Z[k] = X[j];
            j++;
        }
        (*steps)++;
        k++;
    }

    if (i > m) {
        while (j <= n) {
            Z[k] = X[j];
            (*steps)++;
            j++;
            k++;
        }
    } else {
        while (i <= m) {
            Z[k] = X[i];
            (*steps)++;
            i++;
            k++;
        }
    }
}

void MPasso(int X[], int Y[], int n, int l, int *steps) {
    int i = 0;
    while (i <= n - 2 * l) {
        Merge(X, i, i + l - 1, i + 2 * l - 1, Y, steps);
        i = i + 2 * l;
    }

    if (i + l < n) {
        Merge(X, i, i + l - 1, n - 1, Y, steps);
    } else {
        for (int j = i; j < n; j++) {
            Y[j] = X[j];
            (*steps)++;
        }
    }
}

void MSort(int X[], int n, int *steps) {
    int l = 1;
    int* Y = (int*)malloc(n * sizeof(int));
    if (Y == NULL) {
        printf("Falha na alocacao de memoria\n");
        return;
    }
    *steps = 0;
    
    int* A = X;
    int* B = Y;

    while (l < n) {
        MPasso(A, B, n, l, steps);
        l = 2 * l;
        
        int* temp = A;
        A = B;
        B = temp;
    }
    
    if (A != X) {
        for (int i = 0; i < n; i++) {
            X[i] = A[i];
            (*steps)++;
        }
    }
    
    free(Y);
}

int main() {
    srand(time(NULL));
    const int N = 15;
    int arr1[N];
    int arr2[N];
    int steps;

    for (int i = 0; i < N; i++) {
        int randVal = rand() % 100;
        arr1[i] = randVal;
        arr2[i] = randVal;
    }

    printf("--- Teste 1: Conjunto Aleatorio ---\n");
    printf("Original: \n");
    printArray(arr1, N);

    printf("\nTestando SelectSort:\n");
    SelectSort(arr1, N, &steps);
    printArray(arr1, N);
    printf("Passos (SelectSort): %d\n", steps);

    printf("\nTestando Two-way MergeSort:\n");
    MSort(arr2, N, &steps);
    printArray(arr2, N);
    printf("Passos (MergeSort): %d\n", steps);

    printf("\n--- Teste 2: Conjunto Ja Ordenado ---\n");
    int sortedArr[N];
    for(int i = 0; i < N; i++) sortedArr[i] = i + 1;
    
    memcpy(arr1, sortedArr, sizeof(sortedArr));
    memcpy(arr2, sortedArr, sizeof(sortedArr));
    
    printf("Original: \n");
    printArray(arr1, N);

    printf("\nTestando SelectSort:\n");
    SelectSort(arr1, N, &steps);
    printArray(arr1, N);
    printf("Passos (SelectSort): %d\n", steps);

    printf("\nTestando Two-way MergeSort:\n");
    MSort(arr2, N, &steps);
    printArray(arr2, N);
    printf("Passos (MergeSort): %d\n", steps);
    
    printf("\n--- Teste 3: Conjunto Ordem Reversa ---\n");
    int reverseArr[N];
    for(int i = 0; i < N; i++) reverseArr[i] = N - i;

    memcpy(arr1, reverseArr, sizeof(reverseArr));
    memcpy(arr2, reverseArr, sizeof(reverseArr));

    printf("Original: \n");
    printArray(arr1, N);

    printf("\nTestando SelectSort:\n");
    SelectSort(arr1, N, &steps);
    printArray(arr1, N);
    printf("Passos (SelectSort): %d\n", steps);

    printf("\nTestando Two-way MergeSort:\n");
    MSort(arr2, N, &steps);
    printArray(arr2, N);
    printf("Passos (MergeSort): %d\n", steps);

    return 0;
}