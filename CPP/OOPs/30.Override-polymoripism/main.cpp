#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"



int main(){

    Circle circle1(7.2, "Circle1");
    Oval oval1 (13, 1.2, "Oval1");
    Circle circle2(7.2, "Circle2");
    Oval oval2 (13, 1.2, "Oval2");
    Circle circle3(7.2, "Circle3");
    Oval oval3 (13, 1.2, "Oval3");

    Shape * shapes3[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};
    for(Shape * shape_ptr : shapes3){
        std::cout << "Inside array, sizeof(*shape_ptr) : " << sizeof(*shape_ptr) << std::endl;
        shape_ptr->draw();
        std::cout << std::endl;
    }

    return 0;
}