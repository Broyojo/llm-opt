#!/bin/bash
ulimit -t 60

#Your clang and llvm-mca paths
CC=/usr/bin/clang-20
MCA=/usr/lib/llvm-20/bin/llvm-mca

#You CAN change the compiler flags
CFLAGS=""



##################################################
# DO NOT MAKE ANY CHANGES TO THE REST OF THIS FILE
##################################################

#You CANNOT change the mca and arch flags
MCAFLAGS="-mcpu=znver2"
ARCHFLAGS="-march=znver2 -mtune=znver2"



#Correctness testing (step 1): Build the file
rm a.out 2>/dev/null
$CC  $CFLAGS  tester.c || {
    echo "Build error, quit"
    exit 1
}

#Correctness testing (step 2): Test the output
for i in $(seq 1 10); do
    ./a.out > out || {
	echo "Incorrect output! See the out file in this folder."
	exit 1
    }
done




#Performance testing (step 1): Build the file
rm yours.s 2>/dev/null
$CC yours.c $ARCHFLAGS $CFLAGS -S || {
    echo "Cannot build, quit"
    exit 1
}

#Performance testing (step 2): Obtain the RThroughput
$MCA $MCAFLAGS yours.s 2>/dev/null | grep "Block RThroughput:" | sed 's/Block RThroughput: //g' || {
    echo "llvm-mca cannot process your file, quit"
    exit 1
}

exit 0
