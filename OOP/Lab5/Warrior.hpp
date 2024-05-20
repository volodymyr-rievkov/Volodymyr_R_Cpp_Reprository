#pragma once
#include"Character.hpp"

class Warrior : public Character
{
private:
    const int i_damage = 5;
    void print_info() override;
    void use_feature() override;
    void print_death() override;
public:
    Warrior();
};
