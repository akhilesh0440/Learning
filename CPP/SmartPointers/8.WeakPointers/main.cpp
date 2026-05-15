#include <iostream>
#include <memory>
#include "dog.h"
#include "person.h"

int main(){

/* 	std::shared_ptr<Dog> sp_dog1 = std::make_shared<Dog>("Dog1");
    std::shared_ptr<int> sp_int1 = std::make_shared<int>(57);

    std::weak_ptr wp_dog1(sp_dog1);
    std::weak_ptr wp_int1(sp_int1);


    // std::cout << "Dog name" << wp_dog1->get_name() << std::endl;

    std::cout << std::endl;

    std::shared_ptr<Dog> w2sp_dog1 = wp_dog1.lock(); */

    // To solve cyclic dependancy problem 

    std::shared_ptr<Person> person_a = std::make_shared<Person>("Person A");
    std::shared_ptr<Person> person_b = std::make_shared<Person>("Person B");

    person_a->set_friend(person_b);
    person_b->set_friend(person_a);

	
    
    return 0;
}