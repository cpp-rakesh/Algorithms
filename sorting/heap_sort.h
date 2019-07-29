/*
  Heap sort
  02/07/2019
 */

#ifndef ALGORITHMS_SORTING_HEAP_SORT_H_
#define ALGORITHMS_SORTING_HEAP_SORT_H_

#include <vector>

template <typename T>
class HeapSort {
public:
    HeapSort();
    ~HeapSort();

    void sort(std::vector<T>& v);

private:
    void m_build_heap(std::vector<T>& v);
    void m_maxify(std::vector<T>& v, std::size_t p, std::size_t s);
    void m_swap(T& a, T& b);
    std::size_t m_left(std::size_t p) const;
    std::size_t m_right(std::size_t p) const;
};

template <typename T>
HeapSort<T>::HeapSort() {}

template <typename T>
HeapSort<T>::~HeapSort() {}

template <typename T>
void HeapSort<T>::sort(std::vector<T>& v) {
    m_build_heap(v);
    for (int i = v.size() - 1; i > 0; --i) {
        m_swap(v[i], v[0]);
        m_maxify(v, 0, i);
    }
}

template <typename T>
void HeapSort<T>::m_build_heap(std::vector<T>& v) {
    for (int i = v.size() >> 1; i >= 0; --i)
        m_maxify(v, i, v.size());
}

template <typename T>
void HeapSort<T>::m_maxify(std::vector<T>& v, std::size_t p, std::size_t s) {
    while (1) {
        std::size_t l = m_left(p);
        std::size_t r = m_right(p);

        std::size_t largest = p;
        if (l < s && v[l] > v[largest])
            largest = l;
        if (r < s && v[r] > v[largest])
            largest = r;
        if (largest == p)
            break;
        else
            m_swap(v[largest], v[p]);
        p = largest;
    }
}

template <typename T>
void HeapSort<T>::m_swap(T& a, T& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

template <typename T>
std::size_t HeapSort<T>::m_left(std::size_t p) const {
    return (p << 1) + 1;
}

template <typename T>
std::size_t HeapSort<T>::m_right(std::size_t p) const {
    return (p << 1) + 2;
}

#endif // ALGORITHMS_SORTING_HEAP_SORT_H_
