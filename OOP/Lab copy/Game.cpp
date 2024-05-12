#include"Game.hpp"
#include"Map.hpp"
#include"Battelfield.hpp"
#include"BattlefieldCreator.hpp"
#include"ConcreateBdCreator.hpp"
#include<iostream>

void Game::start()
{
    print_title();
    set_battlefield();
    battlefield->print_title();
    set_players_amount();
    set_players();
    print_start();
    battlefield->start();
    finish();
}

void Game::print_start()
{
    Character::change_font_colour(6);
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
    Character::change_font_colour(7);
}

void Game::print_title()
{
    Character::change_font_colour(5);
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
    Character::change_font_colour(7);
    std::cout << "PRESS ENTER TO START";
    std::cin.get();
    std::cout << std::endl;
}

void Game::set_battlefield()
{
    int choice = 0;
    do
    {
        std::cout << "Choose battlefield:" << std::endl << "1 - Damage Battlefield" << std::endl << "2 - Health Battlefield" << std::endl << "Enter number: ";
        std::cin >> choice;
        if(choice < 1 || choice > 2)
        {
            Character::change_font_colour(4);
            std::cout << "Error: Number is out of range." << std::endl << std::endl;
            Character::change_font_colour(7);
        }
    } while (choice < 1 || choice > 2);
    BattlefieldCreator *bf_creator = new ConcreateBdCreator;
    if(choice == 1)
    {
        battlefield = bf_creator->create_damage_battlefield();
    }
    else
    {
        battlefield = bf_creator->create_health_battlefield();
    }
}

void Game::set_players_amount()
{
    std::pair<int, int> players_amount_limits = battlefield->get_players_amount_limits();
    int* players_amount = battlefield->get_players_amount();
    do
    {
        std::cout << "Enter amount of players(" << players_amount_limits.first << "-" << players_amount_limits.second << "): ";
        std::cin >> *players_amount;
        if(*players_amount < players_amount_limits.first || *players_amount > players_amount_limits.second)
        {
            Character::change_font_colour(4);
            std::cout << "Error: Amount of players is out of range." << std::endl << std::endl;
            Character::change_font_colour(7);
        }
    } while (*players_amount < players_amount_limits.first || *players_amount > players_amount_limits.second);
    players_amount = nullptr;
}

void Game::print_characters()
{
    for(int i = 0; i < characters.size(); i++)
    {
        std::cout << i + 1 << " - " << characters[i] << std::endl;
    }
}

void Game::set_players()
{
    int* players_amount = battlefield->get_players_amount();
    Character* character = nullptr;
    for(int i = 0; i < *players_amount; i++)
    {
        std::cout << "Choose character:" << std::endl;
        print_characters();
        int index = 0;
        do
        {
            std::cout << "Enter number: ";
            std::cin >> index;
            if(index < 1 || index > characters.size())
            {
                Character::change_font_colour(4);
                std::cout << "Error: Number is out of range." << std::endl << std::endl;
                Character::change_font_colour(7);
            }
        }while(index < 1 || index > characters.size());
        index--;
        switch(index)
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
        std::string name;
        do
        {
            std::cout << "Enter name: ";
            std::cin >> name;
            if(battlefield->players.search(name) != nullptr)
            {
                Character::change_font_colour(4);
                std::cout << "Error: Name is already used." << std::endl << std::endl;
                Character::change_font_colour(7);
            }
        }while(battlefield->players.search(name) != nullptr);
        std::cout << std::endl;
        character->set_name(name);
        battlefield->players.add(name, character);
        character->print_info();
        std::cout << std::endl;
    }
}

void Game::finish()
{
    Character* current_player = battlefield->get_current_player();
    Character::change_font_colour(6);
    std::cout << current_player->get_type() << " " << current_player->get_name() << " won!" << std::endl << std::endl;
    std::cout << R"(
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
    )" << std::endl << std::endl;
    Character::change_font_colour(7);
}

Game::~Game()
{
    delete battlefield;
}
