#include <gtest/gtest.h>
#include "tree_optimize.h"
#include<iostream>
TEST(TreeOptimize, SingleLeaf) {
    std::vector<node> nodes(1);
    nodes[0] = { 0, "x", {}, 0, -1 };
    auto rep = tree_optimize(nodes);
    EXPECT_EQ(rep[0], 0);
}

TEST(TreeOptimize, TwoIdenticalLeaves) {

    std::vector<node> nodes(3);
    nodes[0] = { 0, "*", {1,2}, 0, -1 };
    nodes[1] = { 1, "x", {}, 0, 0 };
    nodes[2] = { 2, "x", {}, 0, 0 };
    auto rep = tree_optimize(nodes);
    EXPECT_EQ(rep[1], rep[2]);  
}


TEST(TreeOptimize, TwoDifferentLeaves) {
    std::vector<node> nodes(3);
    nodes[0] = { 0, "+", {1,2}, 0, -1 };
    nodes[1] = { 1, "x", {}, 0, 0 };
    nodes[2] = { 2, "y", {}, 0, 0 };
    auto rep = tree_optimize(nodes);
    EXPECT_NE(rep[1], rep[2]);
}

TEST(TreeOptimize, BigTree) {
    std::vector<node> nodes(7);
    nodes[0] = { 0, "+", {1,2}, 0, -1 };
    nodes[1] = { 1, "*", {3, 4}, 0, 0 };
    nodes[2] = { 2, "*", {5, 6}, 0, 0 };
    nodes[3] = { 3, "A", {}, 0, 1 };
    nodes[4] = { 4, "B", {}, 0, 1 };
    nodes[5] = { 5, "A", {}, 0, 2 };
    nodes[6] = { 6, "B", {}, 0, 2 };
    auto rep = tree_optimize(nodes);
    EXPECT_EQ(rep[1], rep[2]);
    EXPECT_EQ(rep[4], rep[6]);
    EXPECT_EQ(rep[3], rep[5]);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}