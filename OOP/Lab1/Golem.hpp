#pragma once
#include"Character.hpp"

class Golem : public Character
{
public:
    Golem();
    void scream() override;
    void print_info() override;
};
