#include <iostream>
#include "derived.h"
#include "base.h"

int main(){

    Base *base_ptr = new Derived;
    double result = base_ptr->add();
    std::cout << "Result (base ptr) : " << result << std::endl;

    std::cout << "--------------------------------------" << std::endl;
    
    // Base ref : uses polymorpism
    Derived *base_ptr1 = new Derived;
    double result1 = base_ptr1->add();
    std::cout << "Result (derived ptr) : " << result1 << std::endl;

    std::cout << "--------------------------------------" << std::endl;
    // Raw objects 
    Derived derived1;
    double result2 = derived1.add();
    std::cout << "Result (raw ptr) : " << result2 << std::endl;

    std::cout << "--------------------------------------" << std::endl;
    // Raw objects - slicing objects
    Base base1 = derived1;
    double result3 = base1.add();
    std::cout << "Result (raw ptr) : " << result3 << std::endl;


}