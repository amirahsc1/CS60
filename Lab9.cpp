#include <iostream>
#include "node.h"
using namespace std;
int main() {
    node* head = new node(5);
    head->set_link(new node(10));
    head->link()->set_link(new node(15));
    head->link()->link()->set_link(new node(20));
    head->link()->link()->link()->set_link(new node(25));
    int target = 15;
    size_t index = list_index(head, target);
    cout << "Looking for Target" <<endl;
    if (index != static_cast<size_t>(-1)) {
       cout << "Target: " << target << " has been found at index: " << index << endl;
    } else {
       cout << "Could not find Target: " << target << endl;
    }

    size_t n = 3;
    node* nthNode = list_at(head, n);
    if (nthNode != nullptr) {
       cout << "The node at index " << n << ": " << nthNode->data() << endl;
    } else {
       cout << "A node is not at this index." << endl;
    }

    node* current = head;
    while (current != nullptr) {
        node* next = current->link();
        delete current;
        current = next;
    }

    return 0;
}
