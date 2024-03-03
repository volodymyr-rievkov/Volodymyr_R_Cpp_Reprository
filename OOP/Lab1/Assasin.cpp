#include"Assasin.hpp"
#include<iostream>

Assasin::Assasin()
{
    //Setting max values
    max_health = 20;
    max_damage = 50;
    max_speed = 30;
    type = "Assasin";
}

void Assasin::scream()
{
    srand(time(0));
    std::cout << type << " " << name << " screamed: " << replicas[rand() % 2] << std::endl;
}
