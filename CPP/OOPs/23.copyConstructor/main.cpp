#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilEngineer.h"

int main(){

   CivilEngineer Ceng1("Daniel Gray", 41, "Green Sky oh Blue 33St#75", 12, "Road strengh");

   std::cout << "----------------------------" << std::endl;

   CivilEngineer Ceng2(Ceng1);
   std::cout << "Eng2 : " << Ceng2 << std::endl;


    return 0;
};