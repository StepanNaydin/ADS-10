// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
struct tree_elem {
    char m_data;
    int count = 1;
    std::vector<tree_elem*> Links;
    explicit tree_elem(char in, tree_elem* a = NULL) {
        m_data = in;
    }
};
class Tree {
 private:
    struct bspom {
        tree_elem& elem;
        std::vector<char> in;
        bspom* a;
        bspom(tree_elem elem, std::vector<char> in, bspom* a) :
        elem(elem), in(in), a(a) {}
    };

 public:
    std::vector<char> all;
    int len;
    explicit Tree(std::vector<char> in) {
        len = in.size();
        for (int q = 0; q < in.size(); q++) {
            tree_elem* elem = new tree_elem(in[q]);
            std::vector<char> in2 = in;
            char z = elem->m_data;
            for (auto it = in2.begin(); it != in2.end(); ) {
                if (*it == z) {
                    it = in2.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
            bspom a(*elem, in2, 0);
            BuildBranch(a);
        }
    }
    bspom BuildBranch(bspom a) {
        for (int q = 0; q < a.in.size(); q++) {
            tree_elem* elem1 = new tree_elem(a.in[q], &a.elem);
            a.elem.Links.push_back(elem1);
            std::vector<char> in2 = a.in;
            char z = elem1->m_data;
            for (auto it = in2.begin(); it != in2.end(); ) {
                if (*it == z) {
                    it = in2.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
            if (a.in.size() <= 1) {
                if (a.in.size() != 0) {
                    all.push_back(a.elem.m_data);
                    all.push_back(elem1->m_data);
                }
                return *a.a;
            } else {
                bspom b(*elem1, in2, &a);
                all.push_back(a.elem.m_data);
                BuildBranch(b);
                if (a.a != 0) {
                    all.push_back(a.a->elem.m_data);
                }
            }
        }
        if (a.a != 0) {
            all.pop_back();
        }
        if (a.a == 0) {
            return a;
        }
        return *a.a;
    }
};
#endif  // INCLUDE_TREE_H_
