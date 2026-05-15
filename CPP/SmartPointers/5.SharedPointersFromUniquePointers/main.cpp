#include <iostream>
#include <memory>
#include "dog.h"


std::unique_ptr<Dog> get_unique_ptr(){
	std::unique_ptr<Dog> dog_ptr_internal = std::make_unique<Dog>("Phil");
	return dog_ptr_internal;
}



int main(){
	/* std::unique_ptr<int> up_int_1 = std::make_unique<int>(22);
	std::unique_ptr<Dog> up_dog_1 = std::make_unique<Dog>("Halz");

	// convert unique ptr to shared_ptr 
	std::shared_ptr<int> sp_int_1 = std::move(up_int_1);
	std::shared_ptr<Dog> sp_dog_1 = std::move(up_dog_1);

	std::cout << "Shared_ptr_int_1 use count: " << sp_int_1.use_count() << std::endl;
	std::cout << "shared_ptr_dog_1 use coutn: " << sp_dog_1.use_count() << std::endl;
	std::cout << std::boolalpha;
	std::cout << "unique_ptr_int_1 use count: " << static_cast<bool> (up_int_1) << std::endl;
	std::cout << "unique_ptr_dog_1 use count: " << static_cast<bool> (up_dog_1) << std::endl;

	std::cout << "unique_ptr_int_1: " << up_int_1 << std::endl;
	std::cout << "unique_ptr_dog_1: " << up_dog_1 << std::endl; */
	
	std::cout << std::endl;
	std::cout << "Retruning unique_ptr from function to unique ptr" << std::endl;
	std::shared_ptr<Dog> shared_ptr_dog_2 = get_unique_ptr();


}