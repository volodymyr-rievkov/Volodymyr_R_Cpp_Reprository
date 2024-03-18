#include<iostream>
#include<List>
#include"Character.hpp"
#include"Archer.hpp"
#include"Warrior.hpp"
#include"Wizard.hpp"
#include"Golem.hpp"

class Battlefield : public Archer, public Golem, public Warrior, public Wizard
{
public:
    Battlefield();
    void set_characters();
private:
    int players_amount = 0;
    const std::list<std::string> characters = {Archer::get_type(), Golem::get_type(), Warrior::get_type(), Wizard::get_type()};
    const std::list<Character> players;
    void set_players_amount();
};