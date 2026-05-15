#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
class CivilEngineer : public Engineer{
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& player);
    public:
        CivilEngineer();
        CivilEngineer(const std::string_view full_name, int age,
            std::string_view adress, int contract_count, std::string_view speciality);
        CivilEngineer(const CivilEngineer& source);

        ~CivilEngineer();

        void build_road();
        
    private:
        std::string m_speciality{"None"} ;
};

#endif