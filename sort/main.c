#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "utility.h"

const long total = 1000000;
int 
main() {
	int i;
	long long old_time, new_time;

	int* A = malloc(sizeof(int) * total);

	for (i = 0; i < total; i++) {
		A[i] = rand() % 65535;
	}
		
	old_time = get_time();	
	merge(A, total);
	new_time = get_time();	

	printf("time cost:%llu \n", new_time - old_time);

//	for (i = 0; i < total; i++) {
//		printf("%d\n", A[i]);
//	}
	
	if (A != NULL) {
		free(A);
	}
}
