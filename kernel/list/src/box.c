#include "../include/box.h"

void forw_trav(struct box *entity) {
    struct list_head *list = &(entity->list);
    while (list != NULL) {
        struct box *tmp = (struct box *)container_of(list, struct box, list);
        print(tmp);
        list = list->next;
    }
}

void backw_trav(struct box *entity) {
    struct list_head *list = &(entity->list);
    while (list != NULL) {
        struct box *tmp = (struct box *)container_of(list, struct box, list);
        print(tmp);
        list = list->prev;
    }
}

int main(int argc, char **argv) {
    struct box box1 = {
        .length = 10,
        .width = 10,
        // .list = {
        //     .next = NULL,
        //     .prev = NULL,
        // },
    };
    forw_trav(&box1);
    return 0;
}