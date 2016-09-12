#include "Integer.h"
#include <ctime>

void test() {
    std::clock_t start = clock();
    Integer A("1000000000000000000000000000000000");
    Integer B("100");

    for (int i = 0; i < 100000000; ++i)
        A += B;

    A.Print();
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}

int main() {
    test();

    return 0;
}
