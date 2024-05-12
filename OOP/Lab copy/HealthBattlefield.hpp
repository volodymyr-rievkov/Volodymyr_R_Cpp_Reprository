#pragma once
#include"Battelfield.hpp"

class HealthBattlefield : public Battlefield
{
public:
    HealthBattlefield() {};
    virtual ~HealthBattlefield() {};
    void start() override;
    void print_title() override;
private:
    void random_health();
};