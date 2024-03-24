#pragma once
#include"Character.hpp"

class Archer : public Character
{
private:
    const int i_speed = 1;
    bool feature_active = false;
    void print_info() override;
    void use_feature() override;
public:
    Archer();
};