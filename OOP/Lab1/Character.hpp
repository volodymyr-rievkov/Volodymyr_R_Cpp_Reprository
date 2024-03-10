#pragma once
#include<iostream>
#include<vector>

class Character
{
private:
    std::string name;
protected:
    int health = 0;
    int damage = 0;
    int speed = 0;
    std::vector<std::string> replicas;
    std::string get_name();
    void set_name();
    void set_health(int health);
    void set_damage(int damage);
    void set_speed(int speed);
    void set_replicas(std::vector<std::string> replicas);
    virtual void print_info();
    virtual void scream();
};