#include"Warrior.hpp"
#include<iostream>

Warrior::Warrior()
{
    set_type("Warrior⚔️ ");
    set_health(80);
    set_damage(10);
    set_speed(2);
    set_replicas({"For honor and glory!",
                "No one can match my strength.",
                "I fear no enemy."});
}

void Warrior::print_info()
{
    Character::print_info();
    std::cout << " - Feature: " << "Damage Increase" << ", when health is below 50%" << std::endl;
}

void Warrior::use_feature()
{
    if(!feature_active)
    {
        damage += i_damage;
        std::cout << "Damage + " << i_damage << std::endl;
        feature_active = true;
    }
    else
    {
        std::cout << "Error: Feature is already used." << std::endl;
    } 
}
