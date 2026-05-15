#include <iostream>
#include <array>

template<typename T, size_t Size>
void print_vec(const std::array<T, Size>& arr){
    for(size_t i{}; i<arr.size(); ++i){
        std::cout << arr[i]  << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print_raw_array(const T* p, std::size_t size){
    std::cout << "data = ";
    for(std::size_t i=0; i<size; ++i){
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}

int main(){
    std::array<int, 3> int_arr1;
    std::array<int, 3> int_arr2{1, 2};
    std::array<int, 3> int_arr3{};
    std::array int_arr4{1, 2};

    std::cout << "int_arr1: ";
    print_vec(int_arr1);

    std::cout << "int_arr2: ";
    print_vec(int_arr2);

    std::cout << "int_arr3: ";
    print_vec(int_arr3);

    std::cout << "int_arr4: ";
    print_vec(int_arr4);
    return 0;
}