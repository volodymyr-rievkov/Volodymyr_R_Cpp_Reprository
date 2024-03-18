#pragma once
#include"Character.hpp"

class Golem : public Character
{
private:
    const std::string feature = "None";
public:
    Golem();
    void scream() override;
    void print_info() override;
};
