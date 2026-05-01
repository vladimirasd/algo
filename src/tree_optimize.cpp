#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <unordered_set>
#include <set>
#include "tree_optimize.h"
using namespace std;


vector<int> replace;  // каждоый вершине ставим в соотвествие ее уникальный аналог

bool node::operator==(const node& other) const {
    if (f != other.f) return false;
    if (args.size() != other.args.size()) return false;
    for (size_t i = 0; i < args.size(); ++i) {
        if (replace[args[i]] != replace[other.args[i]]) return false;
    }
    return true;
}

namespace std {
size_t hash<node>::operator()(const node& nd) const {
    size_t h = hash<string>()(nd.f);
    h ^= hash<size_t>()(nd.args.size()) + 0x9e3779b9 + (h << 6) + (h >> 2);
    for (int arg : nd.args) {
        int replaced = replace[arg];
        h ^= hash<int>()(replaced) + 0x9e3779b9 + (h << 6) + (h >> 2);
    }
    return h;
}
}

vector<int> tree_optimize(vector<node> nodes) {

	int n = nodes.size();
	replace.assign(n, 0);

	for (int i = 0; i < n; ++i) {
		replace[i] = i;
	}

	//формируем replace


	unordered_set<node> unique; // уникальные поддеревья 
	vector<int> cur; // вершины для обработки сейчас
	vector<int> next; // вершины для обработки на следующей итерации

	//запихиваем листы
	for (int i = 0; i < n; ++i) {
		if (nodes[i].args.size() == 0) {
			next.push_back(i);
		}
	}

	while (next.size() != 0) { // пока есть что обрабатываться
		cur = next;
		next.clear();

		for (int i : cur) {

			auto iter = unique.find(nodes[i]);

			if (iter == unique.end()) { // если не нашли то очев добавляем
				unique.insert(nodes[i]);
			}
			else { // иначе обновляем replace
				node analog = *iter;
				replace[i] = analog.ind;
			}

			if (nodes[i].parent != -1) {
				nodes[nodes[i].parent].args_procede++; // для отца обновляем кол-во обработанных сыновей

				if (nodes[nodes[i].parent].args_procede == nodes[nodes[i].parent].args.size()) { // отправляем дальше ТОЛЬКО если обработали всех сыновей
					next.push_back(nodes[i].parent);
				}
			}

		}
	}

	return replace;

}

