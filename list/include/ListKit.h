#ifndef LISTKIT_H
#define LISTKIT_H

#include "List.h"

class ListKit {
public:
    bool isLoop(List *list);
    Node* getLoopEntry(List *list);
    Node* getMid(List *list);
private:
    // warning! do not use this function! it'll destory original struct
    Node* seprateMid(List *list);
private:
    Node* slowFastCross(List *list);
    Node* getMidPre(List *list);
};

#endif