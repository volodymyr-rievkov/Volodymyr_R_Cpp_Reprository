#pragma once
#include"Character.hpp"

class Archer : public Character
{
private:
    const int i_speed = 1;
    const std::string feature = "Speed increase";
    bool feature_active = false;
public:
    Archer();
    void increase_speed();
    void scream() override;
    void print_info() override;
};