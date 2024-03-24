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


    current_player->print_info();
    if(current_player->get_type() != characters[1]->get_type())
    {
        if(ask_feature())
        {
            current_player->use_feature();
        }
    }
    print_players();

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
    for(auto player : players)
    {
        if(player == current_player)
        {
            cout << "*";
        }
        else
        {
            cout << " ";
        }
        cout << player->get_type() << " " << player->get_name() << "(" << player->health << ")" << endl;
    }
    cout << endl;
}

void Battlefield::set_random_current_player()
{
    srand(time(0));
    current_player = players[rand() % players.size()];
}

bool Battlefield::ask_feature()
{
    cout << "Do you want to use feature?\n 1 - No\n 2 - Yes\n: ";
    bool choice = get_choice(1, 2) - 1;
    return choice;
}
