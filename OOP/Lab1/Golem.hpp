#pragma once
#include"Character.hpp"

class Golem : public Character
{
private:
    void print_info() override;
    void use_feature() override;
public:
    Golem();
};
