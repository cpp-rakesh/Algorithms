/*
  Merge sort
  02/07/2019
 */

#ifndef ALGORITHMS_SORTING_MERGE_SORT_H_
#define ALGORITHMS_SORTING_MERGE_SORT_H_

#include <vector>

template <typename T>
class MergeSort {
public:
    MergeSort();
    ~MergeSort();

    void sort(std::vector<T>& v);

private:
    void m_sort(std::vector<T>& v, int s, int e);
    void m_merge(std::vector<T>& v, int s, int m, int e);
};

template <typename T>
MergeSort<T>::MergeSort() {}

template <typename T>
MergeSort<T>::~MergeSort() {}

template <typename T>
void MergeSort<T>::sort(std::vector<T>& v) {
    m_sort(v, 0, v.size() - 1);
}

template <typename T>
void MergeSort<T>::m_sort(std::vector<T>& v, int s, int e) {
    if (s < e) {
        const int m = (s + e) >> 1;
        m_sort(v, s, m);
        m_sort(v, m + 1, e);
        m_merge(v, s, m, e);
    }
}

template <typename T>
void MergeSort<T>::m_merge(std::vector<T>& v, int s, int m, int e) {
    std::vector<T> left;
    for (std::size_t i = s; i <= m; ++i)
        left.push_back(v[i]);
    std::vector<T> right;
    for (std::size_t i = m + 1; i <= e; ++i)
        right.push_back(v[i]);

    std::size_t l = 0;
    std::size_t r = 0;
    std::size_t i = s;
    while (l < left.size() && r < right.size())
        if (left[l] < right[r])
            v[i++] = left[l++];
        else
            v[i++] = right[r++];

    while (l < left.size())
        v[i++] = left[l++];
    while (r < right.size())
        v[i++] = right[r++];
}

#endif // ALGORITHMS_SORTING_MERGE_SORT_H_
