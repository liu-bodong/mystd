cmake_minimum_required(VERSION 3.20)
project(mystd CXX)
set(CMAKE_CXX_STANDARD 17)

# -- mystd interface library --
add_library(mystd src/sorting/bubble_sort.cpp)
target_include_directories(mystd PUBLIC include/)

# -- Google Test --
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(test_sorting tests/sorting/bubble_sort_test.cpp)
target_link_libraries(test_sorting mystd GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_sorting)

# -- Google Benchmark --
set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_Declare(benchmark URL https://github.com/google/benchmark/archive/refs/tags/v1.8.4.tar.gz)
FetchContent_MakeAvailable(benchmark)

add_executable(bench_sorting benchmarks/sorting/bubble_sort_bench.cpp)
target_link_libraries(bench_sorting mystd benchmark::benchmark_main)

