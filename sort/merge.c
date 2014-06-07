/*
 * merge sort
 *
 */

#include <stdlib.h>
#include "sort.h"

void sub_merge(int A[], long left, long right);

void
merge(int A[], long num) {
	if (A == NULL) {
		return;
	}
	if (num == 1) {
		return;
	}
	
	sub_merge(A, 0, num - 1);
}

void 
sub_merge(int A[], long left, long right) {
	if (right - left == 1) {
		int tmp;
		// less than 3,  brute-force
		if (A[left] > A[right]) {
			tmp = A[right];
			A[right] = A[left];
			A[left] = tmp;
		}	
		return;
	}
	else if (right == left) {
		return;
	}

	// divide 
	int mid = (right + left) / 2;
	// conquer each subproblem recursively
	sub_merge(A, left, mid);
	sub_merge(A, mid + 1, right);
	// combine
	long i;
	int tmp;
	long lp = left;
	long rp = mid + 1;
	long size = right - left + 1;
	int* B = malloc(sizeof(int) * size);

	for (i = 0; i < size && lp <= mid && rp <=right; i++) {
		if (A[lp] < A[rp]) {
			B[i] = A[lp++];
		}
		else {
			B[i] = A[rp++];
		}
	}

	if (lp <= mid) {
		for (; lp <= mid; i++) {
			B[i] = A[lp++];
		}
	}
	else {
		for (; rp <= right; i++) {
			B[i] = A[rp++];
		}
	}

	// copy sorted elements to the original array A
	for (i = 0; i < size; i++) {
		A[left + i] = B[i];
	}
}

