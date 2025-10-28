import matplotlib.pyplot as plt

# Data: replace these values with your measured selection sort times
n_values = [100, 200, 400, 800, 1600]
time_values = [0.00012, 0.00046, 0.00185, 0.00740, 0.02980]  # example times in seconds

# Plot
plt.figure(figsize=(8, 5))
plt.plot(n_values, time_values, marker='o', markersize=7, linewidth=2, label="Selection Sort")

# Labels & Title
plt.title("Selection Sort: Time vs Number of Elements", fontsize=14)
plt.xlabel("Number of Elements (n)", fontsize=12)
plt.ylabel("Time Taken (seconds)", fontsize=12)

# Grid + Legend
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

plt.show()
