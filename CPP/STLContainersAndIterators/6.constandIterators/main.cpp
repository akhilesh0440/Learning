#include <iostream>
#include <vector>

template<typename T>
void print_collection(T& a){
    auto it = a.cbegin();
    auto it_end = a.cend();
    
    std::cout << "[";
    while(it != it_end){
        std::cout << *it << ", ";
        it++;
    }
    std::cout << "]";
}

int main(){
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>::iterator it = numbers.begin();
    
    print_collection(numbers);
    std::cout << std::endl << "------------------------------" << std::endl;

    std::cout << "[";
    while(it != numbers.end()){
        *it = 100;
        std::cout << *it << ", ";
        it++;
    }
    std::cout << "]" << std::endl;




}