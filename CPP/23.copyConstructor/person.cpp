#include "person.h"
#include <iostream>

Person::Person(){
    std::cout << "Default Constructor for Person called....." << std::endl;
}

Person::Person(std::string_view fullname, int age,
    std::string_view address)
    : m_full_name{fullname}, m_age{age},
            m_address{address}{
    std::cout << "Custom Constructor for Person called....." << std::endl;
}

Person::Person(const Person& source)
    : m_full_name(source.m_full_name), m_address(source.m_address), 
        m_age(source.m_age){
    std::cout << "Custom Copy Constructor for Person called....." << std::endl;

}


std::ostream& operator<<(std::ostream& out, const Person& person){
    out << "Person [Full name : " << person.get_full_name() << 
                       ", Age : " << person.get_age() << 
                    ", Adress : " << person.get_address() << "]";
    return out;
}

// Person::~Persion(){

// }
