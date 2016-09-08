#include "Multiplication.h"
#include <cstdio>

RECURRENCE::Multiplication::Multiplication() {}

RECURRENCE::Multiplication::~Multiplication() {}

std::string RECURRENCE::Multiplication::Multiply(const std::string& A, const std::string& B) {
    std::string result;
    for (std::size_t i = 0; i < A.length(); ++i) {
        std::string result_for_addition;
        // Adding last zero's
        for (int k = 0; k < i; ++k)
            result_for_addition.push_back('0');

        int carry = 0;
        for (std::size_t j = 0; j < B.length(); ++j) {
            const int sum = ((A[i] - '0') * (B[j] - '0')) + carry;
            result_for_addition.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        while (carry) {
            result_for_addition.push_back((carry % 10) + '0');
            carry /= 10;
        }
        
        m_add(result_for_addition, result);
    }

    return result;
}

void RECURRENCE::Multiplication::m_add(const std::string& A, std::string& B) {
    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t carry = 0;

    while (i < A.length() && j < B.length()) {
        const int sum = (A[i] - '0') + (B[j] - '0') + carry;
        B[j] = (sum % 10) + '0';
        carry = sum / 10;
        ++i;
        ++j;
    }

    // Leftover from A
    while (i < A.length()) {
        const int sum = (A[i] - '0') + carry;
        B.push_back(sum % 10 + '0');
        carry = sum / 10;
        ++i;
    }

    // left over from carry
    while (carry) {
        B.push_back((carry % 10) + '0');
        carry /= 10;
    }
}
