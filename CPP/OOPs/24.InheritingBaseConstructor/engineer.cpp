#include "engineer.h"
#include <iostream>

Engineer::Engineer(){
    std::cout << "Default Constructor for Engineer called....." << std::endl;
}

Engineer::Engineer(const std::string_view full_name, int age,
        std::string_view adress, int contract_count) : 
        Person(full_name, age, adress), contract_count(contract_count){
        std::cout << "Custom Constructor for Engineer called....." << std::endl;  
        }

/*        

Engineer::Engineer(const Engineer& source)
: Person(source), contract_count(source.contract_count)
{
    std::cout << "Custom Copy Constructor for Engineer called....." << std::endl;  
} */

std::ostream& operator<<(std::ostream& out, const Engineer& operand){
    out << "Engineer [Full name : " << operand.get_full_name() << 
                       ", Age : " << operand.get_age() << 
                    ", Adress : " << operand.get_address() <<
                    ", practice certificate id : " << operand.contract_count << "]";
    return out;
}

void Engineer::build_something(){
    m_full_name = "Akhileh V"; //Ok
    m_age = 25;
    // m_address = "Mysuru"; //compiler error 
}

Engineer::~Engineer(){
}
