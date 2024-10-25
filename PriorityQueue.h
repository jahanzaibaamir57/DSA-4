#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>
using namespace std;

struct Node {
    string name;
    string role;
    int priority;
    Node* next;

    Node(const string& n, const string& r, int p);
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue();
    ~PriorityQueue();
    void insert(const string& name, const string& role, int priority);
    Node* getHead() const;  // Provides access to the head for traversal in main
};

#endif
