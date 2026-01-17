#include <iostream>
#include "player.h"

int main(){
    Player p1("BasketBall", "John", "Snow");
    // p1.set_first_name ("Arya");
    // p1.set_last_name("Stark");
    std::cout << "player : " << p1 << std::endl;

    return 0;
};