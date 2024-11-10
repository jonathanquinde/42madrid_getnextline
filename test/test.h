#define malloc(x) xmalloc(x)

static void *xmalloc(size_t size);