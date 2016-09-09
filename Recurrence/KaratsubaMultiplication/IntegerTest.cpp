#include "Integer.h"
#include <ctime>

void factorial() {
    std::clock_t start = clock();
    Integer A(0);
    Integer B(1);

    for (int i = 0; i < 50000; ++i) {
        Integer C = A + B;
        A = B;
        B = C;
    }
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    B.Print();
}

int main() {
    factorial();

    return 0;
}
