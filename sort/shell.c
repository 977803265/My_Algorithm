/*
 * shell sort
 */
#include "sort.h"
void
shell(int A[], long num) {
	if (A == NULL) {
		return ;
	}
	if (num == 1) {
		return ;
	}

	long gap, i, j, k;
	int tmp;
	for (gap = num / 2; gap > 0; gap = gap / 2) { // select gap
		for (i = 0; i < gap; i++) { // select group
			// insertion sort
			for (j = i + gap; j < num; j += gap) { // traverse all members
				tmp = A[j]; // prepare an element
				for (k = j; k >= gap && A[k - gap] > tmp; k -= gap) { // find correct pos
					A[k] = A[k - gap];
				}
				A[k] = tmp;
			} 
		}
	}
}
