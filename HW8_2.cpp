// Problem 2 on page 826 - 5 points
// Write a function called mergeLists that takes two call-by-reference arguments
// that are pointer variables that point to the heads of linked lists of values of type
// int. The two linked lists are assumed to be sorted so that the number at the head
// is the smallest number, the number in the next node is the next smallest, and so
// forth. The function returns a pointer to the head of a new linked list that contains
// all the nodes in the original two lists. The nodes in this longer list are also sorted
// from smallest to largest values. Note that your function will neither create nor destroy any nodes. When the function call ends, the two pointer variable arguments
// should have the value nullptr
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node** head1, Node** head2) {
    Node old;
    Node* tail = &old;
    
    while (*head1 != nullptr && *head2 != nullptr) {
        if ((*head1)->data <= (*head2)->data) {
            tail->next = *head1;
            *head1 = (*head1)->next;
        } else {
            tail->next = *head2;
            *head2 = (*head2)->next;
        }
        tail = tail->next;
    }
    
    if (*head1 != nullptr)
        tail->next = *head1;
    else
        tail->next = *head2;
    
    *head1 = nullptr;
    *head2 = nullptr;
    
    return old.next;
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
    Node* head1 = new Node{1, nullptr};
    head1->next = new Node{2, nullptr};
    head1->next->next = new Node{3, nullptr};
    Node* head2 = new Node{4, nullptr};
    head2->next = new Node{5, nullptr};
    head2->next->next = new Node{6, nullptr};

    cout << "List 1: ";
    print(head1);

    cout << "List 2: ";
    print(head2);

    Node* mergeBegin = mergeLists(&head1, &head2);

    cout << "Merged List: ";
    print(mergeBegin);

    // Delete Mem
    Node* current = mergeBegin;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
