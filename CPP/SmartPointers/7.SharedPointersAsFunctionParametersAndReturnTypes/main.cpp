#include <iostream>
#include <memory>
#include "dog.h"


// passing by value 
void use_dog_v1(std::shared_ptr<Dog> dog){
	std::cout << "shared_ptr passed by value, dog_name: " << dog->get_name() << std::endl;
	std::cout << "use count in use_dog_v1: " << dog.use_count() << std::endl; 
}

// passing by non const reference 
void use_dog_v2(std::shared_ptr<Dog>& dog){
	dog->set_dog_name("Riol");
	std::cout << "shared_ptr passed by non const reference (dog name changed in function), dog_name: " << dog->get_name() << std::endl;
	std::cout << "use count in use_dog_v2: " << dog.use_count() << std::endl;
}

// passing by  const reference 
void use_dog_v3(const std::shared_ptr<Dog>& dog){
	dog->set_dog_name("simy");

	// dog.reset(); // not able to modify const referenct shared ptr from the argument
	std::cout << "shared_ptr passed by const reference (dog name changed in function), dog_name: " << dog->get_name() << std::endl;
	std::cout << "use count in use_dog_v3: " << dog.use_count() << std::endl;
}

// Returning by value 
std::shared_ptr<Dog> get_shared_ptr_v1(){
	std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v1");
	std::cout << "Managed dog address(in): " << dog_ptr.get() << std::endl;
	return dog_ptr;
}

int main(){
	/* std::cout << std::endl;
	std::cout << "Passing shared_ptr by value: " << std::endl;

	std::shared_ptr<Dog> shared_ptr_dog1 = std::make_shared<Dog>("Filld");
	std::cout << "shared_ptr_dog_1 use count(before): " << shared_ptr_dog1.use_count() << std::endl;
	use_dog_v1(shared_ptr_dog1);
	std::cout << "shared_ptr_dog_1 use count (after): " << shared_ptr_dog1.use_count() << std::endl; */
	
	/* std::cout << std::endl;
	std::cout << "Passing shared_ptr non reference: " << std::endl;

	std::shared_ptr<Dog> shared_ptr_dog2 = std::make_shared<Dog>("Filld");
	std::cout << "shared_ptr_dog_1 use count(before): " << shared_ptr_dog2.use_count() << std::endl;
	use_dog_v2(shared_ptr_dog2);
	std::cout << "shared_ptr_dog_1 use count (after): " << shared_ptr_dog2.use_count() << std::endl; */

	/* std::cout << std::endl;
	std::cout << "Passing shared_ptr const reference: " << std::endl;

	std::shared_ptr<Dog> shared_ptr_dog3 = std::make_shared<Dog>("Dog3");
	std::cout << "shared_ptr_dog_3 use count(before): " << shared_ptr_dog3.use_count() << std::endl;
	use_dog_v3(shared_ptr_dog3);
	std::cout << "shared_ptr_dog_3 use count (after): " << shared_ptr_dog3.use_count() << std::endl; */

	
	// Returning by value 
	std::cout << std::endl;

	std::shared_ptr<Dog> shared_ptr_dog4 = get_shared_ptr_v1();
	std::cout << "Managed dog address (out): " << shared_ptr_dog4.get() << std::endl;
	std::cout << "shared_ptr_dog_4 used cout: " << shared_ptr_dog4.use_count() << std::endl;
}