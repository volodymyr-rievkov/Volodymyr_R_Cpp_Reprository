#include"Golem.hpp"
#include<iostream>

Golem::Golem()
{
    set_type("Golem🪨 ");
    set_health(100);
    set_damage(20);
    set_speed(1);
    set_replicas({"I am unstoppable.",
                "My strength knows no bounds.",
                "Crush, smash, destroy!"});
}

void Golem::print_info()
{
    Character::print_info();
    std::cout << " - Feature: " << "None" << std::endl; 
}
