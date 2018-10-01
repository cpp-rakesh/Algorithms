#include "tower_of_hanoi.h"
#include "tower_of_hanoi_iterative.h"
#include <chrono>

void test_recursive(const int& n) {
    RECURRENCE::Tower<int> tower(SOURCE);
    for (int i = 0; i < n; ++i)
        tower.Front(i + 1);
    RECURRENCE::TowerOfHanoi<int> hanoi;
    hanoi.Compute(tower);
}

void test_iterative(const int& n) {
    RECURRENCE::Tower<int> A(SOURCE);
    RECURRENCE::Tower<int> B(TEMP);
    RECURRENCE::Tower<int> C(TARGET);
    for (int i = 0; i < n; ++i)
        A.Front(i + 1);
    TowerOfHanoi<int> hanoi;
    hanoi.Compute(A, B, C);
}

void test() {
    int n = 10;
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    test_recursive(n);
    printf("Recursive execution time == [%lf]\n",
           std::chrono::duration<double>(clock::now() - start).count());

    start = clock::now();
    test_iterative(n);
    printf("Iterative execution time == [%lf]\n",
           std::chrono::duration<double>(clock::now() - start).count());
}

int main() {
    test();

    return 0;
}
