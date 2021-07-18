#ifndef HEADER_MEMPOOL
#define HEADER_MEMPOOL

typedef struct __mpool mpool;

void **mpool_new_pool(unsigned int sz, unsigned int total_sz);
mpool *mpool_init(int min2, int max2);
void mpool_free(mpool *mp);
void *mpool_alloc(mpool *mp, int sz);
void mpool_repool(mpool *mp, void *p, int sz);

#endif