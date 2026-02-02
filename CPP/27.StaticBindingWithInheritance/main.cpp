#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

void draw(Oval& oval){
    oval.draw();
}

void draw(Circle& circle){
    circle.draw();
}

int main(){

    Shape shape1("Shape1");
    // Shape1.draw();

    Oval oval1(2.0, 3.5, "Oval1");
    // oval1.draw();

    Circle circle1(3.3, "Circle1");
    // circle1.draw();

    // Base poitners 
    Shape * shape_ptr = &shape1;
    // shape_ptr->draw();

    // shape_ptr = &oval1;
    // shape_ptr->draw();


    // Base reference 
    Shape& shape_ref = shape1;
    // shape_ref.draw();


    // Drawing shapes 
    draw(circle1);
    draw(oval1);

     
    return 0;
}