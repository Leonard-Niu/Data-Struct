#include "../include/List.h"
#include "../include/ListKit.h"
#include "../include/Logger.h"

void basicTest() {
    List *list = new List();
    list->initList(6);

    ListKit *kit = new ListKit;
    // std::cout << kit->seprateMid(list);
    std::cout << list->head();
}

int main(int argc, char ** argv) {
    basicTest();
    return 0;
}