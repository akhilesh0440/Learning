#include "person.h"
#include <iostream>

Person::Person(){
    std::cout << "Default Constructor for Person called....." << std::endl;
}

Person::Person(std::string_view fullname, int age,
    const std::string_view address)
    : m_full_name{fullname}, m_age{age},
            m_address{address}{

}

std::ostream& operator<<(std::ostream& out, const Person& person){
    out << "Person [Full name : " << person.get_full_name() << 
                       ", Age : " << person.get_age() << 
                    ", Adress : " << person.get_address() << "]";
    return out;
}

// Person::~Persion(){

// }
