#include <stdio.h>

#define SIZE 4   // Works for SIZE = power of 2


void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}


void multiplyDC(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {  // base case: 1x1 matrix
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;

  
    int A11[mid][mid], A12[mid][mid], A21[mid][mid], A22[mid][mid];
    int B11[mid][mid], B12[mid][mid], B21[mid][mid], B22[mid][mid];
    int C11[mid][mid], C12[mid][mid], C21[mid][mid], C22[mid][mid];
    int temp1[mid][mid], temp2[mid][mid];

 
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // C11 = A11*B11 + A12*B21
    multiplyDC(mid, A11, B11, temp1);
    multiplyDC(mid, A12, B21, temp2);
    addMatrix(mid, temp1, temp2, C11);

    // C12 = A11*B12 + A12*B22
    multiplyDC(mid, A11, B12, temp1);
    multiplyDC(mid, A12, B22, temp2);
    addMatrix(mid, temp1, temp2, C12);

    // C21 = A21*B11 + A22*B21
    multiplyDC(mid, A21, B11, temp1);
    multiplyDC(mid, A22, B21, temp2);
    addMatrix(mid, temp1, temp2, C21);

    // C22 = A21*B12 + A22*B22
    multiplyDC(mid, A21, B12, temp1);
    multiplyDC(mid, A22, B22, temp2);
    addMatrix(mid, temp1, temp2, C22);

   
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

void printMatrix(int n, int M[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", M[i][j]);
        }
        printf("\n");
    }
}

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

    multiplyDC(SIZE, A, B, C);

    printf("Resultant Matrix (A × B):\n");
    printMatrix(SIZE, C);

    return 0;
}
