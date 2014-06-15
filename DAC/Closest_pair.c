/*
 * closest pair points problem implementation
 * referred from: http://www.geeksforgeeks.org/closest-pair-of-points/
 */
#include "dac.h"
//=======================================

float 
dist(struct Point p1, struct Point p2) {
	float dx, dy;
	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

float
min(float v1, float v2) {
	return v1 > v2 ? v2:v1;
}

//=======================================
void
sort(struct Point A[], int i) {

}

float
base_case_find(struct Point A[], long left, long right) {
	int i, j;
	long size = right - left + 1;
	float min = dist(A[0], A[1]);
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if ( dist(A[i], A[j]) < min) {
				min = dist(A[i], A[j]);
			}
		}
	}
	return min;
}

float
cross_closest_pair(struct Point A[] , long size, float delta) {
	long i, j;
	// lets do cross area checking
	float min = delta;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size && abs(A[i].y - A[j].y) < min; j++) {
			if (dist(A[i], A[j]) < min) {
				min = dist(A[i], A[j]);	
			}
		}
	}
	return min;
}
float
closest_pair(struct Point A[], long left, long right) {
	long size = right - left + 1;
	if (size < 5) {
		return base_case_find(A, left, right);
	}
	long mid = (right + left) / 2;
	long delta_l = closest_pair(A, left, mid);
	long delta_r = closest_pair(A, mid + 1, right);
	long delta_min = min(delta_l, delta_r);

	// build a new array that contains only the points in strip area
	long i, j;
	struct Point* B = malloc(sizeof(struct Point) * size);
	for (i = left, j = 0; i <= right; i++) {
		if ( abs(A[mid].x - A[i].x) < delta_min) {
			B[j++] = A[i];
		}
	}
	//
	sort(B, j);
	float delta_c = cross_closest_pair(B, j, delta_min);
	free(B);
	return min(delta_min, delta_c);
}
float
find_closest_pair(struct Point A[], long size) {
	sort(A, size);
 	return closest_pair(A, 0, size - 1);
}
