#include <iostream>
#include "person.h"
#include "engineer.h"

int main(){
    Person person1("Daniel Gray", 27, "Blue sky St 233 #56");
    std::cout << "person 1" << person1 << std :: endl;


    std::cout << "-----------------------------" << std::endl;
    Engineer engineer;
    // engineer.m_full_name = "sushma biradar";
    engineer.build_something();
    std::cout << "engineer " << engineer << std :: endl;

    return 0;
};