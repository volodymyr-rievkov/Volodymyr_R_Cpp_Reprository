#include"Warrior.hpp"
#include<iostream>

Warrior::Warrior()
{
    set_type("Warrior⚔️");
    set_name();
    set_health(80);
    set_damage(10);
    set_speed(2);
    set_replicas({"For honor and glory!",
                "No one can match my strength.",
                "I fear no enemy."});
}

void Warrior::damage_increase()
{
    if(!feature_active)
    {
        damage += i_damage;
        std::cout << "Damage + " << i_damage << std::endl;
        feature_active = true;
    }   
}

void Warrior::print_info()
{
    std::cout << get_type() << " " << get_name() << std::endl;
    Character::print_info();
    std::cout << " - Feature: " << feature << ", when health is below 50%" << std::endl;
}

void Warrior::scream()
{
    std::cout << get_type() << " " << get_name() << " screamed: ";
    Character::scream();
}
