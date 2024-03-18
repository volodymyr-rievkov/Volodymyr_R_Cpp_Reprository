#include"Golem.hpp"
#include<iostream>

Golem::Golem()
{
    set_type("Golem🪨");
    set_name();
    set_health(100);
    set_damage(20);
    set_speed(1);
    set_replicas({"I am unstoppable.",
                "My strength knows no bounds.",
                "Crush, smash, destroy!"});
}

void Golem::scream()
{
    std::cout << get_type() << " " << get_name() << " screamed: ";
    Character::scream();
}

void Golem::print_info()
{
    std::cout << get_type() << " " << get_name() << std::endl;
    Character::print_info();
    std::cout << " - Feature: " << feature << std::endl; 
}
