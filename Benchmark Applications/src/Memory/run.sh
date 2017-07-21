#!/bin/bash
echo "\n Compiling and Executing Memory Benchmark with 1 thread and BYTE size sequential transfers\n"
make -f makeT1b
make -f makeT1b run
make -f makeT1b clean
echo "\n Compiling and Executing Memory Benchmark with 1 thread and BYTE size random transfers\n"
make -f makeT1br
make -f makeT1br run
make -f makeT1br clean
echo "\n Compiling and Executing Memory Benchmark with 1 thread and kB size sequential transfers\n"
make -f makeT1k
make -f makeT1k run
make -f makeT1k clean
echo "\n Compiling and Executing Memory Benchmark with 1 thread and kB size random transfers\n"
make -f makeT1kr
make -f makeT1kr run
make -f makeT1kr clean
echo "\n Compiling and Executing Memory Benchmark with 1 thread and MB size sequential transfers\n"
make -f makeT1m
make -f makeT1m run
make -f makeT1m clean
echo "\n Compiling and Executing Memory Benchmark with 1 thread and MB size random transfers\n"
make -f makeT1mr
make -f makeT1mr run
make -f makeT1mr clean
echo "\n Compiling and Executing Memory Benchmark with 2 thread and BYTE size sequential transfers\n"
make -f makeT2b
make -f makeT2b run
make -f makeT2b clean
echo "\n Compiling and Executing Memory Benchmark with 2 thread and BYTE size random transfers\n"
make -f makeT2br
make -f makeT2br run
make -f makeT2br clean
echo "\n Compiling and Executing Memory Benchmark with 2 thread and kB size sequential transfers\n"
make -f makeT2k
make -f makeT2k run
make -f makeT2k clean
echo "\n Compiling and Executing Memory Benchmark with 2 thread and kB size random transfers\n"
make -f makeT2kr
make -f makeT2kr run
make -f makeT2kr clean
echo "\n Compiling and Executing Memory Benchmark with 2 thread and MB size sequential transfers\n"
make -f makeT2m
make -f makeT2m run
make -f makeT2m clean
echo "\n Compiling and Executing Memory Benchmark with 2 thread and MB size random transfers\n"
make -f makeT2mr
make -f makeT2mr run
make -f makeT2mr clean
