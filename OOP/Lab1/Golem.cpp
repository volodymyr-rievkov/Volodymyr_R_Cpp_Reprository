#include"Golem.hpp"
#include<iostream>

Golem::Golem()
{
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
    std::cout << "Golem " << get_name() << " screamed: ";
    Character::scream();
}

void Golem::print_info()
{
    std::cout << "Golem🪨" << std::endl;
    Character::print_info();
    std::cout << " - Feature: None" << std::endl; 
}
