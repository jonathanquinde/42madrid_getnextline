#include "test.h"

static int fail_after = 0;
static int num_allocs = 0;

static void *xmalloc(size_t size)
{
    if (fail_after > 0 && num_allocs++ >= fail_after)
        return 0;
    return malloc(size);
}