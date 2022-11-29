#include <iostream>
#include"Header1.h"

using namespace std;

void change(int &a, int &b) {
	if (a > b) {
		a = a % b;
	}
	else {
		b = b % a;
	}
}

void change1(int *a, int *b) {
	if (*a > *b) {
		*a = *a % *b;
	}
	else {
		*b = *b % *a;
	}
}

void reverse(float &a) {
	a = 1 / a;
}
void reverse1(float *a) {
	*a = 1 / *a;
}

void decrease_r(float &r, float d) {
	r = r - d;
}
void decrease_r1(float *r, float d) {
	*r = *r - d;
}

void change_line(int **mas,int n,int m, int x, int y) {
	int tmp;
	for (int j = 0;j < m;j++) {
		tmp = mas[x][j];
		mas[x][j] = mas[y][j];
		mas[y][j] = tmp;
	}
}