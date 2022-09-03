#include "../include/ListNode.h"

void basicTest() {
    ListNode *list1 = new ListNode();
    list1->remove();
    std::cout << list1;
    list1->add(9);
    list1->print();
    list1->add(1, 0);
    list1->print();
    list1->remove(1);
    list1->print();

    Node *p = new Node(1);
    std::cout << p;

    // list1->initList(5);
    // list1->print();
    // std::cout << list1->getCount() << "=" << list1->tail()->value << std::endl;
    // list1->reverse();
    // list1->print();
    // std::cout <<  list1->getCount() << "=" << list1->tail()->value << std::endl;
}

int main(int argc, char ** argv) {
    basicTest();
    return 0;
}