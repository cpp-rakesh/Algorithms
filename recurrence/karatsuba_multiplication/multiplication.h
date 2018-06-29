#ifndef ALGORITHM_KARATSUBA_MULTIPLY_H_
#define ALGORITHM_KARATSUBA_MULTIPLY_H_

/*
  It is the implementation of normal school grade mathematics.
  Multiply every digit of second with first and sum all.
  Time complexity is n ^ 2 and addition n times.
*/

#include <string>
#include <deque>

namespace RECURRENCE {
    class Multiplication {
    public:
        Multiplication();
        ~Multiplication();

        // Make sure the data is coming in the reverse order as the
        // numbers multiplication start from the last to the first digit.
        // Even addition and subtraction happens this way only.
        std::string Multiply(const std::string& A, const std::string& B);

        // First arguement is the const one as just need this to B.
        // Where every time B holds all the result
        void m_add(std::string& A, const std::string& B);
    };
};

#endif // ALGORITHM_KARATSUBA_MULTIPLY_H_
