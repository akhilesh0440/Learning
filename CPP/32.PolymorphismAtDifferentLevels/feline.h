#ifndef FELINE_H
#define FELINE_H

#include "animal.h"

class Feline : public Animal
{
    public:
        Feline() = default;
        Feline(const std:: string_view fur_style, const std::string_view description);
        ~Feline();

        virtual void run() const {
            std::cout << "Feline::brath called for : " << m_description << std::endl;
        }

    protected:
        std::string m_description;

};

#endif
