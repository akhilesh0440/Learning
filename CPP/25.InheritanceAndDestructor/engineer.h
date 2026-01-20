#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

class Engineer : public Person{
    friend std::ostream& operator<<(std::ostream& out, const Engineer& player);
    public:
        Engineer();
        Engineer(const std::string_view full_name, int age,
            std::string_view adress, int contract_count);
        ~Engineer();
        Engineer(const Engineer& source);

        void build_something();
        int get_contract_count() const{
            return contract_count;
        };

    private:
        int contract_count{102} ;
};

#endif