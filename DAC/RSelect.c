/*
 * random selection problem
 * input: a integer array of length n, specify the index you
 * want to get.
 * output: the value of that entry
 */
#include "dac.h"
#include "../sort/utility.h"
int
RSelect(int A[], long left, long right, long ith) {
	long size = right - left + 1;
	if (size == 0) {
		return A[left];
	}
	
	if (ith < left || ith > right) {
		return A[left];
	}

	long i, j;	
	long r = rand() % size + left; // I make a misktake here
	
	// always move pivot number to the very left
	swap(&A[left],&A[r]);
	for (i = left + 1, j = left + 1; j <= right; j++)	{
		if (A[left] > A[j]) {
			swap(&A[j],&A[i]);
			i++;
		}
	}
	// now (i - 1) is the true pivot index 
	swap(&A[left], &A[i - 1]);
	if ((i - 1) == ith) {
		return A[i-1];
	}
	else if ((i - 1) < ith) {
		return RSelect(A, i, right, ith);
	}
	else {
		return RSelect(A, left, i - 2, ith);
	}
}
