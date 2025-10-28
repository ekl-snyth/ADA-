import matplotlib.pyplot as plt

# Matrix sizes
matrix_sizes = [10, 20, 50, 100, 500, 1000, 2000]

# Execution times (seconds)
iterative_time = [0.000011, 0.000038, 0.001007, 0.005817, 0.300065, 2.337884, 29.630607]
recursive_time = [0.000009, 0.000030, 0.000587, 0.003557, 0.073808, 0.564442, 7.173957]
strassen_time  = [0.000003, 0.000440, 0.019488, 0.069076, 2.407265, 16.339782, 131.277357]

# Plot
plt.plot(matrix_sizes, iterative_time, marker='o', label="Iterative")
plt.plot(matrix_sizes, recursive_time, marker='s', label="Recursive")
plt.plot(matrix_sizes, strassen_time, marker='^', label="Strassen")

# Labels and Title
plt.xlabel("Matrix Size (n x n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Matrix Multiplication Execution Time")
plt.legend()
plt.grid(True)

# Optional: log scale for Y-axis (uncomment next line if needed)
# plt.yscale("log")

# Show the graph
plt.show()
