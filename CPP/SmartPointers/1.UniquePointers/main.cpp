#include <iostream>
#include <memory>
#include "dog.h"

int main(){
    
    // Stack variables 
    /* 
    {
        Dog dog1("Dog1");
        dog1.print_dog();
    }

    std::cout << "Hitting outside scope" << std::endl;
    std::cout << "Done!" << std::endl; */

    // ---------------------------------------------------------------------------
    // using raw pointers : remrember to manually release memory, 
    //                     if you don't release, you leak memory

    /* Dog *p_dog2 = new Dog("Dog2");
    int *p_int1 = new int(100);

    p_dog2->print_dog();
    std::cout << "Integer is : " << *p_int1 << std::endl;
    std::cout << "Integer lives at address: " << p_int1 << std::endl;

    delete p_dog2;  // Calls the destructor
    delete p_int1;
    return 0; */
    
    // ---------------------------------------------------------------------------

    /* {
    Dog *p_dog2 = new Dog("Dog2");
    std::unique_ptr<Dog> up_dog_4{p_dog2};


    std::unique_ptr<Dog> up_dog_5{new Dog("Dog5")};
    std::unique_ptr<int> up_int{new int(100)};
    std::unique_ptr<Dog> up_dog_6{nullptr};
    up_dog_5->print_dog();

    *up_int = 500;

    std::cout << "Integer is: " << *up_int << std::endl;
    std::cout << "Integer lives at address: " << up_int.get() << std::endl;
    } */

    // ---------------------------------------------------------------------------

    /* std::unique_ptr<Dog> up_dog_7 = std::make_unique<Dog>("Dog7");
    up_dog_7->print_dog();

    std::unique_ptr<int> p_int3 = std::make_unique<int>(100);
    *p_int3 = 67;
    std::cout << "Value pointer to by p_int3 is: " << *p_int3 << std::endl;
    std::cout << "p_int pointing at adress: " << p_int3.get() << std::endl;
 */

    // ---------------------------------------------------------------------------
    // Copies are not allowed
    /* std::unique_ptr<Dog> up_dog_8 = std::make_unique<Dog>("Dog 8");
    up_dog_8->print_dog();

    std::cout << "Dog 8 memory address: " << up_dog_8.get() << std::endl;
 */
    // std::unique_ptr<Dog> up_dog_9 = up_dog_8;
    // std::unique_ptr<Dog> up_dog_10{up_dog_8};


    // ---------------------------------------------------------------------------
    // std::unique_ptr<Dog> up_dog_11 = std::make_unique<Dog>("Dog11");
    // Can however move the pointer 
    /* {
        std::unique_ptr<Dog> up_dog_12 = std::move(up_dog_11);
        up_dog_12->print_dog();

        std::cout << "Dog 12 memory address: " << up_dog_12.get() << std::endl;
        std::cout << "up_dog_11 is now nullptr: " << up_dog_11.get() << std::endl;
    } */

    // ---------------------------------------------------------------------------
    std::unique_ptr<Dog> up_dog_13 = std::make_unique<Dog>("Dog11");

    up_dog_13.reset(); //release memory and sets pointer to nullptr
    std::cout << "up_dog_11 is now nullptr: " << up_dog_13.get() << std::endl;

    std::cout << "Hitting outside scope" << std::endl;


}