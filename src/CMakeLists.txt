add_library(TreeOptimizer_Lib STATIC
    tree_optimize.cpp
)

target_include_directories(TreeOptimizer_Lib
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(TreeOptimizer_Lib PUBLIC cxx_std_23)