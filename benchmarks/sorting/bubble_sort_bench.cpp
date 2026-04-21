#include <benchmark/benchmark.h>
#include "mystd/sorting/bubble_sort.h"
#include <numeric>

static void BM_BubbleSortNaive(benchmark::State &state)
{
    std::vector<int> input(state.range(0));
    std::iota(input.rbegin(), input.rend(), 0); // worst case: reverse sorted
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(bubble_sort_naive(input));
    }
}
BENCHMARK(BM_BubbleSortNaive)->Range(8, 1 << 14);

static void BM_BubbleSortOptimized(benchmark::State &state)
{
    std::vector<int> input(state.range(0));
    std::iota(input.rbegin(), input.rend(), 0); // worst case: reverse sorted
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(bubble_sort_shrink_inner_loop(input));
    }
}
BENCHMARK(BM_BubbleSortOptimized)->Range(8, 1 << 14);

static void BM_BubbleSortEarlyExit(benchmark::State &state)
{
    std::vector<int> input(state.range(0));
    std::iota(input.rbegin(), input.rend(), 0); // worst case: reverse sorted
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(bubble_sort_early_exit(input));
    }
}
BENCHMARK(BM_BubbleSortEarlyExit)->Range(8, 1 << 14);