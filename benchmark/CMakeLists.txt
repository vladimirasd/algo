include(FetchContent)
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
FetchContent_MakeAvailable(benchmark)

add_executable(TreeOptimizer_Bench benchmark.cpp)

target_link_libraries(TreeOptimizer_Bench
    PRIVATE
        TreeOptimizer_Lib
        benchmark::benchmark
        benchmark::benchmark_main
)