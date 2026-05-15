#include <iostream>
#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"

int main(){
    Person person1("Daniel Gray", 27, "Blue sky St 233 #56");
    std::cout << "person 1" << person1 << std :: endl;

    std::cout << "-----------------------------" << std::endl;

    Player player;
    player.m_full_name = "Danier mark";
    // player.m_age = 55; complier error 
    std::cout << "player " << player << std :: endl;

    std::cout << "-----------------------------" << std::endl;
    Nurse nurse1;
    // nurse1.m_full_name = "sushma biradar";
    std::cout << "nurse1 " << nurse1 << std :: endl;

    std::cout << "-----------------------------" << std::endl;
    Engineer engineer;
    // engineer.m_full_name = "sushma biradar";
    engineer.build_something();
    std::cout << "engineer " << engineer << std :: endl;

    return 0;
};