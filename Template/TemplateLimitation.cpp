#include<iostream>
#include<string>
using namespace std;

class Person {

public:
	Person(int age, string name) : age(age), name(name) {
	}
	int age;
	string name;
};

template <typename T>
bool myCompare(T & a, T & b) {
	return a == b;
}

// 使用空模板来提醒compiler如何对比Person类
template <>
bool myCompare(Person & a, Person & b) {
	return a.age == b.age && a.name == b.name;
}

// 也可以直接用普通函数
bool myCompare(Person& a, Person& b) {
	return a.age == b.age && a.name == b.name;
}

void test_1() {
	Person a{20, "Tom"};
	Person b{20, "Tom"};

	//myCompare<>(a, b) 用空模板强调调用模板函数
	//myComapre(a, b) 默认调用普通函数
	if (myCompare<>(a, b)) {
		cout << "a == b" << endl;
	}
	else {
		cout << "a != b" << endl;
	}
}

int main() {

	test_1();
	return 0;
}