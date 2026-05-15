#include "civilEngineer.h"
#include <iostream>

CivilEngineer::CivilEngineer(){
    std::cout << "Default Constructor for CivilEngineer called....." << std::endl;
}

CivilEngineer::CivilEngineer(const std::string_view full_name, int age,
    std::string_view adress, int contract_count, std::string_view speciality)
    : Engineer(full_name, age, adress, contract_count), m_speciality(speciality)
    {
        std::cout << "Custom Constructor for CivilEngineer called....." << std::endl;
    };

/* CivilEngineer::CivilEngineer(const std::string_view full_name, int age,
    std::string_view adress, int contract_count, std::string_view speciality)
    {
        m_full_name = full_name;
        m_age = age;
        // m_adress = adress;
        m_speciality = speciality;
        std::cout << "Custom Constructor for CivilEngineer called....." << std::endl;
    }; */

/* CivilEngineer::CivilEngineer(const std::string_view full_name, int age,
    std::string_view adress, int contract_count, std::string_view speciality)
    : m_full_name(full_name), m_age(age), m_adress(adress), m_speciality(speciality)
    {
        m_full_name = full_name;
        m_age = age;
        // m_adress = adress;
        m_speciality = speciality;
        std::cout << "Custom Constructor for CivilEngineer called....." << std::endl;
    }; */


// CivilEngineer::CivilEngineer(std::string_view fullname, int age,
//     const std::string_view address)
//     : m_full_name{fullname}, m_age{age},
//             m_address{address}{

// }

std::ostream& operator<<(std::ostream& out, const CivilEngineer& operand){
   /*  out << "CivilEngineer [Full name : " << operand.get_full_name() << 
                       ", Age : " << operand.get_age() << 
                    ", Adress : " << operand.get_address() <<
                    // ", Contract count : " << operand.get_contract_count() <<
                    ", practice certificate id : " << operand.m_speciality << "]"; */
    return out;
}

void CivilEngineer::build_road(){
    // get_full_name();
    // m_full_name = "Akhileh V"; //Ok
    // m_age = 25;
}

CivilEngineer::~CivilEngineer(){
}
