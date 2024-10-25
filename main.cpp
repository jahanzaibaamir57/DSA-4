#include "PriorityQueue.h"
#include <fstream>
#include <iostream>

int main() {
    PriorityQueue pq;

    ifstream file("data.txt");
    string name, role;
    int priority;

    while (file >> name >> role >> priority) {
        pq.insert(name, role, priority);
    }
    file.close();

    cout << "Priority Queue (sorted by priority):\n";
    Node* current = pq.getHead();
    while (current != nullptr) {
        cout << "Name: " << current->name << ", Role: " << current->role << ", Priority: " << current->priority << endl;
        current = current->next;
    }

    return 0;
}
