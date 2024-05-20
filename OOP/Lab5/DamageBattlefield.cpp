#include"DamageBattlefield.hpp"

void DamageBattlefield::start()
{
    int* players_amount = get_players_amount();
    set_random_current_player();
    while(*players_amount > 1)
    {
        Character* current_player = get_current_player();
        current_player->print_info();
        std::cout << std::endl;
        current_player->use_feature();
        perform_attack();
        check_deaths();
        change_current_player();
        random_damage();
        check_deaths();
    }
}

void DamageBattlefield::print_title()
{
    Character::change_font_colour(4);
    std::cout << R"(
                ▓█████▄  ▄▄▄       ███▄ ▄███▓ ▄▄▄        ▄████ ▓█████     ▄▄▄▄    ▄▄▄     ▄▄▄█████▓▄▄▄█████▓ ██▓    ▓█████   █████▒██▓▓█████  ██▓    ▓█████▄    
                ▒██▀ ██▌▒████▄    ▓██▒▀█▀ ██▒▒████▄     ██▒ ▀█▒▓█   ▀    ▓█████▄ ▒████▄   ▓  ██▒ ▓▒▓  ██▒ ▓▒▓██▒    ▓█   ▀ ▓██   ▒▓██▒▓█   ▀ ▓██▒    ▒██▀ ██▌   
                ░██   █▌▒██  ▀█▄  ▓██    ▓██░▒██  ▀█▄  ▒██░▄▄▄░▒███      ▒██▒ ▄██▒██  ▀█▄ ▒ ▓██░ ▒░▒ ▓██░ ▒░▒██░    ▒███   ▒████ ░▒██▒▒███   ▒██░    ░██   █▌   
                ░▓█▄   ▌░██▄▄▄▄██ ▒██    ▒██ ░██▄▄▄▄██ ░▓█  ██▓▒▓█  ▄    ▒██░█▀  ░██▄▄▄▄██░ ▓██▓ ░ ░ ▓██▓ ░ ▒██░    ▒▓█  ▄ ░▓█▒  ░░██░▒▓█  ▄ ▒██░    ░▓█▄   ▌   
                ░▒████▓  ▓█   ▓██▒▒██▒   ░██▒ ▓█   ▓██▒░▒▓███▀▒░▒████▒   ░▓█  ▀█▓ ▓█   ▓██▒ ▒██▒ ░   ▒██▒ ░ ░██████▒░▒████▒░▒█░   ░██░░▒████▒░██████▒░▒████▓    
                ▒▒▓  ▒  ▒▒   ▓▒█░░ ▒░   ░  ░ ▒▒   ▓▒█░ ░▒   ▒ ░░ ▒░ ░   ░▒▓███▀▒ ▒▒   ▓▒█░ ▒ ░░     ▒ ░░   ░ ▒░▓  ░░░ ▒░ ░ ▒ ░   ░▓  ░░ ▒░ ░░ ▒░▓  ░ ▒▒▓  ▒    
                ░ ▒  ▒   ▒   ▒▒ ░░  ░      ░  ▒   ▒▒ ░  ░   ░  ░ ░  ░   ▒░▒   ░   ▒   ▒▒ ░   ░        ░    ░ ░ ▒  ░ ░ ░  ░ ░      ▒ ░ ░ ░  ░░ ░ ▒  ░ ░ ▒  ▒    
                ░ ░  ░   ░   ▒   ░      ░     ░   ▒   ░ ░   ░    ░       ░    ░   ░   ▒    ░        ░        ░ ░      ░    ░ ░    ▒ ░   ░     ░ ░    ░ ░  ░    
                ░          ░  ░       ░         ░  ░      ░    ░  ░    ░            ░  ░                     ░  ░   ░  ░        ░     ░  ░    ░  ░   ░       
                ░                                                             ░                                                                      ░      
    )" << std::endl << std::endl; 
    Character::change_font_colour(7);
}

void DamageBattlefield::random_damage()
{
    int* players_amount = get_players_amount();
    Character* current_player = nullptr;
    const int damage = 5;
    if(*players_amount > 1)
    {
        srand(time(0));
        int index = rand() % *players_amount;
        int count = 0;
        for(auto player = players.begin(); player != players.end(); ++player)
        {
            if(index == count)
            {
                current_player = *player;
                current_player->health -= damage;
                Character::change_font_colour(4);
                std::cout << R"(
                     ██▀███   ▄▄▄       ███▄    █ ▓█████▄  ▒█████   ███▄ ▄███▓   ▓█████▄  ▄▄▄       ███▄ ▄███▓ ▄▄▄        ▄████ ▓█████  ▐██▌ 
                    ▓██ ▒ ██▒▒████▄     ██ ▀█   █ ▒██▀ ██▌▒██▒  ██▒▓██▒▀█▀ ██▒   ▒██▀ ██▌▒████▄    ▓██▒▀█▀ ██▒▒████▄     ██▒ ▀█▒▓█   ▀  ▐██▌ 
                    ▓██ ░▄█ ▒▒██  ▀█▄  ▓██  ▀█ ██▒░██   █▌▒██░  ██▒▓██    ▓██░   ░██   █▌▒██  ▀█▄  ▓██    ▓██░▒██  ▀█▄  ▒██░▄▄▄░▒███    ▐██▌ 
                    ▒██▀▀█▄  ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█▄   ▌▒██   ██░▒██    ▒██    ░▓█▄   ▌░██▄▄▄▄██ ▒██    ▒██ ░██▄▄▄▄██ ░▓█  ██▓▒▓█  ▄  ▓██▒ 
                    ░██▓ ▒██▒ ▓█   ▓██▒▒██░   ▓██░░▒████▓ ░ ████▓▒░▒██▒   ░██▒   ░▒████▓  ▓█   ▓██▒▒██▒   ░██▒ ▓█   ▓██▒░▒▓███▀▒░▒████▒ ▒▄▄  
                    ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ▒▒▓  ▒ ░ ▒░▒░▒░ ░ ▒░   ░  ░    ▒▒▓  ▒  ▒▒   ▓▒█░░ ▒░   ░  ░ ▒▒   ▓▒█░ ░▒   ▒ ░░ ▒░ ░ ░▀▀▒ 
                    ░▒ ░ ▒░  ▒   ▒▒ ░░ ░░   ░ ▒░ ░ ▒  ▒   ░ ▒ ▒░ ░  ░      ░    ░ ▒  ▒   ▒   ▒▒ ░░  ░      ░  ▒   ▒▒ ░  ░   ░  ░ ░  ░ ░  ░ 
                    ░░   ░   ░   ▒      ░   ░ ░  ░ ░  ░ ░ ░ ░ ▒  ░      ░       ░ ░  ░   ░   ▒   ░      ░     ░   ▒   ░ ░   ░    ░       ░ 
                    ░           ░  ░         ░    ░        ░ ░         ░         ░          ░  ░       ░         ░  ░      ░    ░  ░ ░    
                                                ░                              ░                                                                                     
                )" << std::endl << std::endl;
                std::cout << current_player->get_type() << " " << current_player->get_name() << " - " << damage << std::endl << std::endl; 
                Character::change_font_colour(7);
                break;
            }
            count++;
        }
    }
}