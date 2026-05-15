#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"



void draw_shape(Shape *shape){
    shape->draw();
}

void draw_shape(const Shape& s_r){
    s_r.draw();
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

    shape_ptr = &oval1;
    // shape_ptr->draw();

    shape_ptr = &circle1;
    // shape_ptr->draw();


    // Base reference 
    Shape& shape_ref = oval1;
    // shape_ref.draw();

    //Drawing shapes

    // draw_shape(shape1);
    // draw_shape(oval1);
    // draw_shape(circle1);

    // Shapes stored in collection 

    Shape* shape_collection[](&shape1, &oval1, &circle1);
    for(Shape *sh_pt: shape_collection){
        sh_pt->draw();
    }

     
    return 0;
}