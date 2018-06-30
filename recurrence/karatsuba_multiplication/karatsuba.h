#ifndef ALGORITHM_RECURRENCE_KARATSUBA_H_
#define ALGORITHM_RECURRENCE_KARATSUBA_H_

/*
  Implementation of Karatsuba Multiplication algorithm.
  This implmentation has n ^ (lg 3) time complexity, which is lower
  than the normal one n ^ 2 to multiply two numbers.

  Author: Rakesh Kumar, cpp.rakesh@gmail.com
  Date: September 9, 2016.
 */

#include "integer.h"

namespace RECURRENCE {
    class Karatsuba {
    public:
        Karatsuba();
        ~Karatsuba();

        // Two numbers are passed as strings
        // Let the are coming as noraml in this order. 12345 and 12345
        // Last number is positioned at the end of the string.
        Integer Multiply(const Integer& A, const Integer& B);

    private:
        Integer m_power(int x, int y);
    };
};

#endif // ALGORITHM_RECURRENCE_KARATSUBA_H_
