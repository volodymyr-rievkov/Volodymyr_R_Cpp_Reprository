#pragma once
#include"Battelfield.hpp"

class BattlefieldCreator
{
public:
    BattlefieldCreator() {};
    ~BattlefieldCreator() {};

    virtual Battlefield* create_damage_battlefield() = 0;
    virtual Battlefield* create_health_battlefield() = 0;
};