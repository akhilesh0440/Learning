#ifndef BIRD_H
#define BIRD_H

#include <string_view>
#include "animal.h
class Bird : public Animal
{
    public:
        Bird() = default;
        Bird(std::string_view wing_color, const std::string_view description);
        virtual ~Bird();

        virtual void fly() const {
            std::cout << "Bird::breath called for " << m_wing_color <<std::endl;
        }

    private:
        std::string m_wing_color{""};
};

#endif
