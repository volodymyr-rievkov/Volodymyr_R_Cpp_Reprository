#include"Warrior.hpp"
#include<iostream>

Warrior::Warrior()
{
    set_type("Warrior⚔️ ");
    set_health(80);
    set_max_health(health);
    set_damage(10);
    set_speed(2);
    set_replicas({"For honor and glory!",
                "No one can match my strength.",
                "I fear no enemy."});
}

void Warrior::print_info()
{
    Character::print_info();
    std::cout << " - Feature: " << "Damage Increase" << ", when health is below 50%" << std::endl;
}

void Warrior::use_feature()
{
    damage += i_damage;
    std::cout << get_type() << " " << get_name() << "' " "feature has been used." << std::endl;
    std::cout << "Damage + " << i_damage << std::endl << std::endl;
    feature_active = true;
}

void Warrior::print_death()
{
    std::cout << R"(
 █     █░ ▄▄▄       ██▀███   ██▓ ▒█████   ██▀███      ██▓  ██████    ▓█████▄ ▓█████ ▄▄▄      ▓█████▄ 
▓█░ █ ░█░▒████▄    ▓██ ▒ ██▒▓██▒▒██▒  ██▒▓██ ▒ ██▒   ▓██▒▒██    ▒    ▒██▀ ██▌▓█   ▀▒████▄    ▒██▀ ██▌
▒█░ █ ░█ ▒██  ▀█▄  ▓██ ░▄█ ▒▒██▒▒██░  ██▒▓██ ░▄█ ▒   ▒██▒░ ▓██▄      ░██   █▌▒███  ▒██  ▀█▄  ░██   █▌
░█░ █ ░█ ░██▄▄▄▄██ ▒██▀▀█▄  ░██░▒██   ██░▒██▀▀█▄     ░██░  ▒   ██▒   ░▓█▄   ▌▒▓█  ▄░██▄▄▄▄██ ░▓█▄   ▌
░░██▒██▓  ▓█   ▓██▒░██▓ ▒██▒░██░░ ████▓▒░░██▓ ▒██▒   ░██░▒██████▒▒   ░▒████▓ ░▒████▒▓█   ▓██▒░▒█████ 
░ ▓░▒ ▒   ▒▒   ▓▒█░░ ▒▓ ░▒▓░░▓  ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░   ░▓  ▒ ▒▓▒ ▒ ░    ▒▒▓  ▒ ░░ ▒░ ░▒▒   ▓▒█░ ▒▒▓  ▒ 
  ▒ ░ ░    ▒   ▒▒ ░  ░▒ ░ ▒░ ▒ ░  ░ ▒ ▒░   ░▒ ░ ▒░    ▒ ░░ ░▒  ░ ░    ░ ▒  ▒  ░ ░  ░ ▒   ▒▒ ░ ░ ▒  ▒ 
  ░   ░    ░   ▒     ░░   ░  ▒ ░░ ░ ░ ▒    ░░   ░     ▒ ░░  ░  ░      ░ ░  ░    ░    ░   ▒    ░ ░  ░ 
    ░          ░  ░   ░      ░      ░ ░     ░         ░        ░        ░       ░  ░     ░  ░   ░    
                                                                      ░                       ░      
    )" << std::endl << std::endl;
}
