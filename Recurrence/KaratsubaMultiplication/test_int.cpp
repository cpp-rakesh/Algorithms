#include "Integer.h"
#include "Multiplication.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>

Integer power(const int x, int y) {
    if (y == 1) {
        return Integer(x);
    } else {
        if (y % 2 == 0) {
            Integer value = power(x, y / 2);
            return value * value;
        } else {
            Integer value = power(x, y / 2);
            return value * value * x;
        }
    }
}

Integer Karatsuba(Integer& A, const Integer& B) {
    // Let's do the normal multiplication of n ^ 2
    // When A or B has atleast 5 digit number, otherwise.
    // Love to recurse.
    if (A.Size() <= 5 || B.Size() <= 5) {
#if 0
        printf("-------------------------- return A * B -----------------------------\n");
        A.Print();
        B.Print();
        (A * B).Print();
        printf("-------------------------- return A * B -----------------------------\n");
#endif
        return A * B;
    } else {
        const int m = A.Size() < B.Size() ? A.Size() : B.Size();
        const int m2 = m / 2;
#if 0
        printf("m == [%d] || m2 == [%d]\n", m, m2);
#endif

        Integer AH;
        Integer AL;
        A.Split(m2, AH, AL);
#if 0
        printf("A -- > ");
        A.Print();
        printf("AH - > ");
        AH.Print();
        printf("AL - > ");
        AL.Print();
#endif
        Integer BH;
        Integer BL;
        B.Split(m2, BH, BL);
#if 0
        printf("B -- > ");
        B.Print();
        printf("BH - > ");
        BH.Print();
        printf("BL - > ");
        BL.Print();        
#endif
        Integer F = AL + AH;
        Integer S = BL + BH;
        Integer z0 = Karatsuba(AL, BL);
        Integer z1 = Karatsuba(F, S);
        Integer z2 = Karatsuba(AH, BH);

        Integer p1 = power(10, 2 * m2);
        Integer p2 = power(10, m2);

#if 0
        printf("z2 * p1 === ");
        (z2 * p1).Print();
        printf("z1 - z2 - z0 * p2--- > > > ");
        ((z1 - z2 - z0) * p2).Print();        
        printf("z0 --- > ");
        z0.Print();
#endif        

        return (z2 * p1) + ((z1 - z2 - z0) * p2) + (z0);
    }
}

char get_random() {
    const int MIN = 0;
    const int MAX = 9;
    return (MIN + rand() % (MAX - MIN) + 1) + '0';
}

void test_multiply_normal(const std::string& A, const std::string& B) {
    std::clock_t start = clock();
    RECURRENCE::Multiplication mul;
    std::string result = mul.Multiply(A, B);
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("Result ---------->");
    for (int i = result.size() - 1; i >= 0; --i)
        printf("%c", result[i]);
    printf("\n");
}

void test_kratsuba(const std::string& A, const std::string& B) {
    std::clock_t start = clock();
    Integer IA(A);
    Integer IB(B);
    Integer result = Karatsuba(IA, IB);
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("Result ---------->");    
    result.Print();
}

void test() {
    const int A_LEN = 20000;
    const int B_LEN = 15000;
    
    std::string A;
    for (int i = 0; i < A_LEN; ++i)
        A.push_back(get_random());

    std::string B;
    for (int i = 0; i < B_LEN; ++i)
        B.push_back(get_random());

    printf("A == [%s]\n", A.c_str());
    printf("B == [%s]\n", B.c_str());    
    
    test_multiply_normal(A, B);
    test_kratsuba(A, B);
}

int main() {
    test();

    return 0;
}
