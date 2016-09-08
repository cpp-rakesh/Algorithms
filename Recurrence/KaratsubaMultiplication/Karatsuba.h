#ifndef ALGORITHM_RECURRENCE_KARATSUBA_H_
#define ALGORITHM_RECURRENCE_KARATSUBA_H_

/*
  Implementation of Karatsuba Multiplication algorithm.
  This implmentation has n ^ (lg 3) time complexity, which is lower
  than the normal one n ^ 2 to multiply two numbers.

  Author: Rakesh Kumar, cpp.rakesh@gmail.com
  Date: September 9, 2016.
 */

#include <cstdio>
#include <string>
#include <vector>

namespace RECURRENCE {
    class Karatsuba {
    public:
        Karatsuba();
        ~Karatsuba();

        // Two numbers are passed as strings
        // Let the are coming as noraml in this order. 12345 and 12345
        // Last number is positioned at the end of the string.
        std::string Multiply(const std::string& A, const std::string& B);        
    };  
};

#endif // ALGORITHM_RECURRENCE_KARATSUBA_H_
