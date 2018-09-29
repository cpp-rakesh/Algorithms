/*
  Find the closest pair distance from a set S, which has 1 d space points.
  At least 2 points in the set to calculate the minimum euclidean distance.
 */

#include <bits/stdc++.h>

typedef std::pair<double, double> point;
typedef std::vector<point>  set;

double euclidean_distance(point& a,
                          point& b) {
    return std::sqrt(((a.first  - b.first)  * (a.first  - b.first)) +
                     ((a.second - b.second) * (a.second - b.second)));
}

double random(int s, int e) {
    std::random_device rd;
    std::uniform_real_distribution<> urd(s, e);
    return urd(rd);
}

set get(int n) {
    set s;
    for (int i = 0; i < n; ++i)
        s.emplace_back(point(random(1, 1e+4), random(1, 1e+4)));
    return s;
}

void print(const set& s) {
    for (std::size_t i = 0; i < s.size(); ++i)
        printf("%8d. (%16lf, %16lf)\n", i, s[i].first, s[i].second);
}

/*
  This algorithm is the slowest of all.
  Will compare all elements with each and other
  and will find out the minimum distance
  Time complexity O(n ^ 2)
 */

double n_2(set& s) {
    double min = euclidean_distance(s[0], s[1]);
    for (std::size_t i = 0; i < s.size() - 1; ++i)
        for (std::size_t j = i + 1; j < s.size(); ++j)
            min = std::min(min, euclidean_distance(s[i], s[j]));
    return min;
}

/*
  This algorithm is based on divide and Conquer
  1. sort on x axis.
  2. divide the set into two halves
  3. Let S1 and S2.
  4. Compute the minimum distance of left set and right set
  5. And then prepare those points which has distance in the range of minimum relative to the median point.
  Time Complexity O(nlgn + n)
 */

double strip_min(set& s) {
    std::sort(s.begin(), s.end(), [](point a, point b) {
            return a.second < b.second;
        });
    double min = euclidean_distance(s[0], s[1]);
    for (std::size_t i = 0; i < s.size() - 1; ++i)
        for (std::size_t j = i + 1; j < s.size() && (s[j].second - s[i].second) < min; ++j)
            min = std::min(min, euclidean_distance(s[i], s[j]));

    return min;
}

double nlgn_n(set& s, int a, int b) {
    while (a < b) {
        if (a + 1 == b)
            return euclidean_distance(s[a], s[b]);

        const int m = (a + b) >> 1;
        const double l_m = nlgn_n(s, a, m);
        const double r_m = nlgn_n(s, m + 1, b);
        double min = std::min(l_m, r_m);

        set strip;
        for (int i = a; i <= b; ++i) {
            if (std::abs(s[i].first - s[m].first) < min)
                strip.push_back(s[i]);
        }

        if (strip.size() < 2)
            return min;
        else
            return std::min(min, strip_min(strip));
    }
}

void test_n_2(set& s) {
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    printf("(O(n ^ 2)  Closest pair Euclidean distance == [%lf]\n", n_2(s));
    printf("(Execution time == [%lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));
}

void test_nlgn_n(set& s) {
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    std::sort(s.begin(), s.end(), [](point a, point b) {
            return a.first < b.first;
        });
    printf("(O(nlgn_n) Closest pair Euclidean distance == [%lf]\n", n_2(s));
    printf("(Execution time == [%lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));
}

int main() {
    const int n = 1e+4;
    set s1 = get(n);
    set s2 = s1;
    print(s1);

    test_n_2(s1);
    test_nlgn_n(s2);

    return 0;
}
