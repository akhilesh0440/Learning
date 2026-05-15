#include "nurse.h"
#include <iostream>

Nurse::Nurse(){

}

// Nurse::Nurse(std::string_view fullname, int age,
//     const std::string_view address)
//     : m_full_name{fullname}, m_age{age},
//             m_address{address}{

// }

std::ostream& operator<<(std::ostream& out, const Nurse& operand){
    out << "Nurse [Full name : " << operand.get_full_name() << 
                       ", Age : " << operand.get_age() << 
                    ", Adress : " << operand.get_address() <<
                    ", practice certificate id : " << operand.practice_certificate_id << "]";
    return out;
}

void Nurse::treat_unwell_person(){
    m_full_name = "Akhileh V"; //Ok
    m_age = 25;
    // m_address = "Mysuru"; compiler error 
}

Nurse::~Nurse(){
}
