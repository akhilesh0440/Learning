#include <iostream>
#include "dog.h"

int main(){
    // Base class pointer 
    Animal *animal1 = new Feline("Stripes", "feline1");

    std::cout << "-----------------" << std::endl;
    Feline *animalToFeline = dynamic_cast<Feline*>(animal1);

    if(animalToFeline){
        animalToFeline->do_some_feline_thingy();
    }
    else{
        std::cout << "Couldn't do the transformation from Animal* to Dog*" << std::endl;
    }


/* 
    std::cout << "----------Reference dynamic cast---------" << std::endl;
    Feline feline2 ("stripes", "feline2");
    Animal &animal_ref = feline2;

    // animal_ref.do_some_feline_thingy();

    Feline &feline_ref {dynamic_cast<Feline&>(animal_ref)};
    feline_ref.do_some_feline_thingy();

    std::cout << "Done!" << std::endl;

    std::cout << "----------Casting from ref to pointer---------" << std::endl;
    Feline* feline_ptr1 = {dynamic_cast<Feline*>(&animal_ref)};
    if(feline_ptr1){
        feline_ptr1->do_some_feline_thingy();
    }
    else{
        std::cout << "Couldn't do the transformation from Animal* to Dog*" << std::endl;
        
    } */


    delete animal1;


    return 0;
}