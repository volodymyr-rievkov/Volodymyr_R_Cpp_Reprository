#pragma once
#include"Character.hpp"

class Warrior : public Character
{
private:
    const int i_damage = 5;
    const std::string feature = "Damage Increase";
    bool feature_active = false;
public:
    Warrior();
    void damage_increase();
    void scream() override;
    void print_info() override;
};
