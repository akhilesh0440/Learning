#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"

class Player : public Person{
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    public:
        Player() = default;
        ~Player();

        // See the access we have to inherited members from Person 
        void play();
    private:
        int m_career_start_year{0};
        double m_salary{0.0};
        int health_factor{0}; 
};

#endif