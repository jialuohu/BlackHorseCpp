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

// ʹ�ÿ�ģ��������compiler��ζԱ�Person��
template <>
bool myCompare(Person & a, Person & b) {
	return a.age == b.age && a.name == b.name;
}

// Ҳ����ֱ������ͨ����
bool myCompare(Person& a, Person& b) {
	return a.age == b.age && a.name == b.name;
}

void test_1() {
	Person a{20, "Tom"};
	Person b{20, "Tom"};

	//myCompare<>(a, b) �ÿ�ģ��ǿ������ģ�庯��
	//myComapre(a, b) Ĭ�ϵ�����ͨ����
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