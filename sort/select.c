/*
 * select sort
 *
 */
#include "sort.h"
void
select(int A[], long num) {
//	if (A == NULL) {
//		return;
//	}
//	if (num == 1) {
//		return;
//	}

	int i, j, tmp, pos;
	for (i = 0; i < num - 1; i++) {
		pos = i;
		// find the nth largest number
		for (j = i + 1; j < num; j++) {
			if (A[pos] > A[j]) {
				pos = j;
			}
		}

		if(pos != i) {
			tmp = A[pos];
			A[pos] = A[i];
			A[i] = tmp;
		}
	}

}
/*
void select(int *a, int len)
{
	register int i, j, min, t;
	for(i = 0; i < len - 1; i ++)
	{
		min = i;
		//查找最小值
		for(j = i + 1; j < len; j ++) {
			if(a[min] > a[j])
				min = j;
		}
		//交换
		if(min != i)
		{
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
}
*/
