#include "stdio.h"
#include "stdlib.h"
#include "dac.h"

const long total = 15;
int main() {
	//struct Point* A = malloc(sizeof(struct Point) * total);

	struct Point P[] = {{2, 3}, {12, 30}}; //{40, 50}, {5, 1}, {12, 10}, {3, 4}};
	printf("The smallest distance is %f", find_closest_pair(P, total));
	return 0;
}
