#include "../include/box.h"

// dummy head
static LIST_HEAD(head);

void forw_trav(struct list_head *list) {
    while (list != NULL && list != &head) {
        struct box *tmp = (struct box *)container_of(list, struct box, list);
        print(tmp);
        list = list->next;
    }
}

void backw_trav(struct list_head *list) {
    while (list != NULL && list != &head) {
        struct box *tmp = (struct box *)container_of(list, struct box, list);
        print(tmp);
        list = list->prev;
    }
}

void init1() {
    struct box box1 = {
        .length = 10,
        .width = 10,
        // static init
        .list = LIST_HEAD_INIT(box1.list),
    };
    struct box box2 = {
        .length = 5,
        .width = 5,
    };
    struct box box3 = {
        .length = 15,
        .width = 15,
    };
    list_add(&(box2.list), &(box1.list));
    list_add(&(box3.list), &(box2.list));

    forw_trav(&(box1.list));
}

void init2() {
    struct box *box1 = (struct box *)malloc(sizeof(struct box));
    box1->length = 10;
    box1->width = 10;
    struct box *box2 = (struct box *)malloc(sizeof(struct box));
    box2->length = 5;
    box2->width = 5;
    struct box *box3 = (struct box *)malloc(sizeof(struct box));
    box3->length = 15;
    box3->width = 15;

    // INIT_LIST_HEAD(&(box1->list));

    // head insertion-stack
    list_add(&(box1->list), &head);
    list_add(&(box2->list), &head);
    list_add(&(box3->list), &head);

    forw_trav(head.next);

    // tail insertion-queue
    // list_add(&(box1->list), (head.prev));
    // list_add(&(box2->list), (head.prev));
    // list_add(&(box3->list), (head.prev));
    
    // forw_trav(head.next);
}

int main(int argc, char **argv) {
    init2();
    return 0;
}