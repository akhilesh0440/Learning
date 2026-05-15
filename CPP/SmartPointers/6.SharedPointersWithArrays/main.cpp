#include <iostream>
#include <memory>
#include "dog.h"



int main(){

	//C++17 only : Recommended
	std::shared_ptr<int[]> shared_ptr_int_arr_1 (new int[10]{1, 2, 3, 4, 5, 6, 7, 8});
	std::shared_ptr<Dog[]> shared_ptr_dog_arr_1 (new Dog[10]{Dog("Dog1"), Dog("Dog2")});

	std::cout << std::endl;
	std::cout << "Reading data from arrays" << std::endl;
	std::cout << "Reading shared_prt_int_arr_1: " << std::endl;

	// setting elements 
	shared_ptr_int_arr_1[3] = 33;
	shared_ptr_dog_arr_1[3] = Dog("Sanvi");
	for(size_t i{0}; i < 10; i++){
		std::cout << "shared_ptr_int_arr_1[" << i << "] : " << shared_ptr_int_arr_1[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Reading shared_ptr_dog_arr_1: " << std::endl;
	for(size_t i{0}; i<10; i++){
		std::cout << "shared_ptr_dog-arr_1[" << i << "]: " << shared_ptr_dog_arr_1[i].get_name() << std::endl;
	}

}
