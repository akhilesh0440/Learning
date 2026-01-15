#include <iostream>
#include <string_view>

class Dog{
    public:
        std::string m_name;
};

struct cat{
    std::string m_name;
};


int main(){
    Dog dog1;
    cat cat1;

    dog1.m_name = "Flufy1";
    cat1.m_name = "Fluffy";


    std::cout << dog1.m_name << std::endl;
    std::cout << cat1.m_name << std::endl;
    std::cout << "Done!" << std::endl;
}
