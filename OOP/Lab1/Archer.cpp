#include"Archer.hpp"
#include<iostream>

Archer::Archer()
{
    set_type("Archer🏹");
    set_health(60);
    set_damage(6);
    set_speed(3);
    set_replicas({"I never miss my mark.",
                "Precision is the key to victory.",
                "My arrows shall find their target."});
}

void Archer::increase_speed()
{
    if(!feature_active)
    {
        speed += i_speed;
        std::cout << "Speed + " << i_speed << std::endl;
        feature_active = true;
    }  
}

void Archer::print_info()
{
    Character::print_info();
    std::cout << " - Feature: " << "Speed increase" << ", when health is below 50%" << std::endl;
}
