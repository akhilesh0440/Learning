#ifndef CIRCLE_H
#define CIRCLE_H

#include <string_view>
#include <iostream>
#include "oval.h"

class Circle : public Oval
{
    public:
        Circle() = default;
        Circle(double, const std::string_view);
        ~Circle();

        virtual void draw() const {
            std::cout << "Circle::draw() called. Drawing " << m_description <<
                    "with m_X_radius : " << get_x_rad() << std::endl;
        }

        virtual void draw(int color_depth) const {
            std::cout << "Circle::Drawing with color depth " << color_depth <<std::endl;
        }

};

#endif
