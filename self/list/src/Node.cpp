#include "../include/Node.h"

std::string Node::TAG = "Node";

Node::Node(int val) {
	value = val;
}

void Node::print() {
    if (this != nullptr) {
        std::cout << "node value: " << this->value << std::endl;
    } else {
        std::cerr << "node null!" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& cout, Node *node) {
    if (node != nullptr) {
        while (node != nullptr) {
            if (node->next != nullptr) {
                cout << node->value << "-";
            } else {
                cout << node->value;
            }
            node = node->next;
        }
        cout << std::endl;
    } else {
        cout << "node null!" << std::endl;
    }
    return cout;
}