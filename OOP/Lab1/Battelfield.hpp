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
};