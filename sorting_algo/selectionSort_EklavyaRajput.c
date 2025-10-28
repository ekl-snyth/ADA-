#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void selectionSort(int *A, int n) {
    int indexofmin;
    for (int i = 0; i < n - 1; i++) {
        indexofmin = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[indexofmin]) {
                indexofmin = j;
            }
        }
        // Swap
        int temp = A[indexofmin];
        A[indexofmin] = A[i];
        A[i] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    int runs = 10;   // reduced runs for speed
    clock_t start = clock();
    for (int i = 0; i < runs; i++) {
        generateRandomArray(arr, n);
        selectionSort(arr, n);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / runs;
    printf("Average time to sort %d elements using Selection Sort: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
