
#include <iostream>
#include <cmath>
#include <string>
#include "Header.h"


using namespace std;

complex_number::complex_number() {
    A.imagine = 0;
    A.real = 0;
}

complex_number::complex_number(double x)
{
    A.real = x;
    A.imagine = 0;
}

complex_number::complex_number(complex_number &x)
{
    A.real = x.A.real;
    A.imagine = x.A.imagine;
}

void complex_number::set(double x,double y) {
    A.imagine = y;
    A.real = x;
}
void complex_number::multiply_number(double x) {
    A.imagine *= x;
    A.real *= x;
}
complex_number& complex_number::multiply_complex(complex_number x, complex_number y) {
    complex_number tmp;
    tmp.A.imagine = x.A.real*y.A.imagine + x.A.imagine*y.A.real;
    tmp.A.real = x.A.real*y.A.real - x.A.imagine*y.A.imagine;
    return tmp;
}
complex_number& complex_number::sum_complex(complex_number x, complex_number y) {
    complex_number tmp;
    tmp.A.imagine = x.A.imagine + y.A.imagine;
    tmp.A.real = x.A.real + y.A.real;
    return tmp;
}
double complex_number::length() {
    return sqrt(A.real*A.real + A.imagine*A.imagine);
}
void complex_number::show() {
    cout << A.real;
    if (A.imagine != 0) {
        if (A.imagine > 0) {
            cout << "+";
        }
        cout << A.imagine << 'i';
    }
    cout << endl;
}

void Menu::Start() {
    string tmp;
    this->Info();
    cin>>tmp;
    while(tmp!="exit"){
        bool flag=false;
        if(tmp=="create"){
            this->CreateNewComplexNumber();
            flag=true;
        }
        if(tmp=="sum"){
            this->Sum();
            flag=true;
        }
        if(tmp=="myl"){
            this->Multiply();
            flag=true;
        }
        if(tmp=="len"){
            this->Length();
            flag=true;
        }
        if(tmp=="info"){
            this->Info();
            flag=true;
        }
        if(flag) {
            cout << "All correct. Wait a command" << endl;
        }else{
            cout<<" I don't know this command "<<endl;
        }
        cin>>tmp;
    }
}

void Menu::Info() {
    cout<<"Function: "<<endl;
    cout<<"--Create new complex number: create"<<endl;
    cout<<"--Sum complex number: sum"<<endl;
    cout<<"--Myltiply complex number: myl"<<endl;
    cout<<"--Length complex number: len"<<endl;
    cout<<"--Repeat info; info"<<endl;
}

void Menu::CreateNewComplexNumber() {
    complex_number tmp;
    cout<<"Enter name"<<endl;
    cin>>tmp.name;
    cout<<"Enter real "<<endl;
    cin>>tmp.A.real;
    cout<<"Enter imagine "<<endl;
    cin>>tmp.A.imagine;
    number.push_back(tmp);
}

void Menu::Sum() {

}

void Menu::Multiply() {

}

void Menu::Length() {

}
