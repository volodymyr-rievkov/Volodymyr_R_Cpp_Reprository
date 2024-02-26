#include"Archer.hpp"
#include<iostream>

Archer::Archer()
{
    //Setting max values
    max_health = 20;
    max_damage = 30;
    max_speed = 50;
    type = "Archer";
}

void Archer::scream()
{
    srand(time(0));
    std::cout << type << " " << name << " screamed: " << replicas[rand() % 2] << std::endl;
}
