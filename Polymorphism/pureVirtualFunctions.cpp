
#include<iostream>
using namespace std;

class Human {
public:
	virtual void showAge() = 0;
};

class Man : public Human {
public:
	virtual void showAge() {
		cout << "Man::showAge()"<< endl;
	}
};

class Woman : public Human {
public:
	virtual void showAge() {
		cout << "Woman::showAge()" << endl;
	}
};

 void asd_main() {
	Human * hptr = new Man;
	hptr->showAge();
}