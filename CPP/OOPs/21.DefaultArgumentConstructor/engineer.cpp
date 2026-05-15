#include "engineer.h"
#include <iostream>

Engineer::Engineer(){
    std::cout << "Default Constructor for Engineer called....." << std::endl;
}


// Engineer::Engineer(std::string_view fullname, int age,
//     const std::string_view address)
//     : m_full_name{fullname}, m_age{age},
//             m_address{address}{

// }

std::ostream& operator<<(std::ostream& out, const Engineer& operand){
    out << "Engineer [Full name : " << operand.get_full_name() << 
                       ", Age : " << operand.get_age() << 
                    ", Adress : " << operand.get_address() <<
                    ", practice certificate id : " << operand.contract_count << "]";
    return out;
}

int Engineer::get_contract_count(){
    return contract_count;
}

void Engineer::build_something(){
    m_full_name = "Akhileh V"; //Ok
    m_age = 25;
    // m_address = "Mysuru"; //compiler error 
}

Engineer::~Engineer(){
}
