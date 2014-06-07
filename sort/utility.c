#include <sys/time.h>
#include "utility.h"

long long get_time(){
	struct timeval te;
	gettimeofday(&te, NULL);
	long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return milliseconds;
}

void
swap(int *a, int *b) {
  int tmp;
  tmp = *b;
  *b = *a;
  *a = tmp;
}
