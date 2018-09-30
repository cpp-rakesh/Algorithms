#include "karatsuba.h"
#include "multiplication.h"
#include "integer.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <random>
#include <chrono>

char get_random() {
    const int MIN = 0;
    const int MAX = 9;
    std::random_device rd;
    std::uniform_int_distribution<> dt(MIN, MAX);
    return dt(rd) + '0';
}

void test_multiply_normal(const std::string& A, const std::string& B) {
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    RECURRENCE::Multiplication mul;
    std::string result = mul.Multiply(A, B);
    printf("Execution time == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));
    printf("Result ---------->");
    for (int i = result.size() - 1; i >= 0; --i)
        printf("%c", result[i]);
    printf("\n");
}

void test_kratsuba(const std::string& A, const std::string& B) {
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    RECURRENCE::Karatsuba mul;
    RECURRENCE::Integer result = mul.Multiply(A, B);
    printf("Execution time == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));
    printf("Result ---------->");
    result.Print();
}

void test() {
    const int a_len = 200;
    const int b_len = 150;

    std::string A;
    for (int i = 0; i < a_len; ++i)
        A.push_back(get_random());

    std::string B;
    for (int i = 0; i < b_len; ++i)
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
