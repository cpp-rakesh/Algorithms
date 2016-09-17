#include "Integer.h"

void test_a() {
    Integer A("2");
    Integer B("5");
    for (int i = 0; i < 10; ++i) {
fg
    A = A + B;
        A.Print();
    }
}

int main() {
    test_a();
    
    return 0;
}
