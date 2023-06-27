#ifndef LBIGUINT_H
#define LBIGUINT_H

#include <cstdlib>
#include <string>
using namespace std;

class node {
public:
    node(unsigned short d = 0, node* l = nullptr) : data_(d), link_(l) {}
    unsigned short data() const { return data_; }
    node* link() const { return link_; }
    void set_data(unsigned short d) { data_ = d; }
    void set_link(node* l) { link_ = l; }
private:
    unsigned short data_;
    node* link_;
};

class lbiguint {
public:
    lbiguint();
    lbiguint(const string& s);
    ~lbiguint();
    int size() const;
    unsigned short operator[](int pos) const;
    friend ostream& operator<<(ostream& out, const lbiguint& b);
    void reserve(int newcapacity);
    void push_back(unsigned short value);
    void clear();

private:
    node* head_;
    node* tail_;
    int capacity_;
};





#endif // LBIGUINT_H
