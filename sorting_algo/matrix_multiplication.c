#include <stdio.h>
#define SIZE 4
// iterative
// divide and conqueror
//straton method
// dynamic programming

int main() {
    int A[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 1}
    };

    int C[SIZE][SIZE] = {0}; 
    int i, j, k;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant Matrix (A × B):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%5d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
