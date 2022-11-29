#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include <vector>
#include <string>
using namespace std;

struct number {
    double imagine;
    double real;
};

class complex_number {

public:
    number A;

    string name;
    complex_number();

    complex_number(double x);

    complex_number(complex_number &x);

    complex_number(const complex_number & object);

    void set(double x,double y);

    void multiply_number(double x);

    complex_number& multiply_complex(complex_number x, complex_number y);

    complex_number& sum_complex(complex_number x, complex_number y);

    double length();

    void show();
};

class Menu{
private:
    vector<complex_number> number;
public:
    void Start();
private:
    void Info();
    void CreateNewComplexNumber();
    void Sum();
    void Multiply();
    void Length();
};

#endif // !HEADER_H