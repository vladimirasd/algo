#pragma once
#include <string>
#include <vector>

struct node {
    int ind;
    std::string f;
    std::vector<int> args;
    int args_procede = 0;
    int parent = -1;

    bool operator==(const node& other) const;
};

namespace std {
template <>
struct hash<node> {
    size_t operator()(const node& nd) const;
};
}

std::vector<int> tree_optimize(const std::vector<node> nodes);