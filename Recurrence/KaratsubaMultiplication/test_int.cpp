#include "Integer.h"

int main() {
    Integer A("100");
    A.Print();
    
    A -= "200000";
    
    A.Print();
    
    return 0;
}
