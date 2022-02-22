//
// Created by Jerry Hu on 2/20/22.
//

#include <iostream>
using namespace std;


class Building;
// 第三种方式访问private
class GoodFriendClass{
public:
    GoodFriendClass();

    void visit();

    ~GoodFriendClass();
private:
    Building * pB;
};

// 会被访问private的类
class Building{
    friend void girlFriendFunction();
    friend class girlFriendClass;
    friend void GoodFriendClass::visit();
private:
    string myBedroom;
public:
    Building(string bedroom, string livingroom): myBedroom(bedroom), myLivingroom(livingroom){
    }
    string myLivingroom;
};


// 普通函数访问private
void girlFriendFunction(){
    Building b1{"卧室", "客厅"};
    cout << "普通函数访问private: " << endl;
    cout << "viewing " << b1.myLivingroom << endl;
    cout << "viewing " << b1.myBedroom << endl;
}

void test_1(){
    girlFriendFunction();
}


// 类访问private
class girlFriendClass{
public:
    girlFriendClass(){
        pB = new Building("卧室","客厅");
    }

    void visit(){
        cout << "类访问private: " << endl;
        cout << "viewing " << pB->myLivingroom << endl;
        cout << "viewing " << pB->myBedroom << endl;
    }
    ~girlFriendClass(){
        delete pB;
    }
private:
    Building * pB;
};

void test_2(){
    girlFriendClass g1;
    g1.visit();
}


// 只有类成员函数访问private
GoodFriendClass::GoodFriendClass(){
    pB = new Building("卧室","客厅");
}

void GoodFriendClass::visit(){
    cout << "只有类成员函数访问private: " << endl;
    cout << "viewing " << pB->myLivingroom << endl;
    cout << "viewing " << pB->myBedroom << endl;
}

GoodFriendClass::~GoodFriendClass(){
    delete pB;
}


void test_3 (){
    GoodFriendClass g1;
    g1.visit();
}

int main(){
    cout << "------------------ " << endl;
    test_1();
    cout << "------------------ " << endl;
    test_2();
    cout << "------------------ " << endl;
    test_3();
    cout << "------------------ " << endl;
    return 0;
}