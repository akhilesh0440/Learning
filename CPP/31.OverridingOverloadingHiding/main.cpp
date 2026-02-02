#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"



int main(){

    Circle circle1(7.2, "Circle1");
    Oval oval1 (13, 1.2, "Oval1");

    circle1.draw();
    circle1.draw(44);

    oval1.draw();
    oval1.draw(44);    



    return 0;
}