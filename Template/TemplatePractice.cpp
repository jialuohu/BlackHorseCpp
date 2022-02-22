#include<iostream>
using namespace std;

template<typename T>
void mySwap(T & lNum, T & rNum) {
	T temp = lNum;
	lNum = rNum;
	rNum = temp;
}

template<typename T>
T myPlus(T a, T b) {
	return a + b;
}

void test_1() {
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "---------------------" << endl;
	mySwap(a, b);
	cout << "After Swapping (a, b)" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "---------------------" << endl;
	mySwap(a, b);
	cout << "After Swapping (a, b) again" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "---------------------" << endl;
	//mySwap<int>(a, c);
	mySwap<int>(a, b);
	cout << "After Swapping <int>(a, b)" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "---------------------" << endl;
	cout << "a + c = " << myPlus<int>(a, c);
}


int main() {
	test_1();
	return 0;
}