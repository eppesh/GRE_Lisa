# Run
./build/microbench \
--keys_file=/tmp/trace/umass/umass_financial1 \
--keys_file_type=text \
--read=1 --insert=0\
--operations_num=800000000 \
--table_size=-1 \
--init_table_ratio=1 \
--thread_num=1 \
--memory \
--output_path=./alex_umassfin1_log.csv \
--index=alex