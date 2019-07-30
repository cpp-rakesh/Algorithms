#include "bt.h"

void test() {
    BT<int> bt;
    // insert test
    for (int i = 1; i <= 10; ++i)
        bt.insert(i);

    // traversal test
    bt.pre_order();
    bt.in_order();
    bt.post_order();
    bt.bfs();
    bt.level();

    // remove test
    bt.remove(1);
    bt.level();

    bt.remove(7);
    bt.level();
}

int main() {
    test();

    return 0;
}
