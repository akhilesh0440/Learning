#include "person.h"
#include "player.h"
#include <iostream>

// Player::Player(){

// }
// Player::Player(std::string_view game_param, std::string_view first_name_param, std::string_view last_name_param)
//     : m_game(game_param){
//     first_name = first_name_param;
//     last_name = last_name_param;
// }

std::ostream& operator<<(std::ostream& out, const Player& player){
    out << "Player [Full name : " << player.get_full_name()
        << ", age : " << player.get_age()
            << ", address : " << player.get_address() << "]";
            return out;
}

void Player::play(){
    m_full_name = "John Snow"; //OK
    m_age = 55; //OK

}

Player::~Player(){

}

