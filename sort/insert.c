/*
 * insert.c
 */
#include "sort.h"

void
insert(int A[], long num) {
	if (A == NULL) {
		return;
	}
	if (num == 1) {
		return;
	}
	int i, j, k;
	int tmp;
	for (i = 1; i < num; i++)	{
		tmp = A[i];
		for (j = i; j > 0 && A[j-1] > tmp; j--) {
			A[j] = A[j - 1];
		}
		A[j] = tmp;
	}
}

