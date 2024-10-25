#include "PriorityQueue.h"

Node::Node(const string& n, const string& r, int p) : name(n), role(r), priority(p), next(nullptr) {}

PriorityQueue::PriorityQueue() : head(nullptr) {}

PriorityQueue::~PriorityQueue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void PriorityQueue::insert(const string& name, const string& role, int priority) {
    Node* newNode = new Node(name, role, priority);

    if (head == nullptr || head->priority > priority) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node* PriorityQueue::getHead() const {
    return head;
}
