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
    Dog dog1("Doggy1", "Sheperd", 1);
    Dog dog2("Doggy2", "Sheperd", 2);
    Dog dog3("Doggy3", "Sheperd", 3);
    Dog dog4("Doggy4", "Sheperd", 4);
    std::cout << "Done!" << std::endl;
}
