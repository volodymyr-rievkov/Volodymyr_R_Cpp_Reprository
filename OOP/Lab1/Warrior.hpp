#pragma once
#include"Character.hpp"

class Warrior : public Character
{
private:
    const int i_damage = 5;
    bool feature_active = false;
    void damage_increase();
    void print_info() override;
public:
    Warrior();
};
