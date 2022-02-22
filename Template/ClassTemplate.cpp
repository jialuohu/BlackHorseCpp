#include <iostream>
#include <string>
#include "PeopleClass.hpp"
using namespace std;

template <class NameType, class AgeType = int>
class Person{
public:
    Person(NameType vName, AgeType vAge): name(vName), age(vAge){
    }
    void showPerson(){
        cout << "The person's name is " << this->name << ", and the age is " << this->age << endl;
    }
    NameType name;
    AgeType age;
};

// 默认template类型：
void test_1(){
    Person<string,int> p1{"shit", 100};
    Person<string> p2{"dog", 999};
    Person<int,string> p3{1234, "hello"};
    p1.showPerson();
    p2.showPerson();
    p3.showPerson();
};

// 如何将模板类作为parameter传入function：
// 参数指定化
void printPerson_1(Person<string, int> & p){
    p.showPerson();
}
// 参数模板化
template<typename T1, typename T2>
void printPerson_2(Person<T1, T2> & p){
    p.showPerson();
//    cout << "T1's name: " << typeid(T1).name() << endl;
//    cout << "T2's name: " << typeid(T2).name() << endl;
}

// 整个类模板化
template<typename T>
void printPerson_3(T & p){
    p.showPerson();
}
void test_2(){
    Person<string, int> p1{"dog", 10};
    printPerson_1(p1);
    cout << "-------------------" << endl;
    printPerson_2(p1);
    cout << "-------------------" << endl;
    printPerson_3(p1);
}

// 模板类与继承：
template<class NumType>
class Base{
public:
    NumType num;
};

// 指定父类的类型
class Son1: public Base<int>{
};

// 将自身变为模板
template<class BaseType>
class Son2: public Base<BaseType>{
};


// 类模板成员函数在类外实现
template <class NameType = string, class AgeType = int>
class People{
public:
    People(NameType vName, AgeType vAge);
    void showPerson();
    NameType name;
    AgeType age;
};

template<class NameType, class AgeType>
People<NameType, AgeType>::People(NameType vName, AgeType vAge): name(vName), age(vAge){
}

template<class NameType, class AgeType>
void People<NameType, AgeType>::showPerson(){
    cout << "The name is: " << name << ", the age is: " << age << endl;
}

void test_4(){
    People<string,int> p1{"dog", 100};
    People<> p2{"apple", 2};
    p1.showPerson();
    p2.showPerson();
}


// 分文件编写类模板, 使用.hpp 类型（仅为约定俗成）。
// 这是由于类模板成员函数不会再编译阶段就产生或者link，所以导致linker并没有连接声明与定义，因此当在其他地方调用成员函数时，会产生错误。
void test_5(){
    PeopleClass<> p1{"dog", 123};
    p1.showPerson();
}

int main(){
//    test_1();
//    test_2();

//    test_4();
    test_5();
    return 0;
}