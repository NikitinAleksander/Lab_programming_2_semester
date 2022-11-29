#include<iostream>
#include"Header.h"
#include<conio.h>

using namespace std;


int main() {
	square a;

	/*float x, y;
	cout << "Введите точку " << endl;
	cin >> x >> y;
	a.set_point(x, y);
	cout << "Введите сторону " << endl;
	cin >> x;
	a.set_side(x);
	cout << "Введите угол " << endl;
	cin >> x;
	a.set_angle(x);
	a.show();
	cout << "Введите на что умножить сторону " << endl;
	cin >> x;
	if (x > 0) {
		a.multiplication(x);
	}
	else {
		cout << "Отрицательное число!!!" << endl;
	}
	a.show();
	cout << "Введите вектор смещения " << endl;
	cin >> x >> y;
	a.dispacement(x, y);
	a.show();
	square c;
	cout << "Введите сторону второго квадрата "<<endl;
	cin >> x;
	c.set_side(x);
	if (c > a) {
		cout << "Площадь c > a " << endl;
	}
	if (c < a) {
		cout << "Площадь c < a " << endl;
	}
	if (c == a) {
		cout << "Площадь c = a " << endl;
	}
	if (c != a) {
		cout << "Площадь c != a " << endl;
	}*/
	stack b;
	int n, z;
	cout << "Сколько чисел ввести ? " << endl;
	cin >> n;
	cout << "Введите " << n << " чисел" << endl;
	for (int i = 0;i < n;i++) {
		cin >> z;
		b << z;
	}
	b.show();
	cout << "Сколько чисел удалить ? " << endl;
	cin >> n;
	for (int i = 0;i < n;i++) {
		b >> z;
	}
	b.show();
	cout << "end";
	
	_getch();
}