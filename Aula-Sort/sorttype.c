
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

void SelectSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        
        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void Merge(int X[], int l, int m, int n, int Z[]) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= n) {
        if (X[i] <= X[j]) {
            Z[k] = X[i];
            i++;
        } else {
            Z[k] = X[j];
            j++;
        }
        k++;
    }

    if (i > m) {
        while (j <= n) {
            Z[k] = X[j];
            j++;
            k++;
        }
    } else {
        while (i <= m) {
            Z[k] = X[i];
            i++;
            k++;
        }
    }
}

void MPasso(int X[], int Y[], int n, int l) {
    int i = 0;
    while (i <= n - 2 * l) {
        Merge(X, i, i + l - 1, i + 2 * l - 1, Y);
        i = i + 2 * l;
    }

    if (i + l < n) {
        Merge(X, i, i + l - 1, n - 1, Y);
    } else {
        for (int j = i; j < n; j++) {
            Y[j] = X[j];
        }
    }
}

void MSort(int X[], int n) {
    int l = 1;
    int* Y = (int*)malloc(n * sizeof(int));
    if (Y == NULL) {
        printf("Falha na alocacao de memoria\n");
        return;
    }

    while (l < n) {
        MPasso(X, Y, n, l);
        l = 2 * l;
        if (l >= n) {
            for(int i=0; i < n; i++)
                X[i] = Y[i];
            break;
        }
        MPasso(Y, X, n, l);
        l = 2 * l;
    }
    
    free(Y);
}

int main() {
    srand(time(NULL));
    const int N = 15;
    int arr1[N];
    int arr2[N];

    for (int i = 0; i < N; i++) {
        int randVal = rand() % 100;
        arr1[i] = randVal;
        arr2[i] = randVal;
    }

    printf("--- Teste 1: Conjunto Aleatorio ---\n");
    printf("Original: \n");
    printArray(arr1, N);

    printf("\nTestando SelectSort:\n");
    SelectSort(arr1, N);
    printArray(arr1, N);

    printf("\nTestando Two-way MergeSort:\n");
    MSort(arr2, N);
    printArray(arr2, N);

    printf("\n--- Teste 2: Conjunto Ja Ordenado ---\n");
    int sortedArr[N];
    for(int i = 0; i < N; i++) sortedArr[i] = i + 1;
    
    memcpy(arr1, sortedArr, sizeof(sortedArr));
    memcpy(arr2, sortedArr, sizeof(sortedArr));
    
    printf("Original: \n");
    printArray(arr1, N);

    printf("\nTestando SelectSort:\n");
    SelectSort(arr1, N);
    printArray(arr1, N);

    printf("\nTestando Two-way MergeSort:\n");
    MSort(arr2, N);
    printArray(arr2, N);
    
    printf("\n--- Teste 3: Conjunto Ordem Reversa ---\n");
    int reverseArr[N];
    for(int i = 0; i < N; i++) reverseArr[i] = N - i;

    memcpy(arr1, reverseArr, sizeof(reverseArr));
    memcpy(arr2, reverseArr, sizeof(reverseArr));

    printf("Original: \n");
    printArray(arr1, N);

    printf("\nTestando SelectSort:\n");
    SelectSort(arr1, N);
    printArray(arr1, N);

    printf("\nTestando Two-way MergeSort:\n");
    MSort(arr2, N);
    printArray(arr2, N);

    return 0;
}