#!/bin/bash

# Define the build command
BUILD_COMMAND="make -j 8"

# Check if the build directory exists
if [ ! -d "build" ]; then    
    mkdir -p build
fi

cd build
$BUILD_COMMAND

# Run './build/microbench'
./microbench \
--keys_file=/tmp/trace/fiu/FIU_mail1.csv \
--read=1 \
--insert=0 \
--operations_num=800000000 \
--init_table_ratio=1 \
--thread_num=1 \
--memory \
--output_path=./alex_umassfin1_log.csv \
--index=alex