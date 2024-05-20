#pragma once
#include"Battelfield.hpp"
#include"BattlefieldCreator.hpp"
#include"DamageBattlefield.hpp"
#include"HealthBattlefield.hpp"

class ConcreateBdCreator : public BattlefieldCreator
{
public:
    ConcreateBdCreator() {};
    ~ConcreateBdCreator() {};

    Battlefield* create_damage_battlefield() { return new DamageBattlefield; }
    Battlefield* create_health_battlefield() { return new HealthBattlefield; }
};