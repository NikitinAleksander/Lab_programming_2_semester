#ifndef HEADER_H
#define HEADER_H
#include<iostream>

using namespace std;

struct point {
	float x;
	float y;
};

class square {
public:
	square();

	void set_point(float x, float y);

	void set_side(float tmp);

	void set_angle(float tmp);

	void multiplication(float tmp);

	void dispacement(float x, float y);

	void show();

	bool operator>(square &obj);

	bool operator<(square &obj);

	bool operator==(square &obj);

	bool operator!=(square &obj);
	

private:
	point A;
	float side;
	float angle;
	double area;
};

class stack {
private:
struct 	element *head;
int n;
public:
	stack();

	void operator<<(int a);

	void show();

	int top();

	void pop();

	bool empty();

	void operator>>(int a);

	~stack();
};
#endif//HEADER_H