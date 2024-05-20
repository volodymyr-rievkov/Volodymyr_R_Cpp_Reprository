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
    change_font_colour(6);
    std::cout << " - Feature: " << "Damage Increase" << ", when health is below 50%" << std::endl;
    change_font_colour(7);
}

void Warrior::use_feature()
{
    if(!feature_active && health < max_health / 2)
    {
        damage += i_damage;
        change_font_colour(6);
        std::cout << get_type() << " " << get_name() << "'s " "feature has been used." << std::endl;
        std::cout << "Damage + " << i_damage << std::endl << std::endl;
        change_font_colour(7);
        feature_active = true;
    }
    
}

void Warrior::print_death()
{
    change_font_colour(4);
    std::cout << get_type() << " " << get_name() << ": ";
    type_text("I fought bravely... but it's not enough.");
    std::cout << std::endl;
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
    change_font_colour(7);
}
