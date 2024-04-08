#include<iostream>
#include<List>
#include"Character.hpp"
#include"Archer.hpp"
#include"Warrior.hpp"
#include"Wizard.hpp"
#include"Golem.hpp"

class Battlefield
{
public:
    Battlefield();
    void set_characters();
    void set_players_amount();
private:
    int players_amount = 0;
    const int min_players_amount = 2;
    const int max_players_amount = 6;
    const std::list<Character> characters = {Archer(), Golem(), Warrior(), Wizard()};
    std::list<Character> players;
    void print_characters();
    int get_choice(int start_limit, int end_limit);
};