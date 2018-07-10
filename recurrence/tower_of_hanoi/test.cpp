#include "tower_of_hanoi.h"
#include "tower_of_hanoi_iterative.h"
#include <ctime>

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
    std::clock_t start = clock();
    test_recursive(n);
    std::cout << "Execution time == [" << (clock() - start) / static_cast<double>(CLOCKS_PER_SEC) << "] seconds"
              << std::endl;

    start = clock();
    test_iterative(n);
    std::cout << "Execution time == [" << (clock() - start) / static_cast<double>(CLOCKS_PER_SEC) << "] seconds"
              << std::endl;
}

int main() {
    test();

    return 0;
}
