#include "../include/queue.h"

unsigned int roundup_power_of_2(unsigned int in) {
    if (in == 0 || in == 1) {
        return in;
    }

    unsigned int max_bit = 0;
    for (unsigned int i = in; i != 0; i >>= 1) {
        ++max_bit;
    }
    // printf("%d\n", max_bit);
    return (unsigned int)(1 << max_bit);
}

/*
ecount: element count num
esize: element size
total size: ecount * esize
we need to refine ecount to round up power of 2
*/
int kfifo_init(struct __kfifo *fifo, unsigned int ecount, unsigned int esize) {
    ecount = roundup_power_of_2(ecount);

    fifo->in = 0;
    fifo->out = 0;
    fifo->esize = esize;
    if (ecount < 2) {
        fifo->data = NULL;
        fifo->mask = 0;
        return -1;
    }

    // allocate mem total size
    fifo->data = malloc(esize * ecount);
    memset(fifo->data, 0, ecount * esize);
    printf("data total size:%d\n", esize * ecount);

    if (!fifo->data) {
        fifo->mask = 0;
        return -1;
    }
    
    fifo->mask = ecount - 1;
    return 0;

}

void kfifo_traverse(struct __kfifo *fifo) {
    if (fifo != NULL) {
        unsigned int start = fifo->in;
        unsigned int end = fifo->out;
        while (start != end) {
            printf("fifo data:%d\n", ((int*)(fifo->data))[start]);
            ++start;
        }
    }
}

void kfifo_copy_in(struct __kfifo *fifo, const void *src, unsigned int len, unsigned int off) {
    unsigned int ecount = fifo->mask + 1;
    unsigned int esize = fifo->esize;
    unsigned int size = ecount * esize;

    off &= fifo->mask;

    if (esize != 1) {
        off *= esize;
        len *= esize;
    }

    // if necessary, seprate data into two parts: tail and head(left space is not enough)
    unsigned int left = min(len, size - off);
    memcpy(fifo->data + off, src, left);
    memcpy(fifo->data, src + left, len - left);
}

unsigned int kfifo_unused(struct __kfifo *fifo) {
    // in always better than out, they grow bigger together
    return (fifo->mask + 1) - (fifo->in - fifo->out);
}