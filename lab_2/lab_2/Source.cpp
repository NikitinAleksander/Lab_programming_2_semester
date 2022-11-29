#include<iostream>
#include"Header.h"

	struct element {
		int x;
		element* next;
	};

	stack::stack() {
		head = NULL;
		n = 0;
	}

	void stack::operator<<(int a) {
		if (n < 100) {
			n++;
			element*tmp = new element;
			tmp->x = a;
			tmp->next = head;
			head = tmp;
		}
		else {
			cout << "Стек переполнен!"<<endl;
		}
	}

	void stack::show() {
		element*tmp = head;
		if (head == NULL) {
			cout << "Стек пуст";
		}
		while (tmp != NULL) {
			cout << tmp->x << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	int stack::top() {
		return head->x;
	}

	void stack::pop() {
		head = head->next;
	}

	bool stack::empty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void stack::operator>>(int a) {
		if (n > 0) {
			n--;
			head = head->next;
		}
		else {
			cout << "Стек пуст, нельзя удалить элемент"<<endl;
		}
	}

	stack::~stack() {
		while (head != NULL) {
			element* tmp = head->next;
			delete head;
			head = tmp;
		}
	}

	


	square::square() {
			side = NULL;
			angle = NULL;
			A.x = NULL;
			A.y = NULL;
		}
		void square::set_point(float x, float y) {
			A.x = x;
			A.y = y;
		}
		void square::set_side(float tmp) {
			side = tmp;
			area = side * side;
		}
		void square::set_angle(float tmp) {
			angle = tmp;
		}
		void square::multiplication(float tmp) {
			side = side * tmp;
			area = side * side;
		}
		void square::dispacement(float x, float y) {
			A.x = A.x + x;
			A.y = A.y + y;
		}
		void square::show() {
			cout << "point =(" << A.x << "," << A.y << ")" << endl;
			cout << "side= " << side << endl;
			cout << "angle= " << angle << endl;
		}
		bool square::operator>(square &obj) {
			if (this->area > obj.area) {
				return true;
			}
			else {
				return false;
			}
		}
		bool square::operator<(square &obj) {
			if (this->area < obj.area) {
				return true;
			}
			else {
				return false;
			}
		}
		bool square::operator==(square &obj) {
			if (this->area == obj.area) {
				return true;
			}
			else {
				return false;
			}
		}
		bool square::operator!=(square &obj) {
			if (this->area != obj.area) {
				return true;
			}
			else {
				return false;
			}
		}
