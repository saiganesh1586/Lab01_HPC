#!/bin/bash

for threads in 1 2 4 8 16
do
    echo "=============================="
    echo "Running with $threads threads"
    echo "=============================="

    sed -i "s/#define NUM_THREADS .*/#define NUM_THREADS $threads/" parallel_edge.c

    gcc parallel_edge.c -o parallel_edge -pthread

    ./parallel_edge

    echo ""
done
