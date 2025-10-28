import matplotlib.pyplot as plt

# Data from your Quick Sort experiment
n_values = [1000, 5000, 10000, 50000, 100000]
time_values = [0.000108, 0.000893, 0.002627, 0.048910, 0.093880]  # in seconds

# Plot
plt.figure(figsize=(8, 5))
plt.plot(n_values, time_values, marker='o', markersize=7, linewidth=2, label="Quick Sort")

# Labels & Title
plt.title("Quick Sort: Time vs Number of Elements", fontsize=14)
plt.xlabel("Number of Elements (n)", fontsize=12)
plt.ylabel("Time Taken (seconds)", fontsize=12)

# Grid & Legend
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

plt.show()
