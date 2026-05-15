#include <iostream>
#include <array>
#include <vector>

template<typename T>
void print_collection(const T& collection){
    auto it = collection.begin();
    std::cout << " [";
    while(it != collection.end()){
        std::cout << " " << *it;
        it++;
    }
    std::cout << "]" << std::endl;
}

int main(){
    std::vector<int> inst1{11, 22, 33, 44};
    std::array<int, 4> inst2{100, 200, 300, 400};

    std::vector<int>::iterator it_begin = inst1.begin();
    std::vector<int>::iterator it_end = inst1.end();
/* 
    std::cout << std::boolalpha;
    std::cout << "first elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "second elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;
    
    ++it_begin;
    std::cout << "third elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "fourth elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "junk elt: " << *it_begin << std::endl;
    std::cout << " it == end_it: " << (it_begin == it_end) << std::endl;
*/
    std::cout << "---------------------" << std::endl;
    std::cout << "inst1";
    print_collection(inst1);


}