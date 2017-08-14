/*
  Dynamic Programming Example.
  Pascal Triangle and calculating with binomial coffiecent.
  
  Rakesh Kumar @ 14/08/2017
 */

#include <cstdio>
#include <vector>
#include <cstdlib>

inline int min(double a, double b) {
    return a < b ? a : b;
}

inline int max(double a, double b) {
    return a > b ? a : b;
}

// Choose k elements from n
// Or we can say cofficent of (a + b) ^ n
double binomial(double n, double k) {
    std::vector<double> b;
    for (double i = 0; i <= k; ++i)
        b.push_back(0);

    b[0] = 1;
    
    for (double i = 1; i <= n; ++i)
        for (double j = min(i, k); j > 0; --j)
            b[j] += b[j - 1];

    return b[k];
}

inline int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

void test_binomail() {
    for (double i = 0; i < 10; ++i) {
        const int a = random(1, 100);
        const int b = random(1, 100);
        const int n = max(a, b);
        const int k = min(a, b);
        printf("(%8d %8d) == [%32.0lf]\n", n, k, binomial(n, k));
    }
}

void test_pascal_triangle() {
    int n = 20;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j)
            printf("%8.0lf ", binomial(i, j));
        printf("\n");
    }
}

int main() {
    //test_binomail();
    test_pascal_triangle();

    return 0;
}
