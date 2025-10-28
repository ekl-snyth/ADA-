
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Allocate n×n matrix
int **alloc_matrix(int n) {
int **mat = (int **)malloc(n * sizeof(int *));
for (int i = 0; i < n; i++)
mat[i] = (int *)malloc(n * sizeof(int));
return mat;
}
void free_matrix(int **mat, int n) {
for (int i = 0; i < n; i++) free(mat[i]);
free(mat);
}
void fill_matrix(int **mat, int n) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
mat[i][j] = rand() % 10;
}
// Iterative multiplication
void multiply_iterative(int **A, int **B, int **C, int n) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++) {
C[i][j] = 0;
for (int k = 0; k < n; k++)
C[i][j] += A[i][k] * B[k][j];
}
}
int main() {
srand(time(NULL));
int n;
printf("Enter matrix size: ");
scanf("%d", &n);
int **A = alloc_matrix(n);
int **B = alloc_matrix(n);
int **C = alloc_matrix(n);
fill_matrix(A, n);
fill_matrix(B, n);
clock_t start = clock();
multiply_iterative(A, B, C, n);
clock_t end = clock();
printf("Iterative Time: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
free_matrix(A, n);
free_matrix(B, n);
free_matrix(C, n);
return 0;
}