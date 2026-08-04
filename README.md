# Lab 01 - Performance Profiling and Optimization using GPROF and PERF

## Student Information

- **Name:** Ch. Sai Ganesh
- **Roll Number:** S20240010049
- **College:** Indian Institute of Information Technology (IIIT), Sri City
- **Department:** Computer Science and Engineering
- **Course:** High Performance Computing Laboratory
- **Semester:** UG-3 (Semester 5)

---

## Experiment Objective

The objective of this experiment is to compare the performance of two sorting algorithms, Bubble Sort and Quick Sort, using Linux profiling tools. The experiment also studies the effect of compiler optimizations on execution time and identifies the functions that consume the maximum CPU time using GPROF.

---

## Problem Statement

A weather analytics company processes a large amount of daily temperature data. The existing sorting application is slower than expected. The objective of this experiment is to analyze the application's performance, identify bottlenecks, and compare different sorting algorithms to determine the most efficient approach.

---

## Algorithms Used

- Bubble Sort
- Quick Sort

Bubble Sort is implemented as the baseline algorithm, while Quick Sort is used as the optimized sorting algorithm for performance comparison.

---

## Software Requirements

- Ubuntu Linux
- GCC Compiler
- GNU GPROF
- Git

> **Note:** PERF analysis could not be completed because the experiment was performed on WSL2, where the required Linux kernel performance tools were unavailable.

---

## Files Included

```
Lab01/
│── mysort.c
│── myreport.txt
│── report_O2.txt
│── report_O3.txt
│── report.pdf
│── README.md
└── screenshots/
```

---

## Compilation

Compile without optimization:

```bash
gcc -O0 -pg mysort.c -o mysort
```

Compile with **-O2** optimization:

```bash
gcc -O2 -pg mysort.c -o mysort_O2
```

Compile with **-O3** optimization:

```bash
gcc -O3 -pg mysort.c -o mysort_O3
```

---

## Execution

Run the program using:

```bash
./mysort
```

Measure execution time:

```bash
time ./mysort
```

Generate the GPROF report:

```bash
gprof mysort gmon.out > myreport.txt
```

---

## Observations

- Bubble Sort required significantly more execution time because it performs a large number of comparisons and swaps.
- Quick Sort completed much faster due to its Divide and Conquer approach.
- GPROF identified **bubbleSort()** as the function consuming the maximum CPU time.
- Compiler optimization levels influenced the execution time and overall performance.

---

## Results

| Algorithm | Average Time Complexity | Performance |
|-----------|-------------------------|-------------|
| Bubble Sort | O(n²) | Slow |
| Quick Sort | O(n log n) | Fast |

---

## Conclusion

This experiment demonstrates that algorithm selection has a significant impact on application performance. Quick Sort performed considerably better than Bubble Sort for the given dataset. GPROF profiling successfully identified the performance bottleneck, and compiler optimization helped improve execution efficiency. Overall, Quick Sort is the preferred algorithm for handling large datasets.

---

## References

1. GNU GCC Documentation
2. GNU GPROF Documentation
3. Linux Manual Pages
4. Introduction to Algorithms – Cormen, Leiserson, Rivest and Stein
