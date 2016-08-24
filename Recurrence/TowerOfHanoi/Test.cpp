//#include "TowerOfHanoi.h"
#include "TowerOfHanoiIterative.h"
#include <ctime>

#if 0
void test_recursive() {
	const int n = 5;
	RECURRENCE::Tower<int> tower(SOURCE);
	for (int i = 0; i < n; ++i)
		tower.Front(i + 1);
	std::clock_t start = clock();
	RECURRENCE::TowerOfHanoi<int> hanoi;
	hanoi.Compute(tower);	
	std::cout << "Execution time == [" << (clock() - start) / static_cast<double>(CLOCKS_PER_SEC) << "] seconds"
			  << std::endl;	
}
#endif
void test_iterative() {
	const int n = 4;	
	RECURRENCE::Tower<int> A(SOURCE);
	RECURRENCE::Tower<int> B(TEMP);
	RECURRENCE::Tower<int> C(TARGET);	
	for (int i = 0; i < n; ++i)
		A.Front(i + 1);
	TowerOfHanoi<int> hanoi;
	hanoi.Compute(A, B, C);
}

int main() {
	//test_recursive();
	test_iterative();

	return 0;
}
