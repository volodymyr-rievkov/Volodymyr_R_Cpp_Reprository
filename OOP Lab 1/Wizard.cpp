#include"Wizard.hpp"
#include<iostream>

Wizard::Wizard()
{
    //Setting max values
    max_health = 20;
    max_damage = 60;
    max_speed = 20;
    type = "Wizard";
}

void Wizard::scream()
{
    srand(time(0));
    std::cout << type << " " << name << " screamed: " << replicas[rand() % 2] << std::endl;
}
