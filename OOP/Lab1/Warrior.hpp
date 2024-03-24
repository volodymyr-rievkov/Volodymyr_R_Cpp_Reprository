#pragma once
#include"Character.hpp"

class Warrior : public Character
{
private:
    const int i_damage = 5;
    bool feature_active = false;
    void print_info() override;
    void use_feature() override;
public:
    Warrior();
};
