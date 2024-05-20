#pragma once
#include"AttackStrategy.hpp"
#include<iostream>

class BasicAttackStrategy : public AttackStrategy
{
public:
    void attack(Map<std::string, Character*>& players, Character* current_player, Character* to_attack_player) override
    {
        for(int i = 0; i < current_player->speed; i++)
        {
            to_attack_player->health -= current_player->damage;
            Character::change_font_colour(4);
            std::cout << to_attack_player->get_type() << " " << to_attack_player->get_name() 
                << " - " << current_player->damage << std::endl << std::endl;
            Character::change_font_colour(7);
        }
    }
};