#include "queens.h"
#include <cstdio>
#include <ctime>

void test_get_total() {
    algorithms::backtracking::Queens queen;
    for (int n = 1; n <= 15; ++n) {
        std::clock_t start = clock();
        printf("------------------------------------------------\n");
        printf("N == [%d] || Total == [%d]\n", n, queen.Total(n));
        printf("Execution time     == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
        printf("------------------------------------------------\n");
    }
}

void test_draw_all(int n) {
    algorithms::backtracking::Queens queen;
    std::clock_t start = clock();
    queen.ComputeAll(n);
    printf("Execution time     == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}

int main() {
    //test_get_total();
    test_draw_all(20);

    return 0;
}
