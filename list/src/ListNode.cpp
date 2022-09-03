#include "../include/ListNode.h"

std::ostream& operator<<(std::ostream& cout, ListNode *list) {
	Node *head = list->head();
	if (head == nullptr) {
		cout << "null list" << std::endl;
	} else {
		while (head != nullptr) {
			if (head->next != nullptr) {
				cout << head->value << "-";
			} else {
				cout << head->value;
			}
			head = head->next;
		}
		cout << std::endl;
	}
	return cout;
}

ListNode::ListNode() {
	mDummyHead = new Node(-1);
	mPreTail = mDummyHead;
	mTail = mDummyHead->next;
}

ListNode::~ListNode() {
	delete mDummyHead;
	// avoid random pointer
	mDummyHead = nullptr;
	mPreTail = nullptr;
	mTail = nullptr;
}

Node* ListNode::head() {
	return mDummyHead->next;
}

Node* ListNode::tail() {
	return mTail;
}

int ListNode::getCount() {
	return mCount;
}

void ListNode::init(int value) {
	Node *newNode = new Node(value);
	mDummyHead->next = newNode;
	mTail = newNode;
	mPreTail = mDummyHead;
	++mCount;
}

void ListNode::initList(int index) {
	Node *pre = mDummyHead;
	for (int i = 1; i <= index; ++i) {
		Node *newNode = new Node(i);
		++mCount;
		mTail = newNode;
		pre->next = newNode;
		mPreTail = pre;
		pre = pre->next;
	}
}

void ListNode::destory() {
	Node *pre = mDummyHead;
	while (pre->next != nullptr) {
		Node *p = pre->next;
		pre->next = p->next;
		delete p;
		p = nullptr;
		--mCount;
	}
	mTail = nullptr;
	mPreTail = mDummyHead;
}

void ListNode::print() {
	Node *head = this->head();
	if (head == nullptr) {
		std::cout << "null list" << std::endl;
	} else {
		while (head != nullptr) {
			if (head->next != nullptr) {
				std::cout << head->value << "-";
			} else {
				std::cout << head->value;
			}
			head = head->next;
		}
		std::cout << std::endl;
	}
}

Node* ListNode::reverseCore(Node *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	Node *newHead = reverseCore(head->next);
	Node *nxt = head->next;
	nxt->next = head;
	head->next = nullptr;
	mTail = head;
	mPreTail = nxt;
	return newHead;
}

void ListNode::reverse() {
	Node *head = this->head();
	this->mDummyHead->next = this->reverseCore(head);
}

void ListNode::add(int value) {
	if (this->head() == nullptr) {
		this->init(value);
	} else {
		Node *newNode = new Node(value);
		this->mTail->next = newNode;
		mPreTail = mTail;
		mTail = newNode;
		++mCount;
	}
}

void ListNode::add(int value, int index) {
	if (index < 0) {
		std::cerr << "input index err! " << index << std::endl;
		return;
	}

	if (index > this->mCount) {
		this->add(value);
	} else {
		Node *pre = mDummyHead;
		while (index > 0) {
			pre = pre->next;
			--index;
		}
		Node *newNode = new Node(value);
		Node *cur = pre->next;
		pre->next = newNode;
		newNode->next = cur;
		++mCount;
	}
}

void ListNode::remove() {
	if (this->head() == nullptr) {
		return;
	} else {
		Node *tmp = this->head();
		Node *pre = mDummyHead;
		while (tmp->next != nullptr) {
			pre = tmp;
			tmp = tmp->next;
		}
		delete tmp;
		tmp = nullptr;
		pre->next = nullptr;
		--mCount;
	}
}

void ListNode::remove(int index) {
	if (index < 0) {
		std::cerr << "input index err! " << index << std::endl;
		return;
	}

	if (index < mCount) {
		Node *pre = mDummyHead;
		Node *cur = mDummyHead->next;
		while (index > 0) {
			pre = cur;
			cur = cur->next;
			--index;
		}
		pre->next = cur->next;
		cur->next = nullptr;
		delete cur;
		cur = nullptr;
		--mCount;
	} else {
		if (mCount == 0) {
			return;
		} else {
			this->remove(mCount - 1);
		}
	}
}
