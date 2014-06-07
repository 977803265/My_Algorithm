#include "stdio.h"
#include "stdlib.h"
#include "dac.h"

const long total = 15;
int main() {
	int i;
	long long old_time, new_time;

	int* A = malloc(sizeof(int) * total);

	for (i = 0; i < total; i++) {
		A[i] = rand() % 65535;
	}

//	printf("RSelect result:%d\n\n",RSelect(A, 0, total-1, 9));
	printf("DSelect result:%d\n\n",DSelect(A, 0, total-1, 13));
	quick(A, total);

	for (i = 0; i < total; i++) {
		printf("%d\n", A[i]);
	}

	if (A != NULL) {
		free(A);
	}
}
