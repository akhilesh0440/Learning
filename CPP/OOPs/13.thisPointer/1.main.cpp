#include <iostream>
#include <string_view>

class Dog{
    public:
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        ~Dog();
        //Setters
        Dog& set_dog_name(std::string_view);
        Dog& set_dog_breed(std::string_view breed){
            this->breed = breed;
            return *this;
        }
        Dog& set_dog_age(int age){
            (*this->p_age) = age;
            return *this;
        }
        void print_info();
        
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
    std::cout << "Constructor called for " << name << "at " << this << std::endl;
}

Dog::~Dog(){
    delete p_age;
    std::cout << "Destructor called for " << name << " at " << this << std::endl;
}

// void some_funt(){
//     Dog* p_dog = new Dog("Saanvi", "Golder Retriever", 2);
//     delete p_dog;
// }

Dog& Dog::set_dog_name(std::string_view name){
    // name = name;
    this->name = name;
    return *this;
}
        
void Dog::print_info(){
    std::cout << "Dog (" << this << ") : [ name: " << name << ", breed : " << breed << ", age : " << *p_age << "]" << std::endl;
}


int main(){
    Dog dog1("Doggy1", "Sheperd", 1); //constructor
    dog1.print_info();
    /* dog1.set_dog_name("Saanvi");
    dog1.set_dog_breed("Golden retriver");
    dog1.set_dog_age(4); */

    dog1.set_dog_name("Saanvi").set_dog_breed("Golder retriever").set_dog_age(5);
    dog1.print_info();

    std::cout << "Done!" << std::endl;
}
