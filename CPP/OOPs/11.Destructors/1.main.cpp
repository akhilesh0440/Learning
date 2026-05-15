#include <iostream>
#include <string_view>

class Dog{
    public:
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        ~Dog();
    private:
        std::string name;
        std::string breed;
        int *p_age {nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param){
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Constructor called for " << name << std::endl;
}

Dog::~Dog(){
    delete p_age;
    std::cout << "Destructor called for " << name << std::endl;
}

void some_funt(){
    Dog* p_dog = new Dog("Saanvi", "Golder Retriever", 2);
    delete p_dog;
}



int main(){
    some_funt();
    std::cout << "Done!" << std::endl;
}
