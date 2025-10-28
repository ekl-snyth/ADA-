import matplotlib.pyplot as plt

# Data from your C program outputs (fill in your actual measured times)
n_values = [1000, 5000, 10000, 20000, 50000]  
time_values = [0.00012, 0.0021, 0.0085, 0.034, 0.221]  # Example times in seconds

# Plot
plt.figure(figsize=(8, 5))
plt.plot(n_values, time_values, marker='o', markersize=7, linewidth=2, label="Insertion Sort")

# Labels & Title
plt.title("Insertion Sort: Time vs Number of Elements", fontsize=14)
plt.xlabel("Number of Elements (n)", fontsize=12)
plt.ylabel("Time Taken (seconds)", fontsize=12)

# Grid
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

plt.show()
