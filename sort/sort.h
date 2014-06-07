/*
 * all kinds of sort algorithms common header file
 *
 */

#include <stdio.h>
#include <stdbool.h>

void insert(int A[], long num);
void select(int A[], long num);
void bubble(int A[], long num);
void merge(int A[], long num);
void shell(int A[], long num);
void quick(int A[], long num);

void quick_sort(int A[], long left, long rigth);
