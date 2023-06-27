#include <iostream>
#include <cmath>
using namespace std;
#include "Polynomial.h"

    // Default constructor
    Polynomial::Polynomial() : head(nullptr) {}

    // Copy constructor
    Polynomial::Polynomial(const Polynomial& other) {
        head = nullptr;
        Node* current = other.head;
        while (current != nullptr) {
            insertTerm(current->coefficient, current->power);
            current = current->next;
        }
    }

    // of type int that produces the polynomial that has only one
    // constant term that is equal to the constructor argument
    Polynomial::Polynomial(int constant) : head(nullptr) {
        insertTerm(constant, 0);
    }

    //  a constructor with two arguments of type int that produces
    // the one-term polynomial whose coefficient and exponent are 
    // given by the two arguments
    Polynomial::Polynomial(int coefficient, int power) : head(nullptr) {
        insertTerm(coefficient, power);
    }

    // Destructor
    Polynomial::~Polynomial() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert a term into the polynomial
    void Polynomial::insertTerm(int coefficient, int power) {
        Node* newNode = new Node{ coefficient, power, nullptr };

        if (head == nullptr || power > head->power) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->power >= power) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Overload + operator for addition of polynomials
    Polynomial Polynomial::operator+(const Polynomial& other) const {
        Polynomial result(*this);
        Node* current = other.head;
        while (current != nullptr) {
            result.insertTerm(current->coefficient, current->power);
            current = current->next;
        }
        return result;
    }

    // Overload - operator for subtraction of polynomials
    Polynomial Polynomial::operator-(const Polynomial& other) const {
        Polynomial result(*this);
        Node* current = other.head;
        while (current != nullptr) {
            result.insertTerm(-current->coefficient, current->power);
            current = current->next;
        }
        return result;
    }

    // Overload * operator for multiplication of polynomials
    Polynomial Polynomial::operator*(const Polynomial& other) const {
        Polynomial result;
        Node* current1 = head;
        while (current1 != nullptr) {
            Node* current2 = other.head;
            while (current2 != nullptr) {
                int coefficient = current1->coefficient * current2->coefficient;
                int power = current1->power + current2->power;
                result.insertTerm(coefficient, power);
                current2 = current2->next;
            }
            current1 = current1->next;
        }
        return result;
    }

    // Evaluate the polynomial for a given value of x
    int Polynomial::evaluate(int x) const {
        int result = 0;
        Node* current = head;
        while (current != nullptr) {
            result += current->coefficient * pow(x, current->power);
            current = current->next;
        }
        return result;
    }

    // Input polynomial from the user
    void Polynomial::inputPolynomial() {
        int coefficient, power;
        char term;
        cout<< "Enter the polynomial terms like this: coefficient^exponent (examples: 4^2 -6^1 9^0)" << endl;
        while (cin >> coefficient >> term >> power) {
            insertTerm(coefficient, power);
            if (cin.peek() == '\n') break;
        }
    }

    void Polynomial::print() const {
           Node* current = head;
        while (current != nullptr) {
            cout<< current->coefficient << "x^" << current->power;
            current = current->next;
            if (current != nullptr) {
                cout<< " + ";
            }
        }
        cout<< endl;
        }