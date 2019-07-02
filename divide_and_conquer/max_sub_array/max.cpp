/*
  Max subarray problem
  03/07/2019
 */

#include <bits/stdc++.h>

#define mt std::make_tuple
#define tp std::tuple<int, int, int>

inline void print(const std::vector<int>& v) {
    printf("----------------------------------------------------\n");
    for (const auto& x : v)
        printf("%d ", x);
    printf("\n----------------------------------------------------\n");
}

inline int random(int s, int e) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(s, e);
    return dt(rd);
}

inline std::vector<int> get(int n) {
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
        v.push_back(random(-10, 10));
    return v;
}

/*
  This is the simplest iterative approach
  O(n^2)
 */
inline tp max_itr(const std::vector<int>& v) {
    tp max = mt(v[0], 0, 0);

    for (std::size_t i = 0; i < v.size(); ++i) {
        int sum = v[i];
        for (std::size_t j = i + 1; j < v.size(); ++j) {
            sum += v[j];
            if (sum > std::get<0>(max)) {
                max = mt(sum, i, j);
            }
        }
    }

    return max;
}

inline tp max_sum_cross(const std::vector<int>& v, int s, int m, int e) {
    tp left = mt(v[m], m, m);
    int max = v[m];
    for (int i = m - 1; i >= s; --i) {
        max += v[i];
        if (max > std::get<0>(left))
            left = mt(max, i, i);
    }

    tp right = mt(v[m + 1], m + 1, m + 1);
    max = v[m + 1];
    for (int i = m + 2; i <= e; ++i) {
        max += v[i];
        if (max > std::get<0>(right))
            right = mt(max, i, i);
    }

    return mt(std::get<0>(left) + std::get<0>(right), std::get<1>(left), std::get<1>(right));
}

/*
  This is the divide and conquer approach
  O(nlgn)
 */
inline tp max_dac(const std::vector<int>&v, int s, int e) {
    if (s == e)
        return std::make_tuple(v[s], s, s);
    if (s < e) {
        const int m = (s + e) >> 1;
        const tp left = max_dac(v, s, m);
        const tp right = max_dac(v, m + 1, e);
        const tp cross = max_sum_cross(v, s, m, e);
        if (std::get<0>(left) > std::get<0>(right) &&
            std::get<0>(left) > std::get<0>(cross))
            return left;
        else if (std::get<0>(right) > std::get<0>(left) &&
                 std::get<0>(right) > std::get<0>(cross))
            return right;
        else
            return cross;
    }
}

inline void test() {
    const std::vector<int> v = get(10);
    print(v);
    tp max1 = max_itr(v);
    printf("Max sub array from [%d] to [%d] == [%d]\n",
           std::get<1>(max1), std::get<2>(max1), std::get<0>(max1));
    tp max2 = max_dac(v, 0, v.size() - 1);
    printf("Max sub array from [%d] to [%d] == [%d]\n",
           std::get<1>(max2), std::get<2>(max2), std::get<0>(max2));

}

int main() {
    test();

    return 0;
}
