#include "radixSort_slow.hpp"

/*******************************************************************
* Flips all the bits if negative.                                  *
* Flips only the sign bit if positive.                             *
* Allows for both negative and positive values.                    *
* Returns one of the three bytes of the integer.                   *
*******************************************************************/
inline int position(int number, int pass) {
	int mask;
	if (number <= 0) mask = 0x80000000;
	else mask = (number >> 31) | 0x80000000;
	return ((number ^ mask) >> (pass * 11)) & 0x7FF;
}
/*******************************************************************
* Counting sorts each of the 3 11-bit bytes of each integers.      *
* This eliminates the need for buckets, for each pass.             *
* Bytes used to eliminate the number of passes down from k (length *
*   of the largest integer) down to 3 passes.                      *
*******************************************************************/
void radixSortSlow(int *array, int size) {
	unsigned int *freqArray;
	int *temp = (int *) malloc(size * sizeof(int));
	for (int j=0;j<3;j++) {
		freqArray = (unsigned int *) calloc(2048, sizeof(unsigned int));
		for (int i=0;i<size;i++)
			freqArray[position(array[i], j)]++;
		for (int i=1;i<2048;i++)
			freqArray[i] += freqArray[i-1];
		for (int i=size-1;i>=0;i--) {
			const int pos = --freqArray[position(array[i], j)];
			temp[pos] = array[i];
		}
		memcpy(array, temp, size * sizeof(int));
		free(freqArray);
	}
	free(temp);
}