/*
 * deterministic Selection
 *
 */
#include "dac.h"
#include "../sort/sort.h"
#include "../sort/utility.h"

long 
indexOf(int A[], long left, long right, int val) {
	int i;
	for (i = left; i <= right; i++) {
		if (A[i] == val) {
			break;
		}
	}
	return i;
}

int
find_median(int A[], long left, long right) {
	// break into 5 groups, sort each group, T = \Theta{(n)}
	long size = right - left + 1;
	if (size == 1) {
		return A[left];
	}
	long i, j;
	// sort each sub group
	for (i = left; i <= right; i += 5) {
		if (i + 4 <= right) {
			quick_sort(A, i, i + 4);
		}
		else {
			quick_sort(A, i, right);
		}
	}
	// extract each group median value
	int* C = malloc(sizeof(int) * (size / 5));
	for (j = 0, i = left; i <= right; i += 5, j++) {
		if (i + 4 <= right) {
			C[j] = A[i+2];
		}
		else {
			C[j] = A[left + (size % 5) / 2];
		}
	}
	// recursively computes the sub-array to find the median
  int p = find_median(C, 0, j - 1);
	free(C);
	return p;
}

int
DSelect(int A[], long left, long right, long ith) {
	int size = right - left + 1;
	if (size == 0) {
		return A[left];
	}
	
	if (ith < left || ith > right) {
		return A[left];
	}
	
	long i, j;
  int p = find_median(A, left, right);
	// find the index of median
	int r = indexOf(A, left, right, p);
	
	// the same process as RSelect
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
		return DSelect(A, i, right, ith);
	}
	else {
		return DSelect(A, left, i - 2, ith);
	}
}
