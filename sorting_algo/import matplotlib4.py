import matplotlib.pyplot as plt

# Data for Bubble Sort
n_values = [100, 200, 400, 800, 1600, 50000, 100000]
time_values = [0.00015, 0.00060, 0.00250, 0.01020, 0.04150, 4.5, 18.0]  # adjusted values

# Plot
plt.figure(figsize=(8, 5))
plt.plot(n_values, time_values, marker='o', markersize=7, linewidth=2, color='red', label="Bubble Sort")

# Labels & Title
plt.title("Bubble Sort: Time vs Number of Elements", fontsize=14)
plt.xlabel("Number of Elements (n)", fontsize=12)
plt.ylabel("Time Taken (seconds)", fontsize=12)

# Grid + Legend
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

plt.show()
