#include"Character.hpp"
#include<iostream>

void Character::set_health()
{
    do
    {
        std::cout << "Enter health(0-" << max_health << "): "; 
        std::cin >> health;
        if(health < 1 || health > max_health)
        {
            std::cout << errors[0] << std::endl;
        }
    }while (health < 1 || health > max_health);
}

void Character::set_damage()
{
    do
    {
        std::cout << "Enter damage(0-" << max_damage << "): ";
        std::cin >> damage;
        if(damage < 1 || damage > max_damage)
        {
            std::cout << errors[1] << std::endl;
        }
    } while (damage < 1 || damage > max_damage);
    
    
}

void Character::set_speed()
{
    do
    {
        std::cout << "Enter speed(0-" << max_speed << "): ";
        std::cin >> speed;
        if(speed < 1 || speed > max_speed)
        {
            std::cout << errors[2] << std::endl;
        }
    } while (speed < 1 || speed > max_speed); 
}

void Character::set_name()
{
    std::cout << "Enter name: ";
    std::cin >> name;
}

void Character::set_super_power()
{
    srand(time(0));
    super_power = super_powers[rand() % (sp_size - 1)];
    std::cout << "Your super power is: " << super_power << std::endl;
}

void Character::set_health(int health)
{
    if(health < 0 || health > max_health)
    {
        std::cout << errors[0] << std::endl;
        this->health = 0;
    }
    else
    {
        this->health = health;
    }
}

void Character::set_damage(int damage)
{
    if(damage < 0 || damage > max_damage)
    {
        std::cout << errors[1] << std::endl;
        this->damage = 0;
    }
    else
    {
        this->damage = damage;
    }
}

void Character::set_speed(int speed)
{
    if(speed < 0 || speed > max_speed)
    {
        std::cout << errors[2] << std::endl;
        this->speed = 0;
    }
    else
    {
        this->speed = speed;
    }
}

void Character::set_name(std::string name)
{
    this->name = name;
}

void Character::set_super_power(int index)
{
    if(index < 0 || index > sp_size)
    {
        std::cout << errors[3] << std::endl;
    }
    else
    {
        super_power = super_powers[index];
    }
}

int Character::get_health()
{
    return health;
}

int Character::get_damage()
{
    return damage;
}

int Character::get_speed()
{
    return speed;
}

std::string Character::get_name()
{
    return name;
}

std::string Character::get_super_power()
{
    return super_power;
}

void Character::print_info()
{
    std::cout << " - Type: " << type << std::endl;
    std::cout << " - Name: " << name << std::endl;
    std::cout << " - Health: "<< health << std::endl;
    std::cout << " - Damage: " << damage << std::endl;
    std::cout << " - Speed: " << speed << std::endl;
    std::cout << " - Super power: " << super_power << std::endl;
    std::cout << std::endl;
}