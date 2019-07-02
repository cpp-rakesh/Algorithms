/*
  Insertion sort
  02/07/2019
 */

#ifndef ALGORITHMS_SORTING_INSERTION_SORT_H_
#define ALGORITHMS_SORTING_INSERTION_SORT_H_

#include <vector>

template <typename T>
class InsertionSort {
public:
    InsertionSort();
    ~InsertionSort();
    void sort(std::vector<T>& v);

private:
    void m_swap(T& a, T& b);
};

template <typename T>
InsertionSort<T>::InsertionSort() {}

template <typename T>
InsertionSort<T>::~InsertionSort() {}

template <typename T>
void InsertionSort<T>::sort(std::vector<T>& v) {
    for (std::size_t i = 1; i < v.size(); ++i) {
        std::size_t j = i;
        while (j >= 1 && v[j] < v[j - 1]) {
            m_swap(v[j], v[j - 1]);
            --j;
        }
    }
}

template <typename T>
void InsertionSort<T>::m_swap(T& a, T& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

#endif // ALGORITHMS_SORTING_INSERTION_SORT_H_
