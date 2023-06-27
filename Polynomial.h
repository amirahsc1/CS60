#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

struct Node {
    int coefficient;
    int power;
    Node* next;
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial(int constant);
    Polynomial(int coefficient, int power);
    ~Polynomial();
    void insertTerm(int coefficient, int power);
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    int evaluate(int x) const;
    void inputPolynomial();
    void print() const;

   
};

#endif  // POLYNOMIAL_H
