#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstddef>
using namespace std;
class node {
public:
    node();
    node(const int& initdata, node* initlink = nullptr);
    int data() const;
    node* link();
    const node* link() const;
    void set_data(const int& newdata);
    void set_link(node* newlink);
private:
    int data_;
    node* link_;
};
    node* list_at(node* head_ptr, std::size_t n);
    size_t list_index(node* head_ptr, int target);


#endif // NODE_H
