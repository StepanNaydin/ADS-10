// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> result;
    for (int q = 0; q < tree.all.size(); q++) {
        if (q >= (n - 1) * tree.len && q < n * tree.len) {
            result.push_back(tree.all[q]);
        }
    }
    return result;
}
