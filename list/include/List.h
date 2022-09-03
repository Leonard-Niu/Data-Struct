#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
public:
    List();
    ~List();

    // query head of the list
    Node* head();
    // query tail of the list
    Node* tail();
    void init(int value);
    // from head to tail
    void initList(int index);
    // from head to tail
    void destory();

    void print();
    // record node num of list
    int getCount();

    void add(int value);
    void add(int value, int index);
    // can only use traversal method
    void remove();
    void remove(int index);

    void reverse();

    static std::string TAG;

private:
    Node* reverseCore(Node *head);
    Node *mDummyHead = nullptr;
    Node *mTail = nullptr;
    Node *mPreTail = nullptr;
    int mCount = 0;
};

std::ostream& operator<<(std::ostream& cout, List *list);
Node* merge(Node *head1, Node *head2);


#endif
