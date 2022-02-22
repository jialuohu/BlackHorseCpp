#include<iostream>
using namespace std;


class Person {
public:
	void showPerson() const {
		m_B = 300;
	}

	int m_A;
	mutable int m_B;
};


void a_main() {
	const Person p1{};

	p1.showPerson();
	cout << p1.m_B << endl;
	
}