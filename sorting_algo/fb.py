import matplotlib.pyplot as plt
import numpy as np

# --- Data from your screenshots ---
# The value of 'n' for which the Fibonacci number was calculated.
n_values = [5, 10, 20, 50, 100]

# Time taken in seconds for each method.
# For the recursive method, we only have data up to n=50, as n=100 was not run.
# We'll plot this data point separately to handle the missing value.
n_recursive = [5, 10, 20, 50]
time_recursive = [0.000005, 0.000008, 0.000118, 62.664772]

# Data for the other, more efficient methods.
n_efficient = [5, 10, 20, 50, 100]
time_iterative = [0.000007, 0.000007, 0.000004, 0.000008, 0.000014]
time_memoized = [0.000006, 0.000006, 0.000008, 0.000006, 0.000012]
time_bottom_up = [0.000006, 0.000005, 0.000007, 0.000008, 0.000007]


# --- Plotting the graph ---
# Create a figure and a set of subplots.
fig, ax = plt.subplots(figsize=(12, 8))

# Plot data for each method with a distinct style.
ax.plot(n_recursive, time_recursive, 'o-', label='Recursive (Exponential)', color='red', linewidth=2)
ax.plot(n_efficient, time_iterative, 's--', label='Iterative (Linear)', color='blue')
ax.plot(n_efficient, time_memoized, '^--', label='Memoized DP (Linear)', color='green')
ax.plot(n_efficient, time_bottom_up, 'd--', label='Bottom-Up DP (Linear)', color='purple')

# --- Styling and Labels ---
# Set the y-axis to a logarithmic scale.
# This is essential because the recursive time for n=50 is so massive
# that it would make the other lines appear completely flat at zero on a linear scale.
ax.set_yscale('log')

# Add titles and labels for clarity.
ax.set_title('Performance Comparison of Fibonacci Algorithms', fontsize=16, fontweight='bold')
ax.set_xlabel('Value of n (Input Size)', fontsize=12)
ax.set_ylabel('Execution Time in Seconds (Logarithmic Scale)', fontsize=12)

# Add a legend to identify the lines.
ax.legend(title='Algorithm Type')

# Add a grid for better readability.
ax.grid(True, which="both", ls="--", linewidth=0.5)

# Add a text annotation to highlight the extreme value for the recursive method.
ax.annotate(f'Took ~{time_recursive[-1]:.1f} seconds!',
            xy=(n_recursive[-1], time_recursive[-1]),
            xytext=(n_recursive[-1] - 15, time_recursive[-1] / 10),
            arrowprops=dict(facecolor='black', shrink=0.05),
            fontsize=10,
            bbox=dict(boxstyle="round,pad=0.3", fc="yellow", ec="black", lw=1, alpha=0.8))


# Display the plot.
plt.tight_layout() # Adjust layout to make room for labels
plt.show()
