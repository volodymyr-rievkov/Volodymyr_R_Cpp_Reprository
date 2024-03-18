#pragma once
#include<iostream>
#include<vector>

class Character
{
private:
    std::string name;
    static std::string type;
protected:
    int health = 0;
    int damage = 0;
    int speed = 0;
    std::vector<std::string> replicas;
    void set_type(std::string type);
    static std::string get_type();
    std::string get_name();
    void set_name();
    void set_health(int health);
    void set_damage(int damage);
    void set_speed(int speed);
    void set_replicas(std::vector<std::string> replicas);
    virtual void scream();
    virtual void print_info();
};