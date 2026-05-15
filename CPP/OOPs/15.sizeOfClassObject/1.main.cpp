#include <iostream>
#include <string_view>

class Dog{
    public:
        Dog() = default;

    private:
        size_t let_count;
        size_t arm_count;
        int *ptr;
};

struct cat{
    std::string m_name;
};


int main(){
    Dog dog1;
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl;
    std::cout << "sizeof(Dog) : " << sizeof(Dog) << std::endl;


    std::cout << "Done!" << std::endl;
}

