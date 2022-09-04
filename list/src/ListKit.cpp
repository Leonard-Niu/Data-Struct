#include "../include/ListKit.h"

Node* ListKit::slowFastCross(List *list) {
    Node *head = list->head();
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

bool ListKit::isLoop(List *list) {
    Node *cross = this->slowFastCross(list);
    if (cross == nullptr) {
        return false;
    } else {
        return true;
    }
}

Node* ListKit::getLoopEntry(List *list) {
    if (!this->isLoop(list)) {
        return nullptr;
    } else {
        Node *cross = this->slowFastCross(list);
        Node *p = list->head();
        while (cross != p) {
            cross = cross->next;
            p = p->next;
        }
        return p;
    }
}

Node* ListKit::getMidPre(List *list) {
    if (this->isLoop(list)) {
        return nullptr;
    }

    Node *head = list->head();
    Node *slow = head;
    Node *fast = head;
    Node *pre = head;
    while (fast != nullptr && fast->next != nullptr) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return pre;
}

Node* ListKit::getMid(List *list) {
    Node *pre = this->getMidPre(list);
    return pre->next;
}

Node* ListKit::seprateMid(List *list) {
    Node *pre = this->getMidPre(list);
    Node *mid = pre->next;
    pre->next = nullptr;
    return mid;
}