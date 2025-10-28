
#include <stdio.h>
#include <time.h>
#define MAX 10000
int memo[MAX];
// Memoization (Top-Down DP)
int fib_memo(int n) {
if (memo[n] != -1) return memo[n];
if (n <= 1) memo[n] = n;
else memo[n] = fib_memo(n-1) + fib_memo(n-2);
return memo[n];
}
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
for (int i = 0; i < MAX; i++) memo[i] = -1; // init
clock_t start = clock();
int result = fib_memo(n);
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Memoized Fibonacci of %d = %d\n", n, result);
printf("Time taken = %f seconds\n", time_taken);
return 0;
}