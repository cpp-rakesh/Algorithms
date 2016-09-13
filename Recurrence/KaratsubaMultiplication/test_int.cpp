#include "Integer.h"
#include <ctime>

void test_1() {
    Integer A(1);
    for (int i = 1000; i > 1; --i)
        A *= i;
    A.Print();
}

void test_2() {
    Integer A(1);
    for (int i = 1000; i > 1; --i)
        A = A * i;
    A.Print();    
}

int main() {
    std::clock_t start = clock();
    test_1();
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    start = clock();
    test_2();
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    
    return 0;
}
