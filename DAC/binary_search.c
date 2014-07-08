/*
 * binary search algorithm implementation
 *
 */
#include "binary_search.h"

/*
 * recursive version
 */
static int binary_search_helper(int elem[], int i, int j, int key);

int 
binary_search(int elem[], int n, int key) {
	return binary_search_helper(elem, 0, n - 1, key);
}

int
binary_search_helper(int elem[], int i, int j, int key) {
	int mid;
	mid = (i + j) / 2;
	// didn't find
	if (j < i) {
		return -1;
	}

	else if (elem[mid] == key) {
		return mid;
	}
	else if (key < elem[mid]) {
		return binary_search_helper(elem, i, mid - 1, key);
	}
	else {
		return binary_search_helper(elem, mid + 1, j, key);
	}
}
