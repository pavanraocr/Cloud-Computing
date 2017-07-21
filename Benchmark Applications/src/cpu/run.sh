#!/bin/bash
echo "Compiling and executing CPU Performance for IOPS with single thread"
make -f makefileT1I
make -f makefileT1I run
make -f makefileT1I clean
echo "Compiling and executing CPU Performance for FLOPS with single thread"
make -f makefileT1F
make -f makefileT1F run
make -f makefileT1F clean
echo "Compiling and executing CPU Performance for IOPS with two thread"
make -f makefileT2I
make -f makefileT2I run
make -f makefileT2I clean
echo "Compiling and executing CPU Performance for FLOPS with two thread"
make -f makefileT2F
make -f makefileT2F run
make -f makefileT2F clean
echo "Compiling and executing CPU Performance for IOPS with four thread"
make -f makefileT4I
make -f makefileT4I run
make -f makefileT4I clean
echo "Compiling and executing CPU Performance for FLOPS with four thread"
make -f makefileT4F
make -f makefileT4F run
make -f makefileT4F clean
echo "Compiling and executing CPU Performance in terms of IOPS for 10 min with smaples extracted every second with four threads, result in an outputFile"
make -f makefileIT4
make -f makefileIT4 run
make -f makefileIT4 clean
echo "Compiling and executing CPU Performance in terms of FLOPS for 10 min with smaples extracted every second with four threads, result in an outputFile"
make -f makefileFT4
make -f makefileFT4 run
make -f makefileFT4 clean
