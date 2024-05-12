#include<iostream>
#include"Battelfield.hpp"
using namespace std;

void Battlefield::print_players()
{
    cout << "Players: " << endl;
    for (auto player = players.begin(); player != players.end(); ++player)
    {
        if(*player == current_player)
        {
            cout << "*";
        }
        else
        {
            cout << " ";
        }
        cout << (*player)->get_type() << " " << (*player)->get_name() << "(" << (*player)->health << "/" << (*player)->max_health << ")" << endl;
    }
    cout << endl;
}

void Battlefield::set_random_current_player()
{
    srand(time(0));
    int index = rand() % players_amount;
    int count = 0;
    for(auto player = players.begin(); player != players.end(); ++player)
    {
        if(index == count)
        {
            current_player = *player;
            break;
        }
        count++;
    }
}

void Battlefield::attack()
{
    cout << "Choose player to attack" << endl;
    print_players();
    string name;
    Character* to_attack_player = nullptr;
    
    do
    {
        cout << "Enter name: ";
        cin >> name;
        to_attack_player = players.search(name);
        
        if(to_attack_player == nullptr)
        {
            Character::change_font_colour(4);
            cout << "Error: There is no player with the name '" << name << "'." << endl << endl;
            Character::change_font_colour(7);
        }
        else if(to_attack_player == current_player)
        {
            Character::change_font_colour(4);
            cout << "Error: You can't harm yourself." << endl << endl;
            Character::change_font_colour(7);
            to_attack_player = nullptr;
        }
    } while (to_attack_player == nullptr);
    current_player->scream();
    for(int i = 0; i < current_player->speed; i++)
    {
        to_attack_player->health -= current_player->damage;
        Character::change_font_colour(4);
        cout << to_attack_player->get_type() << " " << to_attack_player->get_name() 
             << " - " << current_player->damage << endl << endl;
        Character::change_font_colour(7);
    }
    
    if(to_attack_player->health <= 0)
    {
        to_attack_player->print_death();
        players.remove(name);
        players_amount--;
    }
}

void Battlefield::change_current_player()
{
    for(auto player = players.begin(); player != players.end(); ++player)
        {
            if(current_player == *player)
            {
                ++player;
                if(player != players.end())
                {
                    current_player = *player;
                }
                else
                {
                    current_player = *players.begin();
                }
                break;
            }
        }
}

std::pair<int, int> Battlefield::get_players_amount_limits()
{
    return {min_players_amount, max_players_amount};
}

int* Battlefield::get_players_amount()
{
    return &players_amount;
}

Character* Battlefield::get_current_player()
{
    return current_player;
}
