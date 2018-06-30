#include "karatsuba.h"

RECURRENCE::Karatsuba::Karatsuba() {}

RECURRENCE::Karatsuba::~Karatsuba() {}

RECURRENCE::Integer RECURRENCE::Karatsuba::Multiply(const Integer& A, const Integer& B) {
    // Let's do the normal multiplication of n ^ 2
    // When A or B has atleast 5 digit number, otherwise.
    // Love to recurse.
    if (A.Size() <= 5 || B.Size() <= 5) {
        Integer R = const_cast<Integer&>(A) * B;
        return R;
    } else {
        const int m = A.Size() < B.Size() ? A.Size() : B.Size();
        const int m2 = m / 2;

        Integer AH;
        Integer AL;
        A.Split(m2, AH, AL);

        Integer BH;
        Integer BL;
        B.Split(m2, BH, BL);

        Integer z0 = Multiply(AL, BL);
        Integer z1 = Multiply((AL + AH), (BL + BH));
        Integer z2 = Multiply(AH, BH);

        Integer p1 = m_power(10, 2 * m2);
        Integer p2 = m_power(10, m2);

        return (z2 * p1) + ((z1 - z2 - z0) * p2) + (z0);
    }
}

RECURRENCE::Integer RECURRENCE::Karatsuba::m_power(int x, int y) {
    if (y == 1) {
        return Integer(x);
    } else {
        if (y % 2 == 0) {
            Integer value = m_power(x, y / 2);
            return value * value;
        } else {
            Integer value = m_power(x, y / 2);
            return value * value * x;
        }
    }
}
