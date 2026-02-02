#ifndef OVAL_H
#define OVAL_H

#include <string_view>
#include <iostream>
#include "shape.h"

class Oval : public Shape
{
    public:
        Oval() = default;
        Oval(double, double, const std::string_view);
        ~Oval();

        virtual void draw() const {
            std::cout << "Oval::draw() called. Drawing " << m_description <<
                    "with m_X_radius : " << m_x_radius << "and m_y_radius : " << m_y_radius << std::endl;
        }

    protected:
        double get_x_rad() const{
            return m_x_radius;
        }

        double get_y_rad() const{
            return m_y_radius;
        }

    private:
    double m_x_radius{0.0};
    double m_y_radius{0.0};
};

#endif
