import math
import matplotlib.pyplot as plt

# =========================
# SERIAL RESULT
# =========================

serial_time = 0.020978

# =========================
# THREAD RESULTS
# =========================

threads = [1, 2, 4, 8, 16]

parallel_times = [
    0.017350,
    0.028550,
    0.013789,
    0.019039,
    0.014036
]

# =========================
# POINT RESULTS
# =========================

points = [
    10,
    100,
    10000,
    1000000,
    10000000,
    100000000,
    1000000000
]

pi_values = [
    0.0000000000,
    2.9600000000,
    3.1216000000,
    3.1413560000,
    3.1420172000,
    3.1417683600,
    3.1415748080
]

times_points = [
    0.001377,
    0.001331,
    0.001496,
    0.020373,
    0.203679,
    1.221237,
    20.735260
]

# =========================
# ERROR
# =========================

actual_pi = math.pi

errors = [
    abs(actual_pi - value)
    for value in pi_values
]

# =========================
# SPEEDUP
# =========================

speedups = [
    serial_time / time
    for time in parallel_times
]

# =========================
# EFFICIENCY
# =========================

efficiencies = [
    (speedup / thread) * 100
    for speedup, thread in zip(speedups, threads)
]

# =========================
# PRINT RESULTS
# =========================

print("\n========== Q1 RESULTS ==========\n")

print("Serial Average Time:", serial_time)

print("\nTHREAD PERFORMANCE")
print("---------------------------------------------")
print("Threads\tTime\t\tSpeedup\t\tEfficiency")

for t, time, speedup, efficiency in zip(
    threads,
    parallel_times,
    speedups,
    efficiencies
):
    print(
        f"{t}\t{time:.6f}\t"
        f"{speedup:.4f}\t\t"
        f"{efficiency:.2f}%"
    )

print("\nPOINT RESULTS")
print("---------------------------------------------")
print("Points\t\tPi\t\tError\t\tTime")

for p, pi, error, time in zip(
    points,
    pi_values,
    errors,
    times_points
):
    print(
        f"{p:<12}\t"
        f"{pi:.10f}\t"
        f"{error:.10f}\t"
        f"{time:.6f}"
    )

# =========================
# GRAPH 1
# POINTS VS PI
# =========================

plt.figure()

plt.plot(points, pi_values, marker="o")

plt.xscale("log")

plt.xlabel("Number of Points")
plt.ylabel("Estimated Pi")
plt.title("Number of Points vs Estimated Pi")

plt.grid(True)

plt.savefig("points_vs_pi.png", dpi=300)

plt.show()

# =========================
# GRAPH 2
# POINTS VS ERROR
# =========================

plt.figure()

plt.plot(points, errors, marker="o")

plt.xscale("log")
plt.yscale("log")

plt.xlabel("Number of Points")
plt.ylabel("Error")
plt.title("Number of Points vs Error")

plt.grid(True)

plt.savefig("points_vs_error.png", dpi=300)

plt.show()

# =========================
# GRAPH 3
# THREADS VS EXECUTION TIME
# =========================

plt.figure()

plt.plot(
    threads,
    parallel_times,
    marker="o"
)

plt.xlabel("Number of Threads")
plt.ylabel("Execution Time (seconds)")
plt.title("Threads vs Execution Time")

plt.grid(True)

plt.savefig("threads_vs_time.png", dpi=300)

plt.show()

# =========================
# GRAPH 4
# THREADS VS SPEEDUP
# =========================

plt.figure()

plt.plot(
    threads,
    speedups,
    marker="o"
)

plt.xlabel("Number of Threads")
plt.ylabel("Speedup")
plt.title("Threads vs Speedup")

plt.grid(True)

plt.savefig("threads_vs_speedup.png", dpi=300)

plt.show()

# =========================
# GRAPH 5
# THREADS VS EFFICIENCY
# =========================

plt.figure()

plt.plot(
    threads,
    efficiencies,
    marker="o"
)

plt.xlabel("Number of Threads")
plt.ylabel("Efficiency (%)")
plt.title("Threads vs Efficiency")

plt.grid(True)

plt.savefig("threads_vs_efficiency.png", dpi=300)

plt.show()

print("\nGraphs created successfully!")
print("Files:")
print("points_vs_pi.png")
print("points_vs_error.png")
print("threads_vs_time.png")
print("threads_vs_speedup.png")
print("threads_vs_efficiency.png")