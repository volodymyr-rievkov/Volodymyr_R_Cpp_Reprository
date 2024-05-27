#include<iostream>
#include"Battelfield.hpp"
#include"BasicAttackStrategy.hpp"
#include"ScatteringAttackStrategy.hpp"
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

void Battlefield::perform_attack()
{
    cout << "Choose player to attack" << endl;
    print_players();
    string name;
    do
    {
        cout << "Enter name: ";
        cin >> name;
        to_attack_player = players.search(name);
        
        if(to_attack_player == nullptr)
        {
            Character::change_font_colour(4);
            cerr << "Error: There is no player with the name '" << name << "'." << endl << endl;
            Character::change_font_colour(7);
        }
        else if(to_attack_player == current_player)
        {
            Character::change_font_colour(4);
            cerr << "Error: You can't harm yourself." << endl << endl;
            Character::change_font_colour(7);
            to_attack_player = nullptr;
        }
    } while (to_attack_player == nullptr);
    current_player->scream();
    set_attack_strategy();
    attack_strategy->attack(players, current_player, to_attack_player);
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

void Battlefield::set_attack_strategy()
{
    int choice = 0;
    do
    {
        cout << "Choose attack strategy" << endl << "1 - Basic Attack" << endl << "2 - Scattering Attack" << endl << "Enter number: ";
        cin >> choice;
        if(choice < 1 || choice > 2)
        {
            cerr << "Error: Number is out of range." << endl << endl;
        }
    } while (choice < 1 || choice > 2);
    if(choice == 1)
    {
        attack_strategy = new BasicAttackStrategy();
    }
    else
    {
        attack_strategy = new ScatteringAttackStartegy();
    }
}

void Battlefield::check_deaths()
{
    for(auto player = players.begin(); player != players.end(); ++player)
    {
        if((*player)->health <= 0)
        {
            if((*player) == current_player)
            {
                change_current_player();
            }
            players_to_remove.push_back(*player);            
        }
    }
    for(int i = 0; i < players_to_remove.size(); i++)
    {
        players_to_remove[i]->print_death();
        players.remove(players_to_remove[i]->get_name());
        players_amount--;
    }
    players_to_remove.clear();
}
