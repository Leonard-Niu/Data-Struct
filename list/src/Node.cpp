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
        cout << "node value:" << node->value << std::endl;
    } else {
        cout << "node null!" << std::endl;
    }
    return cout;
}