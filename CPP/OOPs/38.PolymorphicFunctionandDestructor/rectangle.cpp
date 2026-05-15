#include "rectangle.h"

Rectangle::Rectangle(double width, double heigth, std::string_view description)
    : Shape(description), m_width(width), m_height(heigth){
        
    }