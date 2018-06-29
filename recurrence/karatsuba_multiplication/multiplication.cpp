#include "Multiplication.h"
#include <cstdio>

RECURRENCE::Multiplication::Multiplication() {}

RECURRENCE::Multiplication::~Multiplication() {}

std::string RECURRENCE::Multiplication::Multiply(const std::string& A, const std::string& B) {
    std::string number;

    for (int i = A.size() - 1; i >= 0; --i) {
        std::string temp;

        // Add leading zeros for summing up all multiplications one by one.
        for (int j = 0; j < A.size() - 1 - i; ++j)
            temp.push_back('0');

        int carry = 0;
        for (int j = B.size() - 1; j >= 0; --j) {
            const int mul = carry + ((A[i] - '0') * (B[j] - '0'));
            temp.push_back((mul % 10) + '0');
            carry = mul / 10;
        }

        while (carry) {
            temp.push_back((carry % 10) + '0');
            carry /= 10;
        }

        m_add(number, temp);
    }

    return number;
}

void RECURRENCE::Multiplication::m_add(std::string& A, const std::string& B) {
    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t carry = 0;

    while (i < A.size() && j < B.size()) {
        const int sum = carry + (A[i] - '0') + (B[j++] - '0');
        A[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Leftover from A
    while (i < A.size()) {
        const int sum = (A[i] - '0') + carry;
        A[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Leftover from B
    while (j < B.size()) {
        const int sum = (B[j++] - '0') + carry;
        A.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    // left over from carry
    while (carry) {
        A.push_back((carry % 10) + '0');
        carry /= 10;
    }
}
