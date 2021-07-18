#include <stdlib.h>
#include "mempool.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

#define PMAX 11

int main(void)
{
    /* Initialize a new mpool for values 2^4 to 2^PMAX */
    mpool *mp = mpool_init(4, PMAX);

    srandom(getpid() ^ (intptr_t) &main); /* Assume ASLR */

    for (int i = 0; i < 5000000; i++) {
        int sz = random() % 64;
        /* also alloc some larger chunks  */
        if (random() % 100 == 0)
            sz = random() % 10000;
        if (!sz)
            sz = 1; /* avoid zero allocations */
        int *ip = (int *) mpool_alloc(mp, sz);
        *ip = 7;

        /* randomly repool some of them */
        if (random() % 10 == 0) /* repool, known size */
        mpool_repool(mp, ip);
        if (i % 10000 == 0 && i > 0) {
            putchar('.');
            if (i % 700000 == 0)
                putchar('\n');
        }
    }

    mpool_free(mp);
    putchar('\n');
    return 0;
}