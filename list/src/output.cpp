#include "../include/List.h"
#include "../include/Logger.h"

void basicTest() {
    List *list1 = new List();
    list1->remove();
    std::cout << list1;
    list1->add(9);
    list1->print();
    list1->add(1, 0);
    list1->print();
    list1->remove(1);
    list1->print();
    Logger::d(list1->TAG, "yes");

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