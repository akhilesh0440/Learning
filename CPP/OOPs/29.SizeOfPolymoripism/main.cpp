#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"



int main(){

    // std::cout << "sizeof(Shape) : " << sizeof(Shape) << std::endl; //dynamic :40
    // std::cout << "sizeof(Oval) : " << sizeof(Oval) << std::endl; //dynaic : 56
    // std::cout << "sizeof(Circle) : " << sizeof(Circle) << std::endl; //dynamic: 56

    // Slicing 
    Circle circle1(3.3, "Circle1");
    Shape shape1("Shape");
    Oval oval1(3, 2, "Oval");
    
    // Shape shape = circle1; //slice of circle and oval info and will just hold the shape part


    Oval * shape_collection[]{&circle1, &oval1};
    
    for(Oval *ptr : shape_collection){
        std::cout << "sizeof : " << sizeof(*ptr) << std::endl; //dynamic :40
    }

    return 0;
}