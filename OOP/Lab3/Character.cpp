#include "Character.hpp"
#include<iostream>
using namespace std;

void Character::set_health(int health)
{
    this->health = health;
}

void Character::set_damage(int damage)
{
    this->damage = damage;
}

void Character::set_speed(int speed)
{
    this->speed = speed;
}

void Character::set_name(std::string name)
{
    this->name = name;
}

string Character::get_name()
{
    return name;
}

void Character::print_info()
{
    cout << get_type() << " " << get_name() << std::endl;
    cout << " - Health: " << health << "/" << max_health << endl;
    cout << " - Damage: " << damage << endl;
    cout << " - Speed: " << speed << endl;
}

void Character::set_replicas(vector<string> replicas)
{
    this->replicas = replicas;
    replicas.shrink_to_fit();
}

void Character::scream()
{
    srand(time(0));
    cout << get_type() << " " << get_name() << " screamed: ";
    cout << replicas[rand() % replicas.size()] << endl;
}

void Character::set_type(string type)
{
    this->type = type;
}

string Character::get_type()
{
    return type;
}

void Character::set_max_health(int health)
{
    max_health = health;
}
