#include <iostream>
#include "Logger.h"

struct Node {
    Node(int val);
    void print();

    // int value = this == nullptr ? INT64_MIN : value;
    int value;
    Node *next = nullptr;
};

// global defination, not in class
std::ostream& operator<<(std::ostream& cout, Node *node);