/*
  Find the closest pair distance from a set S, which has 1 d space points.
 */

#include <bits/stdc++.h>

const int INF = 1e+8 + 1;

/*
  For all the problems we consider that the 1d space set must have
  at least 2 points.
 */

int random(int s, int e) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(s, e);
    return dt(rd);
}

std::vector<int> get(int n) {
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
        v.push_back(random(-1e+8, 1e+8));
    return v;
}

void print(const std::vector<int>& v) {
    printf("------------------------ Number of points in 1d space ------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}

/*
  This algorithm actually has time complexity of n^2.
  Because first it has n iterations of n - 1.
  And therefore, it will go on for n(n - 1) times.
  Which is n^2 time complexity
*/

int n_2(const std::vector<int>& p) {
    int min = std::abs(p[0] - p[1]);
    for (std::size_t i = 0; i < p.size() - 1; ++i)
        for (std::size_t j = i + 1; j  < p.size(); ++j)
            min = std::min(min, std::abs(p[i] - p[j]));
    return min;
}

/*
  This algorithm will first sort the set of 1d points in ascending order.
  Then we will run through all the points and will find the min of the adjacent points.
  Time complexity O(nlgn) for sorting and n for finding the min pair.
  Time Complexity O(nlgn + n)
 */

int nlgn_n(std::vector<int>& p) {
    std::sort(p.begin(), p.end());
    int min = p[1] - p[0];
    for (std::size_t i = 2; i < p.size(); ++i)
        min = std::min(min, p[i] - p[i - 1]);
    return min;
}

/*
  This algorithm is based on divide and conquer.
  1. First sort the set of 1d space points.
  2. divide the set into two with atleast 2 points each
  3. get min of S1, and S2.
  4. Try to find out the min of those points which are crossing the median point
  relative to the median value.
  Time complexity of this sort(nlgn), and for finding the min O(lgn), O(nlgn + lgn)
 */

int nlgn_lgn(std::vector<int>& p, int s, int e) {
    while (s < e) {
        if (s + 1 == e)
            return p[e] - p[s];

        const int m = (s + e) >> 1;
        const int l_m = nlgn_lgn(p, s, m);
        const int r_m = nlgn_lgn(p, m + 1, e);

        int min = std::min(l_m, r_m);

        for (int i = s; i <= e; ++i)
            if (i != m)
                min = std::min(min, std::abs(p[i] - p[m]));

        return min;
    }

    return INF;
}

void test_n_2(std::vector<int>& p) {
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    printf("(O(n ^ 2)    Closest pair distance == [%d]\n", n_2(p));
    printf("(Execution time == [%lf] seconds\n",
           clock::now() - start);
}

void test_nlgn_n(std::vector<int>& p) {
    std::clock_t start = std::clock();
    printf("(O(nlgn_n)   Closest pair distance == [%d]\n", nlgn_n(p));
    printf("(Execution time == [%lf] seconds\n",
           (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}

void test_nlgn_lgn(std::vector<int>& p) {
    std::clock_t start = std::clock();
    std::sort(p.begin(), p.end());
    printf("(O(nlgn_lgn) Closest pair distance == [%d]\n", nlgn_lgn(p, 0, p.size() - 1));
    printf("(Execution time == [%lf] seconds\n",
           (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}

int main() {
    const int n = 1e+5;
    std::vector<int> p1 = get(n);
    std::vector<int> p2 = p1;
    std::vector<int> p3 = p1;
    print(p1);

    test_n_2(p1);
    test_nlgn_n(p2);
    test_nlgn_lgn(p3);

    return 0;
}
