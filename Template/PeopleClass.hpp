//
// Created by Jerry Hu on 2/20/22.
//

#ifndef CPP_PEOPLE_HPP
#define CPP_PEOPLE_HPP
#include <iostream>
#include <string>

template <class NameType = std::string, class AgeType = int>
class PeopleClass{
public:
    PeopleClass(NameType vName, AgeType vAge);
    void showPerson();
    NameType name;
    AgeType age;
};

template<class NameType, class AgeType>
PeopleClass<NameType, AgeType>::PeopleClass(NameType vName, AgeType vAge): name(vName), age(vAge){
}

template<class NameType, class AgeType>
void PeopleClass<NameType, AgeType>::showPerson(){
    std::cout << "The name is: " << name << ", the age is: " << age << std::endl;
}

#endif //CPP_PEOPLE_HPP
