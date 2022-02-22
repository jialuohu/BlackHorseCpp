//
// Created by Jerry Hu on 2/20/22.
//
#include <iostream>
using namespace std;

// 由于show需要知道Person类型
template <class NameType , class AgeType > class Person;

// 需要让编译器知道show的存在。
//template <class NameType, class AgeType>
//void show(Person<NameType, AgeType> & p){
//    cout << "Name is: "<< p.name << ", Age is: " << p.age;
//}

template <class NameType = string , class AgeType = int>
class Person{
public:

    // 全局函数类外实现
//    friend void show<>(Person<NameType, AgeType> & p);

    // 全局函数类内实现
    friend void show(Person & p){
        cout << "Name is: "<< p.name << ", Age is: " << p.age;
    }

    Person(NameType vName, AgeType vAge): name(vName), age(vAge){
    }

private:
    NameType name;
    AgeType age;
};

void test_1(){
    Person<> p1{"dog", 1};
    show(p1);
}

int main(){
    test_1();
    return 0;
}


