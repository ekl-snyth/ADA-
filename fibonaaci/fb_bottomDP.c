
#include <stdio.h>
#include <time.h>
// Bottom-Up DP
int fib_bottomup(int n) {
if (n <= 1) return n;
int dp[n+1];
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++)
dp[i] = dp[i-1] + dp[i-2];
return dp[n];
}
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
clock_t start = clock();
int result = fib_bottomup(n);
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Bottom-Up DP Fibonacci of %d = %d\n", n, result);
printf("Time taken = %f seconds\n", time_taken);
return 0;
}