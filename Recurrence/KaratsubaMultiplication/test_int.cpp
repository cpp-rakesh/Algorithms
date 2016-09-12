#include "Integer.h"

int main() {
    Integer A("9");
    Integer B("1009");

    Integer C = A - B;

    A.Print();
    B.Print();
    C.Print();
    
    return 0;
}
