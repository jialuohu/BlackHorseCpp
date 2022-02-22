#include<iostream>
using namespace std;

class Animal {
public:
	int age;
};


class Sheep: virtual public Animal {
};

class Camel : virtual public Animal {
};

class Apaca : public Sheep, public Camel {
};

void test01() {

	Apaca a1;
	a1.Sheep::age = 100;
	a1.Camel::age = 200;
	cout << "Sheep::age = " << a1.Sheep::age <<endl;
	cout << "Camel::age = " << a1.Camel::age << endl;

	Camel c1;
	c1.age = 400;

	cout << "Sheep::age = " << a1.Sheep::age << endl;
	cout << "Camel::age = " << a1.Camel::age << endl;

}