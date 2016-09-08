#include "Multiplication.h"
#include <cstdio>
#include <ctime>
#include <algorithm>

const int MIN = 0;
const int MAX = 9;

const int random_number() {
    return MIN + rand() % (MAX - MIN + 1);
}

// Argument is the size of the random number generated
std::string get_random_number_string(const int& n) {
    std::string number;
    for (int i = 0; i < n; ++i)
        number.insert(0, 1, random_number() + '0');
    return number;
}

// Argument is the size of the random number generated
std::deque<int> get_random_number(const int& n) {
    std::deque<int> number;
    for (int i = 0; i < n; ++i)
        number.push_front(random_number());
    return number;
}

void test_normal_string() {
    const int a_length = 1000;
    const int b_length = 1000;    
    RECURRENCE::Multiplication mul;
    std::string A = get_random_number_string(a_length);
    std::string B = get_random_number_string(b_length);
    std::clock_t start = clock();
    std::string C = mul.Multiply(A, B);
    printf("Exeuction time for normal multiplication data stored in string == [%.8f] seconds\n",
           (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));    
    std::reverse(A.begin(), A.end());    
    std::reverse(B.begin(), B.end());
    std::reverse(C.begin(), C.end());
    printf("[%s] X [%s] == [%s]\n", A.c_str(), B.c_str(), C.c_str());    
}

void print_deque(const std::deque<int>& D) {
    for (int i = D.size() - 1; i >= 0; --i)
        printf("%d", D[i]);
}

void test_normal_number() {
    const int a_length = 1000;
    const int b_length = 1000;    
    RECURRENCE::Multiplication mul;
    std::deque<int> A = get_random_number(a_length);
    std::deque<int> B = get_random_number(b_length);
    std::clock_t start = clock();
    std::deque<int> C = mul.Multiply(A, B);
    printf("Exeuction time for normal multiplication data stored in deque  == [%.8f] seconds\n",
           (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("[");
    print_deque(A);
    printf("] X [");
    print_deque(B);
    printf("] == [");
    print_deque(C);
    printf("]\n");
}

int main() {
    test_normal_string();
    test_normal_number();
    
    return 0;
}
