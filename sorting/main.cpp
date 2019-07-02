/*
  test all the sorting algorithms
  02/07/2019
 */

#include "insertion_sort.h"
#include <bits/stdc++.h>

inline int random(int s, int e) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(s, e);
    return dt(rd);
}

inline std::vector<int> get(int n) {
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
        v.push_back(random(0, 100));
    return v;
}

inline void print(const std::vector<int>& v) {
    printf("--------------------------------------------------------------\n");
    for (const auto& x : v)
        printf("%d ", x);
    printf("\n--------------------------------------------------------------\n");
}

void test() {
    const int n = 20;
    using clock = std::chrono::steady_clock;
    std::vector<int> v1 = get(n);
    print(v1);

    InsertionSort<int> is;
    clock::time_point start = clock::now();
    is.sort(v1);
    clock::time_point end = clock::now();
    print(v1);
    printf("Execution time for insertion sort == [%.2f] seconds\n",
           std::chrono::duration<double>(end - start).count());
}

int main() {
    test();

    return 0;
}
