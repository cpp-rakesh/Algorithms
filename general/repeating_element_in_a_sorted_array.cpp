/*
  Rakesh Kumar
  Never stop learning
  Problem : Find the only repeating element in a sorted array of size n
  20/05/2021
 */

#include <bits/stdc++.h>

/*
  Time complexity O(n)
 */
int find_duplicate_iter(const std::vector<int>& v) {
    int r = 0;
    for (std::size_t i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            r = v[i];
            break;
        }
    }
    return r;
}

/*
  Time Complexity O(log2(n))
 */
int find_duplicate_dac(const std::vector<int>& v, int s, int e) {
    if (s > e)
        return -1;
    const int mid = (s + e) >> 1;
    if (v[mid] != mid + 1) {
        if (mid > 0 && v[mid]==v[mid-1])
            return v[mid];
        return find_duplicate_dac(v, s, mid-1);
    }
    return find_duplicate_dac(v,mid+1,e);
}

int main() {
    std::vector<int> v1 = {1,2,3,4,4,5,6,7};
    printf("duplicate value == [%d]\n", find_duplicate_iter(v1));
    printf("duplicate value == [%d]\n", find_duplicate_dac(v1, 0, v1.size()));

    return 0;
}
