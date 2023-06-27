#ifndef DBIGUINT_H
#define DBIGUINT_H

#include <cstdlib>
#include <string>
using namespace std;

class dbiguint{
public:
    dbiguint();
    dbiguint(const string& s);
    int size() const;
    unsigned short operator[] (int pos) const;
    void operator+= (const dbiguint & b);
    void reserve(int newcapacity);

private:
    unsigned short *data_;
    int capacity_;

};
ostream& operator<< (ostream& out, const dbiguint& b);
#endif // DBIGUINT_H
