#include "lbiguint.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
lbiguint::lbiguint() {
    head_ = nullptr;
    tail_ = nullptr;
    capacity_ = 0;
}

lbiguint::lbiguint(const string& s) {
    head_ = nullptr;
    tail_ = nullptr;
    capacity_ = s.size();

    for (int i = capacity_ - 1; i >= 0; i--) {
        unsigned short digit = s[i] - '0';
        push_back(digit);
    }
}

lbiguint::~lbiguint() {
    clear();
}

int lbiguint::size() const {
    return capacity_;
}

unsigned short lbiguint::operator[](int pos) const {
    node* current = head_;
    for (int i = 0; i < pos; i++) {
        current = current->link();
    }
    return current->data();
}

ostream& operator<<(ostream& out, const lbiguint& b) {
    node* current = b.head_;
    while (current != nullptr) {
        out << current->data();
        current = current->link();
    }
    return out;
}

void lbiguint::reserve(int newcapacity) {
    if (newcapacity > capacity_) {
        while (capacity_ < newcapacity) {
            push_back(0);
        }
    }
}


void lbiguint::push_back(unsigned short value) {
    node* new_node = new node(value);
    if (head_ == nullptr) {
        head_ = new_node;
        tail_ = new_node;
    }
    else {
        tail_->set_link(new_node);
        tail_ = new_node;
    }
    capacity_++;
}

void lbiguint::clear() {
    node* current = head_;
    while (current != nullptr) {
        node* temp = current;
        current = current->link();
        delete temp;
    }
    head_ = nullptr;
    tail_ = nullptr;
    capacity_ = 0;
}
