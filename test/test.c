#include <stdlib.h>
#include "test.h"


void *xmalloc(size_t size)
{
	int fail_after = 7;
	static int num_allocs = 0;
	
    if (fail_after >= 0 && num_allocs >= fail_after)
		return (0);
	num_allocs++;
    return malloc(size);
}

/*
1- calloc
2- raed_buffer
3- strjoin
4- result

5- read_buffer
6- result

7- read_buffer
*/