#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <string_view>

class Person{
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
    public: 
        Person();
        Person(const std::string_view full_name, int age,
            std::string_view adress);
        // ~Person();
        Person(const Person& source);

        // Getters 
        std::string_view get_full_name() const{
            return m_full_name;
        }

        int get_age() const{
            return m_age;
        }

        std::string_view get_address() const{
            return m_address;
        }

    public:
        std::string m_full_name{"None"};
    protected:
        int m_age{0};
    private:
        std::string m_address{"None"};
};

#endif // PERSON_H