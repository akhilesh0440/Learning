#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
class CivilEngineer : private Engineer{
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& player);
    public:
        CivilEngineer();
        ~CivilEngineer();

        void build_road();
    private:
        std::string m_speciality{"None"} ;
};

#endif