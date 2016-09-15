#include "Integer.h"
#include <ctime>

int main() {
    Integer A("1129");
    Integer B("-89");

    Integer C = A - B;
    C.Print();
    
    return 0;
}
