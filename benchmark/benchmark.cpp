#include "tree_optimize.h"
#include <benchmark/benchmark.h>
#include <vector>

std::vector<node> generate_balanced_binary_tree(int size) {

    if (size <= 0) return {};
    std::vector<node> nodes(size);

    for (int i = 0; i < size; ++i) {

        nodes[i].ind = i;
        nodes[i].f = (2 * i + 1 < size || 2 * i + 2 < size) ? "+" : "x";
        nodes[i].args_procede = 0;
        nodes[i].parent = -1;
        nodes[i].args.clear();

    }

    for (int i = 0; i < size; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size) {
            nodes[i].args.push_back(left);
            nodes[left].parent = i;
        }
        if (right < size) {
            nodes[i].args.push_back(right);
            nodes[right].parent = i;
        }
    }
    return nodes;
}

static void BM_BalancedTree(benchmark::State& state) {
    int size = state.range(0);
    auto tree = generate_balanced_binary_tree(size);
    for (auto _ : state) {
        auto rep = tree_optimize(tree);
        benchmark::DoNotOptimize(rep);
    }
}
BENCHMARK(BM_BalancedTree)->Range(8, 8 << 10)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();