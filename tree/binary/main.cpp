#include "binary.h"
#include <bits/stdc++.h>

int random(int s, int e) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(s, e);
    return dt(rd);
}

void test_binary() {
    Binary<int> b;
    for (int i = 0; i < 15; ++i)
        b.insert(random(1, 100));
    b.in_order();
}

int main() {
    test_binary();

    return 0;
}
