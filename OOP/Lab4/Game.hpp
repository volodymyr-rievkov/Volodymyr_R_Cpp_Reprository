#pragma once
#include"Battelfield.hpp"

class Game
{
public:
    Game() {};
    ~Game();
    void start();
    void set_battlefield();
    Battlefield* get_battlefield();
    void set_players_amount();
    void set_players();
private:
    void print_title();
    void print_start();
    void print_characters();
    void finish();
    Battlefield* battlefield = nullptr;
    const std::vector<std::string> characters = {"Archer", "Golem", "Warrior", "Wizard"};

};