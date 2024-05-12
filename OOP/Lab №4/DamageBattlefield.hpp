#pragma once
#include"Battelfield.hpp"

class DamageBattlefield : public Battlefield
{
public:
    DamageBattlefield() {};
    virtual ~DamageBattlefield() {};
    void start() override;
private:
    void random_damage();
    void print_title() override;
};