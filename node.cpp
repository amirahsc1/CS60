#include "node.h"
node::node(){
data_ = 0;
link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
data_ = initdata;
link_ = initlink;
}
int node::data() const
{
return data_;
}
node * node::link()
{
return link_;
}
//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function
//doesn't change anything - On a const node*, you can only call const functions
{
return link_;
}
void node::set_data(const int & newdata)
{
data_ = newdata;
}
void node::set_link(node * newlink)
{
link_ = newlink;
}
std::size_t list_index(node* head_ptr, int target) {
    std::size_t index = 0;
    node* current = head_ptr;

    while (current != nullptr) {
        if (current->data() == target) {
            return index;
        }
        current = current->link();
        index++;
    }

    // Target not found
    return static_cast<std::size_t>(-1);
}
node* list_at(node* head_ptr, std::size_t n) {
    node* current = head_ptr;
    std::size_t count = 0;

    while (current != nullptr && count < n) {
        current = current->link();
        count++;
    }

    return current;
}



















