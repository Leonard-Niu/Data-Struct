#ifndef BOX_H
#define BOX_H

#include "./list.h"

struct box {
    unsigned int width;
    unsigned int length;
    struct list_head list;
};

void forw_trav(struct list_head *list);
void backw_trav(struct list_head *list);

static inline void print(struct box *entity) {
    printf("box length: %d, width: %d \n", entity->length, entity->width);
}


#endif