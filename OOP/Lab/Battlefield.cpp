#include<iostream>
#include"Battelfield.hpp"
using namespace std;

Battlefield::Battlefield()
{
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

void Battlefield::set_players()
{
    for(int i = 0; i < players_amount; i++)
    {
        cout << "Choose character:" << endl;
        print_characters();
        int index = 0;
        do
        {
            cout << "Enter number: ";
            cin >> index;
            if(index < 1 || index > characters.size())
            {
                cout << "Error: Number is out of range." << endl;
            }
        } while (index < 1 || index > characters.size());
        index--;
        Character* character = nullptr;
        switch (index)
        {
        case 0: character = new Archer();
            break;
        case 1: character = new Golem();
            break;
        case 2: character = new Warrior();
            break;
        case 3: character = new Wizard();
            break;
        }
        string name;
        do
        {
            cout << "Enter name: ";
            cin >> name;
            if(players.search(name) != nullptr)
            {
                cout << "Error: Name is already used." << endl;
            }
        }while(players.search(name) != nullptr);
        cout << endl;
        character->set_name(name);
        players.add(name, character);
        character->print_info();
        cout << endl;
    }
}

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
        cout << (*player)->get_type() << " " << (*player)->get_name() << "(" << (*player)->health << "/" << (*player)->get_max_health() << ")" << endl;
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
        to_attack_player = *players.search(name);
        if(to_attack_player == nullptr )
        {
            cout << "Error: There is no player on name '" << name << "'." << endl;
        }
        if(to_attack_player == current_player)
        {
            cout << "Error: You can't harm yourself." << endl;
        }
    }while (to_attack_player == nullptr || to_attack_player == current_player);
    for(int i = 0; i < current_player->speed; i++)
    {
        to_attack_player->health -= current_player->damage;
        cout << to_attack_player->get_type() << " " << to_attack_player->get_name() << " - " << current_player->damage << endl << endl;
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

void Battlefield::finish()
{
    cout << current_player->get_type() << " " << current_player->get_name() << " won!" << endl << endl;
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

void Battlefield::launch_game()
{
    start();
    set_players_amount();
    set_players();
    print_start();
    set_random_current_player();
    while(players_amount > 1)
    {
        current_player->print_info();
        cout << endl;
        current_player->use_feature();
        attack();
        change_current_player();
    }
    finish();
}
