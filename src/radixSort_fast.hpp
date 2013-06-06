#ifndef _RADIXSORT_FAST_HPP
#define _RADIXSORT_FAST_HPP

// Needed libraries
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string.h>

// Function Prototypes
void radixSortFast(int *array, int size);

#endif