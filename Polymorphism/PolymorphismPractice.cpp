#include<iostream>
using namespace std;


class AbstractMakeDrink {

public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void pourItIntoCup() = 0;
	virtual void addSomething() = 0;

	void makeDrink() {
		boil();
		brew();
		pourItIntoCup();
		addSomething();
	}
};

class Coffee : public AbstractMakeDrink {
public:
	virtual void boil() {
		cout << "Boil the water for a cup of Coffee" << endl;
	}
	virtual void brew() {
		cout << "Brew the Coffee" << endl;
	}
	virtual void pourItIntoCup() {
		cout << "Pour water in Coffee cup" << endl;
	}
	virtual void addSomething() {
		cout << "Add sugar and milk into Coffee cup" << endl;
	}
};

class Tea : public AbstractMakeDrink {

public:
	virtual void boil() {
		cout << "Boil the water for a cup of Tea" << endl;
	}
	virtual void brew() {
		cout << "Brew the Tea" << endl;
	}
	virtual void pourItIntoCup() {
		cout << "Pour water in Tea cup" << endl;
	}
	virtual void addSomething() {
		cout << "Add lemon into Tea cup" << endl;
	}
};

void implementDrink (AbstractMakeDrink * pDrink) {
	pDrink->makeDrink();
	delete pDrink;
}

void implementDrink(AbstractMakeDrink & refDrink) {
	refDrink.makeDrink();
}
void test_1() {
	implementDrink(new Coffee);
	cout << "--------------------" << endl;
	implementDrink(new Tea);
}

int main() {
	
	test_1();
	return 0;
}