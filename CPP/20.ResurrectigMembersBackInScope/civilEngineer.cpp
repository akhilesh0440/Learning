#include "civilEngineer.h"
#include <iostream>

CivilEngineer::CivilEngineer(){

}

// CivilEngineer::CivilEngineer(std::string_view fullname, int age,
//     const std::string_view address)
//     : m_full_name{fullname}, m_age{age},
//             m_address{address}{

// }

std::ostream& operator<<(std::ostream& out, const CivilEngineer& operand){
    out << "CivilEngineer [Full name : " << operand.get_full_name() << 
                       ", Age : " << operand.get_age() << 
                    ", Adress : " << operand.get_address() <<
                    // ", Contract count : " << operand.get_contract_count() <<
                    ", practice certificate id : " << operand.m_speciality << "]";
    return out;
}

void CivilEngineer::build_road(){
    // get_full_name();
    // m_full_name = "Akhileh V"; //Ok
    // m_age = 25;
}

CivilEngineer::~CivilEngineer(){
}
