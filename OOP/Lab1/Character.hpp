#pragma once
#include<iostream>
#include<vector>
class Character
{
private:
    int health = 0;
    int damage = 0;
    int speed = 0;
    std::string super_power = "";
    std::vector<std::string> errors = {"Health value is out of range", "Damage value is out of range", 
                            "Speed value is out of range", "Index value is out of range"};
    int er_size = errors.size();
    std::vector<std::string> super_powers = {"Super strength", "Flight", "Teleportation", "Invisibility", "Telekinesis",
                                        "Shape-shifting", "Time manipulation", "Regeneration", "Elemental control",
                                        "Mind reading", "Force fields", "Heat vision", "X-ray vision", "Elasticity",
                                        "Immortality", "Pyrokinesis", "Cryokinesis", "Telepathy", "Healing", "Animal communication"};
    int sp_size = super_powers.size();

protected:
    int max_health = 0;
    int max_damage = 0;
    int max_speed = 0;
    std::string name = "";
    std::string type = "";

public:
    void set_health();
    void set_damage();
    void set_speed();
    void set_name();
    void set_super_power();
    void set_health(int health);
    void set_damage(int damage);
    void set_speed(int speed);
    void set_name(std::string name);
    void set_super_power(int index);
    int get_health();
    int get_damage();
    int get_speed();
    std::string get_name();
    std::string get_super_power();
    void print_info();
};