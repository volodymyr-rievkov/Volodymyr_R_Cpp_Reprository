#include<iostream>
#include"Battelfield.hpp"
using namespace std;

Battlefield::Battlefield()
{
    start();
    set_players_amount();
    set_characters();
    print_start();
    set_random_current_player();
    while(players.size() > 1)
    {
        current_player->print_info();
        cout << endl;
        active_feature();
        attack();
        change_current_player();
    }
    finish();
}

void Battlefield::start()
{
    std::cout << R"(
 ▄▄▄       ██▀███   ▄████▄   ▄▄▄       ███▄    █ ▓█████     ▄▄▄       ██▀███  ▓█████  ███▄    █  ▄▄▄      
▒████▄    ▓██ ▒ ██▒▒██▀ ▀█  ▒████▄     ██ ▀█   █ ▓█   ▀    ▒████▄    ▓██ ▒ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    
▒██  ▀█▄  ▓██ ░▄█ ▒▒▓█    ▄ ▒██  ▀█▄  ▓██  ▀█ ██▒▒███      ▒██  ▀█▄  ▓██ ░▄█ ▒▒███   ▓██  ▀█ ██▒▒██  ▀█▄  
░██▄▄▄▄██ ▒██▀▀█▄  ▒▓▓▄ ▄██▒░██▄▄▄▄██ ▓██▒  ▐▌██▒▒▓█  ▄    ░██▄▄▄▄██ ▒██▀▀█▄  ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██ 
 ██   ▓██▒░██▓ ▒██▒▒ ▓███▀ ░ ██   ▓██▒▒██░   ▓██░░▒████▒    ██   ▓██▒░██▓ ▒██▒░▒████▒▒██░   ▓██░ ██   ▓██▒
 ▒█   ▓▒█░░ ▒▓ ░▒▓░░ ░▒ ▒  ░ ▒█   ▓▒█░░ ▒░   ▒ ▒ ░░ ▒░ ░    ▒█   ▓▒█░░ ▒▓ ░▒▓░░░ ▒░ ░░ ▒░   ▒ ▒  ▒█   ▓▒█░
 ▒   ▒▒ ░  ░▒ ░ ▒░  ░  ▒     ▒   ▒▒ ░░ ░░   ░ ▒░ ░ ░  ░     ▒   ▒▒ ░  ░▒ ░ ▒░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░
 ░   ▒     ░░   ░ ░          ░   ▒      ░   ░ ░    ░        ░   ▒     ░░   ░    ░      ░   ░ ░   ░   ▒   
     ░  ░   ░     ░ ░            ░  ░         ░    ░  ░         ░  ░   ░        ░  ░         ░       ░  ░
    )" << std::endl;
    std::cout << "PRESS ENTER TO START";
    std::cin.get();
    std::cout << std::endl;
}

void Battlefield::print_start()
{
    std::cout << R"(
  ▄████  ▄▄▄       ███▄ ▄███▓▓█████      ██████ ▄▄▄█████▓ ▄▄▄       ██▀███  ▄▄▄█████▒▓█████ ▓█████▄ 
 ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██    ▒ ▓  ██▒ ▓▒▒████▄    ▓██ ▒ ██▒▓  ██▒ ▓▒▓█   ▀ ▒██▀ ██▌
▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ░ ▓██▄   ▒ ▓██░ ▒░▒██  ▀█▄  ▓██ ░▄█ ▒▒ ▓██░ ▒░▒███   ░██   █▌
░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄      ▒   ██▒░ ▓██▓ ░ ░██▄▄▄▄██ ▒██▀▀█▄  ░ ▓██▓ ░ ▒▓█  ▄ ░▓█▄   ▌
░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ▒██████▒▒  ▒██▒ ░  ▓█   ▓██▒░██▓ ▒██▒  ▒██▒ ░ ░▒████▒░▒█████
 ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ▒ ▒▓▒ ▒ ░  ▒ ░░    ▒▒   ▓▒█░░ ▒▓ ░▒▓░  ▒ ░░   ░░ ▒░ ░ ▒▒▓  ▒ 
  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░   ░ ░▒  ░ ░    ░      ▒   ▒▒ ░  ░▒ ░ ▒░    ░     ░ ░  ░ ░ ▒  ▒ 
░ ░   ░   ░   ▒   ░      ░      ░      ░  ░  ░    ░        ░   ▒     ░░   ░   ░         ░    ░ ░  ░ 
      ░       ░  ░       ░      ░  ░         ░                 ░  ░   ░                 ░  ░   ░    
                                                                                             ░      
    )" << std::endl;
}

void Battlefield::set_players_amount()
{
    do
    {
        cout << "Enter amount of players(" << min_players_amount << "-" << max_players_amount << "): ";
        cin >> players_amount;
        if(players_amount < 2 || players_amount > 6)
        {
            cout << "Error: Amount of players is out of range." << endl;
        }
    } while (players_amount < 2 || players_amount > 6);
}

void Battlefield::print_characters()
{
    int count = 0;
    for(auto character : characters)
    {
        cout << ++count << " - " << character->get_type() << endl;
    }
}

int Battlefield::get_choice(int start_limit, int end_limit)
{
    int action = 0;
    do
    {
        cout << "Enter number: ";
        cin >> action;
        if(action < start_limit || action > end_limit)
        {
            cout << "Error: Number is out of range." << endl;
        }
    } while (action < start_limit || action > end_limit);
    return action;
}

void Battlefield::set_characters()
{
    for(int i = 0; i < players_amount; i++)
    {
        cout << "Choose character:" << endl;
        print_characters();
        int index = get_choice(1, characters.size()) - 1;
        switch (index)
        {
        case 0: players.push_back(new Archer());
            break;
        case 1: players.push_back(new Golem());
            break;
        case 2: players.push_back(new Warrior());
            break;
        case 3: players.push_back(new Wizard());
            break;
        }
        players.back()->set_name();
        cout << endl;
        players.back()->print_info();
        cout << endl;
    }
}

void Battlefield::print_players()
{
    cout << "Players: " << endl;
    for(int i = 0; i < players.size(); i++)
    {
        cout << i + 1 << " - ";
        if(players[i] == current_player)
        {
            cout << "*";
        }
        else
        {
            cout << " ";
        }
        cout << players[i]->get_type() << " " << players[i]->get_name() << "(" << players[i]->health << "/" << players[i]->get_max_health() << ")" << endl;
    }
    cout << endl;
}

void Battlefield::set_random_current_player()
{
    srand(time(0));
    current_player = players[rand() % players.size()];
}

void Battlefield::active_feature()
{
    if(current_player->get_type() != characters[1]->get_type())
        {
            if(!current_player->feature_active)
            {
                if((current_player->get_type() == characters[0]->get_type() && current_player->health < current_player->get_max_health() / 2) || (current_player->get_type() == characters[2]->get_type() && current_player->health < current_player->get_max_health() / 2))
                {
                    current_player->use_feature();
                }
                if(current_player->get_type() == characters[3]->get_type() && !current_player->feature_active)
                {
                    cout << "Do you want to use feature?\n 1 - Yes\n 2 - No\n: ";
                    bool choice = get_choice(1, 2);
                    if(choice == 1)
                    {
                        current_player->use_feature();
                    }
                }
            }
        }
    
}

void Battlefield::attack()
{
    cout << "Choose player to attack" << endl;
    int index = 0;
    print_players();
    do
    {
        index = get_choice(1, players.size()) - 1;
        if(current_player == players[index])
        {
            cout << "Error: You can't harm yourself." << endl << endl;
        }
    }while (current_player == players[index]);
    for(int i = 0; i < current_player->speed; i++)
    {
        players[index]->health -= current_player->damage;
        cout << players[index]->get_type() << " " << players[index]->get_name() << " - " << current_player->damage << endl << endl;
    }
    if(players[index]->health <= 0)
    {
        players[index]->print_death();
        players.erase(players.begin() + index);
    }
}

void Battlefield::change_current_player()
{
    for(int i = 0; i < players.size(); i++)
        {
            if(current_player == players[i])
            {
                if(i != players.size() - 1)
                {
                    current_player = players[i + 1];
                }
                else
                {
                    current_player = players.front();
                }
                break;
            }
        }
}

void Battlefield::finish()
{
    cout << players.front()->get_type() << " " << players[0]->get_name() << " won!" << endl << endl;
    cout << R"(
  ▄████  ▄▄▄       ███▄ ▄███▓▓█████      █████▒██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████ ▓█████▄ 
 ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▓██   ▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▒██▀ ██▌
▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒████ ░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ░██   █▌
░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ░▓█▒  ░░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ░▓█▄   ▌
░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░▒█░   ░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░▒█████ 
 ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░    ▒ ░   ░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░ ▒▒▓  ▒ 
  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░    ░      ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░ ░ ▒  ▒ 
░ ░   ░   ░   ▒   ░      ░      ░       ░ ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░    ░ ░  ░ 
      ░       ░  ░       ░      ░  ░           ░           ░  ░        ░   ░  ░  ░   ░  ░   ░    
                                                                                          ░     
    )" << endl << endl;
}
