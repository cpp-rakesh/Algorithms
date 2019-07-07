#include "bst.h"
#include <bits/stdc++.h>

int random(int s, int e) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(s, e);
    return dt(rd);
}

void test_bst() {
    BST<int> bst;
    for (int i = 0; i < 15; ++i)
        bst.insert(random(1, 100));

    bst.pre_order();
    bst.in_order();
    bst.post_order();

    for (int i = 0; i < 15; ++i) {
        const int n = random(1, 100);
        printf("[%d] is %s\n", n, bst.search(n) ? "present" : "not present");
    }
}

int main() {
    test_bst();

    return 0;
}
