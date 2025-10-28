import matplotlib.pyplot as plt

# Example data (replace with your actual recorded values)
n_values = [1000, 5000, 10000, 20000, 50000, 100000]
time_values = [0.000001, 0.000002, 0.000003, 0.000003, 0.000004, 0.000004]  # in seconds

plt.plot(n_values, time_values, marker='o', label="Binary Search")
plt.title("Binary Search: Time vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.legend()
plt.show()
