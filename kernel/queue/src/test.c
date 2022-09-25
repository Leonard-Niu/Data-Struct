#include "../include/queue.h"

#include <stdio.h>

void test1() {
    unsigned int in = 100;
    printf("original:%d, modified:%d\n", in, roundup_power_of_2(in));
}

void test2() {
    struct __kfifo *fifo = (struct __kfifo*)malloc(sizeof(struct __kfifo));
    unsigned int ecount = 20;
    kfifo_init(fifo, ecount, sizeof(int));
    printf("data size:%ld\n", sizeof(fifo->data));
    kfifo_traverse(fifo);
}

int main(int argc, char **argv) {
    test2();
    return 0;
}