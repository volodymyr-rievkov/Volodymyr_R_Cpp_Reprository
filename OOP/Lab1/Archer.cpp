#include"Archer.hpp"
#include<iostream>

Archer::Archer()
{
    set_type("Archer🏹");
    set_name();
    set_health(60);
    set_damage(6);
    set_speed(3);
    set_replicas({"I never miss my mark.",
                "Precision is the key to victory.",
                "My arrows shall find their target."});
}

void Archer::scream()
{
    std::cout << get_type() << " " << get_name() << " screamed: ";
    Character::scream();
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
    std::cout << get_type() << " " << get_name() << std::endl;
    Character::print_info();
    std::cout << " - Feature: " << feature << ", when health is below 50%" << std::endl;
}
