// Problem 1 on page 826 - 5 points
// Write a void function that takes a linked list of integers and reverses the order of its
// nodes. The function will have one call-by-reference parameter that is a pointer to
// the head of the list. After the function is called, this pointer will point to the head
// of a linked list that has the same nodes as the original list but in the reverse of the
// order they had in the original list. Note that your function will neither create nor
// destroy any nodes. It will simply rearrange nodes. Place your function in a suitable
// test program.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void reverse(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void print(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    cout << "Original List: ";
    print(head);
    reverse(&head);
    cout << "List in Reverse: ";
    print(head);
    // Delete Mem
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
