/*
  test all the sorting algorithms
  02/07/2019
 */

#include "insertion_sort.h"
#include "merge_sort.h"
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
    /*
    printf("--------------------------------------------------------------\n");
    for (const auto& x : v)
        printf("%d ", x);
    printf("\n--------------------------------------------------------------\n");
    */
}

inline void test_insertion_sort(std::vector<int>& v) {
    using clock = std::chrono::steady_clock;
    print(v);

    InsertionSort<int> sort;
    clock::time_point start = clock::now();
    sort.sort(v);
    clock::time_point end = clock::now();
    print(v);
    printf("Execution time for insertion sort == [%.2f] seconds\n",
           std::chrono::duration<double>(end - start).count());
}

inline void test_merge_sort(std::vector<int>& v) {
    using clock = std::chrono::steady_clock;
    print(v);

    MergeSort<int>  sort;
    clock::time_point start = clock::now();
    sort.sort(v);
    clock::time_point end = clock::now();
    print(v);
    printf("Execution time for merge sort     == [%.2f] seconds\n",
           std::chrono::duration<double>(end - start).count());
}

void test() {
    const int n = 50000;
    std::vector<int> v1 = get(n);
    std::vector<int> v2 = v1;

    test_insertion_sort(v1);
    test_merge_sort(v2);
}

int main() {
    test();

    return 0;
}
