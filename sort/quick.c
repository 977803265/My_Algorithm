/*
 * quick sort
 */
#include <stdlib.h>
#include "sort.h"
#include "utility.h"

void quick_sort(int A[], long left, long right);

void
quick(int A[], long num) {
	if (num == 1) {
		return;
	}
	if (A == NULL) {
		return;
	}

	quick_sort(A, 0, num - 1);
}

//void 
//quick_sort(int A[], long left, long right) {
//	if (right - left < 2) {
//		if (A[left] > A[right]) {
//			swap(&A[left], &A[right]);
//		}
//		return;
//	}
//
//	long pivot = rand() % (right - left) + left;
//	// always move randomly chosen pivot to the very left side of array
//	swap(&A[left], &A[pivot]);
//	int i, j;
//	for (i = left + 1, j = left + 1; j <= right; j++) {
//		if ( A[left] > A[j]) {
//			swap(&A[i],&A[j]);
//			i++;
//		}
//	}
//	swap(&A[left],&A[i - 1]);
//	// recursive do quick sort on left part
//	if (left < i - 2) {
//		quick_sort(A, left, i - 2);
//	}
//	// recursive do quick sort on right part
//	if (i < right) {
//		quick_sort(A, i, right);
//	}
//}


/*
 * random select pivot
 */
void 
quick_sort(int A[], long left, long right) {
	if (left >= right) {
		return;
	}

	long pivot;
	long size;
	size = right - left + 1;
	pivot	= rand() % size + left;
	// always move randomly chosen pivot to the very left side of array
	swap(&A[left], &A[pivot]);
	int i, j;
	for (i = left + 1, j = left + 1; j <= right; j++) {
		if ( A[left] > A[j]) {
			swap(&A[i],&A[j]);
			i++;
		}
	}
	swap(&A[left],&A[i - 1]);
	// recursive do quick sort on left part
	quick_sort(A, left, i - 2);
	// recursive do quick sort on right part
	quick_sort(A, i, right);

}
