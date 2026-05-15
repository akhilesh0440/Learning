#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

class Engineer : private Person{
    friend std::ostream& operator<<(std::ostream& out, const Engineer& player);
    public:
        Engineer();
        ~Engineer();

        void build_something();
        int get_contract_count();
    protected:
        using Person:: get_address;
        using Person:: get_age;
        using Person:: get_full_name;

    private:
        int contract_count{102} ;
};

#endif