#include "feline.h"      

Feline::Feline(std::string_view fur_style, std::string_view description)
        : Animal(description){

}

      

Feline::~Feline(){
    std::cout << "Feline Destructor called" << std::endl;
}