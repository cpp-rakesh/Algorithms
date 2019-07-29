#include "bt.h"

int main() {
    BT<int> bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    bt.insert(8);
    bt.insert(9);
    bt.insert(10);

    bt.pre_order();
    bt.in_order();
    bt.post_order();
    bt.bfs();
    bt.level();

    return 0;
}
