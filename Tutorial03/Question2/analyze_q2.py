serial_time = 0.040298

threads = [1, 2, 4, 8, 16]

parallel_times = [
    0.034713,
    0.030578,
    0.040828,
    0.034960,
    0.027428
]

speedups = [
    serial_time / t
    for t in parallel_times
]

efficiencies = [
    (s / thread) * 100
    for s, thread in zip(speedups, threads)
]

print("\n========== Q2 RESULTS ==========\n")

print("Serial Execution Time:", serial_time)

print("\nThreads\tTime\t\tSpeedup\t\tEfficiency")
print("---------------------------------------------")

for thread, time, speedup, efficiency in zip(
    threads,
    parallel_times,
    speedups,
    efficiencies
):
    print(
        f"{thread}\t"
        f"{time:.6f}\t"
        f"{speedup:.4f}\t\t"
        f"{efficiency:.2f}%"
    )

# Graphs
import matplotlib.pyplot as plt

# 1. Threads vs Execution Time
plt.figure()
plt.plot(threads, parallel_times, marker="o")
plt.xlabel("Number of Threads")
plt.ylabel("Execution Time (seconds)")
plt.title("Threads vs Parallel Execution Time")
plt.grid(True)
plt.savefig("q2_threads_vs_time.png", dpi=300)
plt.close()

# 2. Threads vs Speedup
plt.figure()
plt.plot(threads, speedups, marker="o")
plt.xlabel("Number of Threads")
plt.ylabel("Speedup")
plt.title("Threads vs Speedup")
plt.grid(True)
plt.savefig("q2_threads_vs_speedup.png", dpi=300)
plt.close()

# 3. Threads vs Efficiency
plt.figure()
plt.plot(threads, efficiencies, marker="o")
plt.xlabel("Number of Threads")
plt.ylabel("Efficiency (%)")
plt.title("Threads vs Efficiency")
plt.grid(True)
plt.savefig("q2_threads_vs_efficiency.png", dpi=300)
plt.close()

print("\nGraphs created successfully!")
print("q2_threads_vs_time.png")
print("q2_threads_vs_speedup.png")
print("q2_threads_vs_efficiency.png")
