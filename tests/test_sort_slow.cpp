#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cstring>
#include <algorithm>

#include "../src/radixSort_slow.hpp"

int main (int argc, char *argv[]) {
    int size = atoi(argv[1]), limit = std::numeric_limits<int>::max();
    srand(time(NULL));
    int *array = new int[size];
    for (int i=0;i<size;i++)
		array[i] = rand () % limit;
    radixSortSlow(array, size);
	// for (int i=0;i<size;i++)
		// std::cout << array[i] << ' ';
	// std::cout << std::endl;
    bool sorted = true;
    for (int i=1;i<size;i++)
        if (array[i] < array[i-1]) {
            sorted = false;
            break;
        }
    if (sorted) std::cout << "Array successfully sorted!";
    else std::cout << "Error, unsuccessful at sorting array!";
	std::cout << std::endl;
    return 0;
}