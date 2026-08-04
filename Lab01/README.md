# Lab 01 - Performance Profiling and Optimization using GPROF and PERF

## Student Details

Name: Ch. Sai Ganesh
Roll Number: S20240010049
College: IIIT Sri City
Department: Computer Science and Engineering
Course: High Performance Computing

## Objective

To compare the performance of Bubble Sort and Quick Sort using GPROF and compiler optimizations.

## Files

- mysort.c
- myreport.txt
- report_O2.txt
- report_O3.txt
- report.pdf
- screenshots/

## Compilation

gcc -O0 -pg mysort.c -o mysort

gcc -O2 -pg mysort.c -o mysort_O2

gcc -O3 -pg mysort.c -o mysort_O3

## Execution

./mysort

## GPROF

gprof mysort gmon.out > myreport.txt

## Conclusion

Quick Sort performed better than Bubble Sort. GPROF identified bubbleSort() as the hotspot function.
