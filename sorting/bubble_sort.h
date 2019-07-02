/*
  Bubble sort
  02/07/2019
 */

#ifndef ALGORITHMS_SORTING_BUBBLE_SORT_H_
#define ALGORITHMS_SORTING_BUBBLE_SORT_H_

#include <vector>

template <typename T>
class BubbleSort {
public:
    BubbleSort();
    ~BubbleSort();

    void sort(std::vector<T>& v);

private:
    void m_swap(T& a, T& b);
};

template <typename T>
BubbleSort<T>::BubbleSort() {}

template <typename T>
BubbleSort<T>::~BubbleSort() {}

template <typename T>
void BubbleSort<T>::sort(std::vector<T>& v) {
    for (std::size_t i = 0; i < v.size() - 1; ++i)
        for (std::size_t j = i + 1; j < v.size(); ++j)
            if (v[i] > v[j])
                m_swap(v[i], v[j]);
}

template <typename T>
void BubbleSort<T>::m_swap(T& a, T& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

#endif // ALGORITHMS_SORTING_BUBBLE_SORT_H_
