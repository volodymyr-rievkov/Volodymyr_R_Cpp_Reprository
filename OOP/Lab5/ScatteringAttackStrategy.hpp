#pragma once
#include "AttackStrategy.hpp"

class ScatteringAttackStartegy : public AttackStrategy
{
public:
    void attack(Map<std::string, Character*>& players, Character* current_player, Character* to_attack_player) override
    {
        for(int i = 0; i < current_player->speed; i++)
        {
            to_attack_player->health -= (current_player->damage * 0.7);
            Character::change_font_colour(4);
            std::cout << to_attack_player->get_type() << " " << to_attack_player->get_name() 
                << " - " << (current_player->damage * 0.7) << std::endl << std::endl;
            Character::change_font_colour(7);
        }
        for(auto player = players.begin(); player != players.end(); ++player)
        {
            if(*player == to_attack_player)
            {
                if(++player != players.end())
                {
                    to_attack_player = *player;
                }
                else
                {
                    to_attack_player = *players.begin();
                }
            }
        }
        for(int i = 0; i < current_player->speed; i++)
        {
            to_attack_player->health -= (current_player->damage * 0.3);
            Character::change_font_colour(4);
            std::cout << to_attack_player->get_type() << " " << to_attack_player->get_name() 
                << " - " << (current_player->damage * 0.3) << std::endl << std::endl;
            Character::change_font_colour(7);
        }
    }
};