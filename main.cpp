#include "PriorityQueue.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    PriorityQueue pq;
    ifstream file("data.txt");
    string line;

    cout << "Entries before sorting:\n";
    while (getline(file, line)) {
        stringstream ss(line);
        string name, role;
        int priority;

        ss >> priority;
        getline(ss, role, ' '); 

        getline(ss, name);

        role.erase(0, role.find_first_not_of(" "));
        name.erase(0, name.find_first_not_of(" "));

        cout << name << " " << role << " " << priority << endl;

        pq.insert(name, role, priority);
    }
    file.close();

    cout << "\nPriority Queue (sorted by priority):\n";
    Node* current = pq.getHead();
    while (current != nullptr) {
        cout << "Name: " << current->name << ", Role: " << current->role << ", Priority: " << current->priority << endl;
        current = current->next;
    }

    return 0;
}
