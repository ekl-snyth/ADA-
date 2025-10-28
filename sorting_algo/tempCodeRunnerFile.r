import matplotlib.pyplot as plt

# Matrix sizes
sizes = [4, 8, 16, 64, 256, 512, 1024]

# Execution times (in seconds) from your table
iterative_times = [0.000005, 0.000004, 0.000036, 0.001232, 0.065600, 0.340915, 2.520226]
recursive_times = [0.000013, 0.000012, 0.000023, 0.001963, 0.075427, 0.374691, 2.791070]
strassen_times  = [0.000019, 0.000174, 0.000724, 0.027229, 0.497135, 3.368077, 23.32715]

# Plot
plt.figure(figsize=(10,6))
plt.plot(sizes, iterative_times, marker='o', label="Iterative")
plt.plot(sizes, recursive_times, marker='s', label="Recursive (D&C)")
plt.plot(sizes, strassen_times, marker='^', label="Strassen")

# Graph formatting
plt.xlabel("Matrix Size (n x n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Matrix Multiplication Execution Time Comparison")
plt.xscale("log", base=2)  # log scale for matrix sizes
plt.yscale("log")          # log scale for time (better visualization)
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Save & Show
plt.savefig("matrix_multiplication_comparison.png", dpi=300)
plt.show()
