#include "../include/queue.h"

int main(int argc, char **argv) {
    queue q(10);
    int index = 1;
    while (index < 50) {
        q.push(index);
        ++index;
    }
    q.traverse();
    
    q.pop();
    q.pop();
    while (index < 100) {
        q.push(index);
        ++index;
    }
    q.traverse();

    q.traverse_mem();


    return 0;
}