#include <iostream>
#include <memory>
#include "dog.h"



int main(){
    /* {
        std::shared_ptr<int> int_ptr_1 {new int{55}};
        std::cout << "The pointed to value is: " << *int_ptr_1 << std::endl;
        *int_ptr_1 = 40;
        std::cout << "The pointed to value is: " << *int_ptr_1 << std::endl;
        // std::cout << "Address of int_ptr1: " << int_ptr_1.get() << std::endl;

        std::cout << "----------------" << std::endl;
        std::shared_ptr<int> int_ptr_2{int_ptr_1};
        std::cout << "The pointed to value is (through int_ptr2): " << *int_ptr_2 << std::endl;
        *int_ptr_2 = 70;
        std::cout << "The pointed to value is (through int_ptr2): " << *int_ptr_2 << std::endl;
        
        std::cout << "----------------" << std::endl;
        std::shared_ptr<int> int_ptr_3;
        int_ptr_3 = int_ptr_1;
        std::shared_ptr<int> int_ptr_4;
        int_ptr_4 = int_ptr_1;

        std::shared_ptr<int> int_ptr_5{int_ptr_1};
        std::cout << "The pointed to value is (through int_ptr5): " << *int_ptr_5 << std::endl;
        *int_ptr_5 = 555;
        std::cout << "The pointed to value is (through int_ptr5): " << *int_ptr_5 << std::endl;
        std::cout << std::endl << "reset..." << std::endl;
        int_ptr_5.reset();

        int_ptr_4.reset();
        int_ptr_3.reset();
        int_ptr_2.reset();
        int_ptr_1.reset();
       
        std::cout << "Use count int_ptr_1: " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count int_ptr_2: " << int_ptr_2.use_count() << std::endl;
        std::cout << "Use count int_ptr_3: " << int_ptr_3.use_count() << std::endl;
        std::cout << "Use count int_ptr_4: " << int_ptr_4.use_count() << std::endl;
        std::cout << "Use count int_ptr_5: " << int_ptr_5.use_count() << std::endl;
        
        std::cout << "----------------" << std::endl;
        int *int_ptr_raw = new int{33};
        std::shared_ptr<int> int_ptr_6{int_ptr_raw};
        int_ptr_raw = nullptr;
        std::cout << "The pointed to value is (through int_ptr_raw): " << *int_ptr_6 << std::endl;
        std::cout << "Use count int_ptr_6: " << int_ptr_6.use_count() << std::endl;
        std::cout << "raw pointer: " << int_ptr_raw << std::endl;
        std::cout << "int_ptr_6.get(): " << int_ptr_6.get() << std::endl;

        std::cout << std::boolalpha;

        std::cout <<"int_ptr_4->bool: " << static_cast<bool>(int_ptr_4) << std::endl;
        std::cout <<"int_ptr_5->bool: " << static_cast<bool>(int_ptr_5) << std::endl;
        
        if(int_ptr_4){
            std::cout << "int_ptr_4 poining to something valid" << std::endl;
        }
        else{
            std::cout << "int_ptr_4 pointing to nullptr" << std::endl;
        }
    } */

    // Shared pointer with custom types 

    /* {
        std::shared_ptr<Dog> dog_ptr_1{new Dog("Dog 1")};
        dog_ptr_1->print_info();

        std::cout << "Use count: " << dog_ptr_1.use_count() << std::endl;
        std::shared_ptr<Dog> dog_ptr_2 = dog_ptr_1;

        std::cout << "Use count for dog_ptr_1: " << dog_ptr_1.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_2: " << dog_ptr_2.use_count() << std::endl;

    } */


    // make_shared
    {
        std::shared_ptr<int> int_ptr_6 = std::make_shared<int>(5);
        std::shared_ptr<Dog> dog_ptr_1 = std::make_shared<Dog>("Julie");
        dog_ptr_1->print_info();

        std::cout << "int_ptr_6 use count: " << int_ptr_6.use_count() << std::endl;
        std::cout << "dog_ptr_1 use count: " << dog_ptr_1.use_count() << std::endl;
    }
    std::cout << "Done!" << std::endl;


}