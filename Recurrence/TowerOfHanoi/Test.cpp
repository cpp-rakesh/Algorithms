#include "TowerOfHanoi.h"
#include <ctime>

int main() {
	const int n = 10;
	RECURRENCE::Tower<int> tower(SOURCE);
	for (int i = 0; i < n; ++i)
		tower.Push(i + 1);
	std::clock_t start = clock();
	RECURRENCE::TowerOfHanoi<int> hanoi;
	hanoi.Compute(tower);	
	std::cout << "Execution time == [" << (clock() - start) / static_cast<double>(CLOCKS_PER_SEC) << "] seconds"
			  << std::endl;

	return 0;
}
