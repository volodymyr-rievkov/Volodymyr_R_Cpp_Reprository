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
private:
    void print_title();
    void print_start();
    void print_characters();
    void set_players();
    void finish();
    void turn_on_song();
    void turn_off_song();
    Battlefield* battlefield = nullptr;
    const std::vector<std::string> characters = {"Archer", "Golem", "Warrior", "Wizard"};
    const char* mp3_file_path = "D:\\Programming\\C,C++Applications\\OOP\\Lab5\\music\\The Gravewalker.mp3";
};