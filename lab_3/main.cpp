#include<iostream>
#include"Header.h"
#include<conio.h>
#include <locale.h>

using namespace std;

void func(complex_number ob) {
    cout << "ok";
}
int main() {
    setlocale(LC_ALL,"rus");
    cout << "Создаем три комплексных числа a,b,c " << endl;
    complex_number a;
    double x, y;
    cout << "Введите действительную и мнимую часть числа а соответственно " << endl;
    cin >> x >> y;
    a.set(x, y);
    cout << "Введите вещественное число для комплексного числа b" << endl;
    cin >> x;
    complex_number b(x);
    cout << "Пусть число с будет равно числу а" << endl;
    complex_number c(a);

    cout << "a= ";
    a.show();
    cout << "b= ";
    b.show();
    cout << "c= ";
    c.show();
    cout << "На какое вещественное число умножить а  " << endl;
    cin >> x;
    a.multiply_number(x);

    cout << "a= ";
    a.show();
    cout << "Пусть с будет результатом умножения а на b" << endl;
    c = a.multiply_complex(a, b);

    cout << "a= ";
    a.show();

    cout << "b= ";
    b.show();

    cout << "c= ";
    c.show();

    cout << "Пусть с будет результатом суммы а на b" << endl;
    c = b.sum_complex(a, b);

    cout << "a= ";
    a.show();

    cout << "b= ";
    b.show();

    cout << "c= ";
    c.show();

    cout << "Длинна числа а = " << a.length() << endl;
    func(a);
    _getch();
}