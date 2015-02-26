#include <stdlib.h>
/*
 * element  {x| 0 <= x <= N-1}
 * bucket id = element / bucket_amount 
 * 
 */

#define BUCKET_AMOUNT      5

void bucket_sort(int A[], int N) {
    
    // allocate bucket, two dimensional array
    int bucket_size = N / BUCKET_AMOUNT;
    int* bucket[BUCKET_AMOUNT];
    int ptr[BUCKET_AMOUNT];
    int num;
    
    int i;
    for (i = 0; i < BUCKET_AMOUNT; i++) {
        bucket[i] = (int*) malloc(sizeof(int) * bucket_size);
        ptr[i] = 0;
    }

    // put into bucket according to each element value
    for (i = 0; i < N; i++) {
        num = A[i] / bucket_size;
        bucket[num][ptr[num]++] = A[i];
    }
    
    // merge elements in each bucket
    for (i = 0; i < bucket_size; i++) {
        merge_sort(bucket[i], bucket_size);
    }

    // put back
    for (i = 0; i < N; i++) {
       A[i] = bucket[i/bucket_size][i%bucket_size]; 
    }
}



