
#include <stdio.h>
#include <time.h>
// Iterative Fibonacci
int fib_iterative(int n) {
if (n <= 1) return n;
int a = 0, b = 1, c;
for (int i = 2; i <= n; i++) {
c = a + b;
a = b;
b = c;
}
return b;
}
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
clock_t start = clock();
int result = fib_iterative(n);
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Iterative Fibonacci of %d = %d\n", n, result);
printf("Time taken = %f seconds\n", time_taken);
return 0;
}