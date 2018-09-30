#include "queens.h"
#include <cstdio>
#include <ctime>
#include <chrono>

void test_get_total() {
    algorithms::backtracking::Queens queen;
    for (int n = 1; n <= 15; ++n) {
        using clock = std::chrono::steady_clock;
        clock::time_point start = clock::now();
        printf("------------------------------------------------\n");
        printf("N == [%d] || Total == [%d]\n", n, queen.Total(n));
        printf("Execution time     == [%16f] seconds\n",
               std::chrono::duration<double>(clock::now() - start));
        printf("------------------------------------------------\n");
    }
}

void test_draw_all(int n) {
    algorithms::backtracking::Queens queen;
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    queen.ComputeAll(n);
    printf("Execution time     == [%16f] seconds\n",
           std::chrono::duration<double>(clock::now() - start));
}

int main() {
    //test_get_total();
    test_draw_all(20);

    return 0;
}
