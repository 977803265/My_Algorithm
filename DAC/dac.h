#ifndef _DAC_H
#define _DAC_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../sort/sort.h"

struct Point {
	int x;
	int y;
};
int DSelect(int A[], long left, long right, long ith);
int RSelect(int A[], long left, long right, long ith);
float find_closest_pair(struct Point A[], long size);

#endif
