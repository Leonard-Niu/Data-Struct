#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int QUEUE_DEFAULT_VALUE = 0;

class queue {
public:
    queue(int size) {
        mem = (int *)malloc(size * sizeof(int));
        memset(mem, QUEUE_DEFAULT_VALUE, sizeof(int) * size);
        this->size = size;
        front_idx = 0;
        rear_idx = 0;
    }

    bool empty() {
        if (front_idx == rear_idx) {
            return true;
        } else {
            return false;
        }
    }

    bool full() {
        if (front_idx == ((rear_idx + 1) % size)) {
            return true;
        } else {
            return false;
        }
    }

    bool push(int value) {
        std::cout << "value:" << value << std::endl;
        if (this->full()) {
            return false;
        }
        mem[rear_idx % size] = value;
        ++rear_idx;
        return true;
    }

    bool pop() {
        if (this->empty()) {
            return false;
        }
        mem[front_idx % size] = QUEUE_DEFAULT_VALUE;
        ++front_idx;
        return true;
    }

    int front() {
        return mem[front_idx % size];
    }

    int rear() {
        size_t tmp = rear_idx - 1;
        return mem[tmp % size];
    }

    void traverse() {
        size_t start = front_idx;
        size_t stop = rear_idx;
        std::cout << "---------------------------------" << std::endl;
        while (start != stop) {
            std::cout << "queue data:" << mem[start % size] << std::endl;
            ++start;
        }
    }

    void traverse_mem() {
        size_t start = 0;
        size_t stop = size;
        std::cout << "---------------------------------" << std::endl;
        while (start != stop) {
            std::cout << "queue data:" << mem[start] << std::endl;
            ++start;
        }
    }
    

private:
    size_t front_idx = 0;
    size_t rear_idx = 0;
    size_t size = 0;
    int *mem = nullptr;
};


#endif