#include <stdlib.h>
#include "test.h"

int malloc_to_fail = 0;
int num_allocs = 0;

void *xmalloc(size_t size)
{
	num_allocs++;
    if (malloc_to_fail == num_allocs)
		return (0);
    return malloc(size);
}
