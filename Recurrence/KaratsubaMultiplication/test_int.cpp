#include "Integer.h"

int main() {
    Integer A("9");
    Integer B("1090");

    Integer C = B - A;

    A.Print();
    B.Print();
    C.Print();
    
    return 0;
}
