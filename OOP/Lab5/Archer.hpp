#pragma once
#include"Character.hpp"

class Archer : public Character
{
private:
    const int i_speed = 1;
    void print_info() override;
    void use_feature() override;
    void print_death() override;
public:
    Archer();
};