#include<iostream>
#include"Header1.h"
#include<conio.h>

using namespace std;


int main() {
	int a, b;
	cout << "Введите два числа "<<endl;
	cin >> a >> b;
	if (a > b) {
		cout << a<<" % "<<b<<" = ";
	}
	else {
		cout << b << " % " << a << " = ";
	}
	change(a, b);
	cout << a << endl;
	cout << "Введите два числа " << endl;
	cin >> a >> b;
	if (a > b) {
		cout << a << " % " << b << " = ";
	}
	else {
		cout << b << " % " << a << " = ";
	}
	change1(&a, &b);
	cout << a << endl;
	float c;
	cout << "Введите число " << endl;
	cin >> c;
	cout << "число обратное для " << c << " = ";
	reverse(c);
	cout << c << endl;
	cout << "Введите число " << endl;
	cin >> c;
	cout << "число обратное для " << c<<" = ";
	reverse1(&c);
	cout << c<<endl;
	float r,d;
	cout << "Введите радиус и на что его нужно уменьшить " << endl;
	cin >> r>>d;
	decrease_r(r,d);
	cout << "Радиус равен ";
	cout << r << endl;
	cout << "Введите радиус и на что его нужно уменьшить " << endl;
	cin >> r >> d;
	decrease_r1(&r,d);
	cout << "Радиус равен ";
	cout << r << endl;
	int n,m ;
	cout << "Введите размерность матрицы"<<endl;
	cin >> n >> m;
	cout << "Введите матрицу " << endl;
	int **mas = new int *[n];
	for (int i = 0;i < n;i++) {
		mas[i] = new int[m];
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> mas[i][j];
		}
	}
	int x, y;
	cout << "Введите какие строки нужно поменять" << endl;
	cin >> x >> y;
	x = x - 1;
	y = y - 1;
	change_line(mas,n,m, x, y);
	cout << "Новая матрица " << endl;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << "end";
	/*int a=10;
	int &b = a;
	b = 12;
	cout <<b<<a;*/
	_getch();
}