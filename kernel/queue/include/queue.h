#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// unlocked circular queue
struct __kfifo{
    unsigned int in; // in index
    unsigned int out; // out index
    unsigned int mask; // count mask
    unsigned int esize; // element size
    void *data; // data ptr
};

// find closest max value
unsigned int roundup_power_of_2(unsigned int in);
// fifo init
int kfifo_init(struct __kfifo *fifo, unsigned int ecount, unsigned int esize);
void kfifo_in(struct __kfifo *fifo, const void *src, unsigned int len);
void kfifo_out(struct __kfifo *fifo, void *dst, unsigned int len);
void kfifo_copy_in(struct __kfifo *fifo, const void *src, unsigned int len, unsigned int off);
unsigned int kfifo_unused(struct __kfifo *fifo);
void kfifo_traverse(struct __kfifo *fifo);

#endif