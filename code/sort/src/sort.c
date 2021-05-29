
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

// The Only Indent Style Accepted is the ALLMANN
// K&R is for the JS-Weaks

int foo(int a,int b)
{
	return a-b-1;
}

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

void cj_sort (int *v, int size)
{
	qsort(v, size, sizeof(int), cmpfunc);
}