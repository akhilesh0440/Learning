#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilEngineer.h"

int main(){

   /*  Person p1("Akhilesh V", 24, "Bengaluru");
    std::cout << "Person" << p1 << std::endl; */

    /* std::cout << "\n--------------------------" << std::endl;
    Engineer E("Sushma", 24, "Kalaburgi", 12);
    std::cout << "Person" << E << std::endl; */

    std::cout << "\n--------------------------" << std::endl;
    CivilEngineer CE("Shashi", 25, "Hassan", 12, "Mindri");
    std::cout << "Person" << CE << std::endl;


    return 0;
};