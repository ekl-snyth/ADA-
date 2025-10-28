import matplotlib.pyplot as plt

# Data
n = [3, 5, 10]
greedy_time = [0.000006, 0.000003, 0.000007]
dynamic_time = [0.000009, 0.000007, 0.000010]
# Plot
plt.figure(figsize=(8,5))
plt.plot(n, greedy_time, marker='o', color='blue', label='Fractional Knapsack (Greedy)')
plt.plot(n, dynamic_time, marker='o', color='red', label='0/1 Knapsack (Dynamic)')

# Labels and title
plt.title("Comparison of Execution Time: Greedy vs Dynamic Programming")
plt.xlabel("Number of Items (n)")
plt.ylabel("Execution Time (seconds)")
plt.legend()
plt.grid(True)

# Show
plt.show()