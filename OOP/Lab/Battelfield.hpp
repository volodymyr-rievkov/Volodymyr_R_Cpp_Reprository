#pragma once
#include<iostream>
#include"Character.hpp"
#include"Archer.hpp"
#include"Warrior.hpp"
#include"Wizard.hpp"
#include"Golem.hpp"

class Battlefield
{
public:
    Battlefield();
    void launch_game();
private:
    int players_amount = 0;
    const int min_players_amount = 2;
    const int max_players_amount = 6;
    Character* current_player = nullptr;
    const std::vector<Character*> characters = {new Archer(), new Golem(), new Warrior(), new Wizard()};
    std::vector<Character*> players;
    void print_characters();
    int get_choice(int start_limit, int end_limit);
    void start();
    void set_characters();
    void set_players_amount();
    void print_players();
    void set_random_current_player();
    void active_feature();
    void print_start();
    void attack();
    void change_current_player();
    void finish();
};