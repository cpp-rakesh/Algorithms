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

int main() {
    test_normal_string();

    return 0;
}
