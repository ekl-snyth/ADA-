import matplotlib.pyplot as plt

n_values = [1000, 5000, 10000, 20000, 50000, 100000]
time_values = [0.000014, 0.000025, 0.000045, 0.000072, 0.000163, 0.000179]

# Plotting
plt.plot(n_values, time_values, marker='o')
plt.title("Linear Search: Time vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()
