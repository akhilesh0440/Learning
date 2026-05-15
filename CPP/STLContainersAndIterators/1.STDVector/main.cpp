#include <iostream>
#include <vector>

template<typename T>
void print_vec(const std::vector<T>& vec){
    for(size_t i{}; i<vec.size(); ++i){
        std::cout << vec[i]  << " ";
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
    std::vector<std::string> vec1{"The", "Sky", "is", "blue", "my", "freind"};
    // std::cout << "vec1[1] " << vec1[1] << std::endl;
    print_vec(vec1);

    std::cout << "----------------" << std::endl;
    std::vector<int> inst;
    std::cout << "int: ";
    print_vec(inst);

    std::vector<int> inst1{1, 2, 3, 4};
    std::cout << "int1: ";
    print_vec(inst1);

    std::vector<int> inst2{5, 6, 7, 8};
    std::cout << "int1: ";
    print_vec(inst2);

    std::vector<int> inst3(20, 55);
    std::cout << "int3: ";
    print_vec(inst3);

    // Accessing elements 
    std::cout << std::endl;
    std::cout << "Accessing elements in a vector: " << std::endl;
    std::cout << "vec_str[2]: " << vec1[2] << std::endl;
    std::cout << "vec_str.at(3): " << vec1.at(3) << std::endl;
    std::cout << "vec_str.front(): " << vec1.front() << std::endl;
    std::cout << "vec_str.back(): " << vec1.back() << std::endl;

    print_raw_array(vec1.data(), vec1.size());

    inst.push_back(100);
    inst.push_back(200);
    inst.push_back(300);
    inst.pop_back();
    print_vec(inst);
    return 0;
}