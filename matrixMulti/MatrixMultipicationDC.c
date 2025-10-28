
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Allocate matrix
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
// Recursive utility
void multiply_recursive_util(int **A, int **B, int **C, int n,
int a_row, int a_col,
int b_row, int b_col,
int c_row, int c_col) {
if (n == 1) {
return;
C[c_row][c_col] += A[a_row][a_col] * B[b_row][b_col];
}
int half = n / 2;
multiply_recursive_util(A, B, C, half, a_row, a_col, b_row, b_col, c_row, c_col);
multiply_recursive_util(A, B, C, half, a_row, a_col + half, b_row + half, b_col,
c_row, c_col);
multiply_recursive_util(A, B, C, half, a_row, a_col, b_row, b_col + half, c_row,
c_col + half);
multiply_recursive_util(A, B, C, half, a_row, a_col + half, b_row + half, b_col +
half, c_row, c_col + half);
multiply_recursive_util(A, B, C, half, a_row + half, a_col, b_row, b_col, c_row +
half, c_col);
multiply_recursive_util(A, B, C, half, a_row + half, a_col + half, b_row + half,
b_col, c_row + half, c_col);
multiply_recursive_util(A, B, C, half, a_row + half, a_col, b_row, b_col + half,
c_row + half, c_col + half);
multiply_recursive_util(A, B, C, half, a_row + half, a_col + half, b_row + half,
b_col + half, c_row + half, c_col + half);
}
// Wrapper
void multiply_recursive(int **A, int **B, int **C, int n) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
C[i][j] = 0;
multiply_recursive_util(A, B, C, n, 0, 0, 0, 0, 0, 0);
}
int main() {
srand(time(NULL));
int n;
printf("Enter matrix size (power of 2): ");
scanf("%d", &n);
int **A = alloc_matrix(n);
int **B = alloc_matrix(n);
int **C = alloc_matrix(n);
fill_matrix(A, n);
fill_matrix(B, n);
clock_t start = clock();
multiply_recursive(A, B, C, n);
clock_t end = clock();
printf("Recursive Time: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
free_matrix(A, n);
free_matrix(B, n);
free_matrix(C, n);
return 0;
}