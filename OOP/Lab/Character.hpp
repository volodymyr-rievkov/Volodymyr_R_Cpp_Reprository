#pragma once
#include<iostream>
#include<vector>

class Character
{
private:
    std::string name;
    std::string type;
    int max_health = 0;
protected:
    std::vector<std::string> replicas;
    void set_type(std::string type);
    void set_health(int health);
    void set_damage(int damage);
    void set_speed(int speed);
    void set_replicas(std::vector<std::string> replicas);
    void scream();
    void set_max_health(int health);
public:
    int health = 0;
    int damage = 0;
    int speed = 0;
    bool feature_active = false;
    std::string get_type(); 
    std::string get_name();
    int get_max_health();
    void set_name(); 
    virtual void print_info(); 
    virtual void use_feature() = 0;
    virtual void print_death() = 0;
};