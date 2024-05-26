#include "./benchmark.h"

int main(int argc, char **argv)
{
    Benchmark<uint32_t, uint32_t> bench;
    bench.parse_args(argc, argv);
    bench.run_benchmark();
}
