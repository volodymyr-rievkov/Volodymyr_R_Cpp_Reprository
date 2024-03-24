#pragma once
#include<iostream>
#include<vector>

class Character
{
private:
    std::string name;
    std::string type;
protected:
    int health = 0;
    int damage = 0;
    int speed = 0;
    std::vector<std::string> replicas;
    void set_type(std::string type);
    void set_health(int health);
    void set_damage(int damage);
    void set_speed(int speed);
    void set_replicas(std::vector<std::string> replicas);
    void scream();
public:
    std::string get_type(); 
    std::string get_name();
    void set_name(); 
    virtual void print_info(); 
};