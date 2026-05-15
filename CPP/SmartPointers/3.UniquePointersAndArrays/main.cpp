#include <iostream>
#include <memory>
#include "dog.h"
#include "person.h"

int main(){
    /* {
        std::cout << "workin with dog array on the stack" << std::endl;
        Dog dog_array[3] {Dog("Dog1"), Dog("Dog2"), Dog("Dog3")};
        for(size_t i{0}; i < 3; i++){
            dog_array[i].print_info();
        }
        
    } */

    {
        // std::unique_ptr<Dog[]> raw_array = std::unique_ptr<Dog[]>(new Dog[3]{Dog("Dog4"), Dog("Dog5"), Dog("Dog6")});
        auto arr_ptr = std::make_unique<Dog[]>(3);
        for(size_t i{0}; i < 3; i++){
            arr_ptr[i].print_info();
        }
    }
    std::cout << "Done !" <<std::endl;
}