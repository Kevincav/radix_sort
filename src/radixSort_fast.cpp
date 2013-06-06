#include "radixSort_fast.hpp"

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
* Creates a histogram using shared memory and fork processes for   *
* parallelism.  This creates a parallel conquer and divide         *
* algorithm, which merges into one histogram to use later on in    *
* the code.  Note: This will not work in windows, with unistd.h.   *
*******************************************************************/
inline int *histogram(int *array, int size, int pass) {
	const int arrSize = 2048 * 8 * sizeof(int);
	int shmMal = shmget(12345, arrSize, IPC_CREAT | 0666);
		if (shmMal < 0) return NULL;
	int *hist = (int *) shmat(shmMal, NULL, 0);
		if (hist == (int *) -1) return NULL;
	int status, i, j, pos, start, stop;
	pid_t pid[8];
	for (i=0;i<8;i++) {
		pid[i] = fork();
		if (pid[i] < 0) _exit(0);
		if (pid[i] == 0) {
			start = (i * size) / 8;
			stop = i == 7 ? size : (i + 1) * size / 8;
			for (j=start;j<stop;++j) {
				pos = position(array[j], pass);
				hist[i * 2048 + pos]++;
			}
			_exit(0);
		}
	}
	for (i=0;i<8;i++)
		wait(&status);
	int *newHist = (int *) calloc(2048, sizeof(int));
	for (i=0;i<8;i++)
		for (j=0;j<2048;j++)
			newHist[j] += hist[i * 2048 + j];

	shmdt((void *) hist);
	shmctl(shmMal, IPC_RMID, 0);
	return newHist;
}
/*******************************************************************
* Counting sorts each of the 3 11-bit bytes of each integers.      *
* This eliminates the need for buckets, for each pass.             *
* Bytes used to eliminate the number of passes down from k (length *
*   of the largest integer) down to 3 passes.                      *
*******************************************************************/
void radixSortFast(int *array, int size) {
	int i, j, pos;
	int *freqArray;
	int *temp = (int *) malloc(size * sizeof(int));
	for (j=0;j<3;j++) {
		freqArray = histogram(array, size, j);
		for (i=1;i<2048;i++)
			freqArray[i] += freqArray[i-1];
		for (i=size-1;i>=0;i--) {
			pos = --freqArray[position(array[i], j)];
			temp[pos] = array[i];
		}
		memcpy(array, temp, size * sizeof(int));
		free(freqArray);
	}
	free(temp);
}
