/*
 * bubble sort
 * 
 */
#include "sort.h"

void
bubble(int A[], long num) {
	if (A == NULL) {
		return ;
	}
	if (num == 1) {
		return ;
	}
	int i, j, k;
	int cur;
	int tmp;
	int pos;
	for (i = 0; i < num; i++) {
		for (j = num - 1; j > i; j--) {
			if (A[j - 1] > A[j]) {
				tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
			}
		}
	}
}
