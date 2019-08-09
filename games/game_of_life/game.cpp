#include "universe.h"
#include <cstdio>

int main() {
    Universe uni(32);

    while (1) {
        uni.print();
        uni.generate();
        getchar();
    }

    return 0;
}
