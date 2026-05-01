enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(TreeOptimizer_Tests test.cpp)

target_link_libraries(TreeOptimizer_Tests
    PRIVATE
        TreeOptimizer_Lib
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(TreeOptimizer_Tests)