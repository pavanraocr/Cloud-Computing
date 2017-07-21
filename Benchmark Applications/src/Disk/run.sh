#!/bin/bash
echo "Compiles and Executes the Benchmarks for disk read and write operations with 1 thread and varying buffer sizes"
make -f makefile
make -f	makefile run
make -f makefile clean
echo "Compiles and Executes the Benchmarks for disk read and write operations with 2 thread and varying buffer sizes"
make -f makefile2
make -f makefile2 run
make -f makefile2 clean
