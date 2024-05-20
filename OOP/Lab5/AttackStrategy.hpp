#pragma once
#include"Character.hpp"
#include"Map.hpp"

class AttackStrategy
{
public:
    virtual void attack(Map<std::string, Character*>& players, Character* current_player, Character* to_attack_player) = 0;
};