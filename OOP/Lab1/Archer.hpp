#pragma once
#include"Character.hpp"

class Archer : public Character
{
private:
    const int i_speed = 1;
    bool feature_active = false;
    void increase_speed();
    void print_info() override;
public:
    Archer();
};