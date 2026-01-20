#include <iostream>
#include "person.h"
#include "engineer.h"

int main(){

    Engineer eng1("Daniel Gray", 25, "Electronic city", 4);
    std::cout << "Eng 1 : " << eng1 << std::endl;

    return 0;
};