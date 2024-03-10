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

void Character::set_name()
{
    cout << "Enter name: ";
    cin >> name;
}

string Character::get_name()
{
    return name;
}

void Character::print_info()
{
    cout << " - Name: " << name << endl;
    cout << " - Health: " << health << endl;
    cout << " - Damage: " << damage << endl;
    cout << " - Speed: " << speed << endl;
}

void Character::set_replicas(vector<string> replicas)
{
    this->replicas = replicas;
}

void Character::scream()
{
    srand(time(0));
    cout << replicas[rand() % replicas.size()] << endl;
}

