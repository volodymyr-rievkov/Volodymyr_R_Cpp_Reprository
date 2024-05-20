#include"HealthBattlefield.hpp"

void HealthBattlefield::start()
{
    int* players_amount = get_players_amount();
    set_random_current_player();
    while(*players_amount > 1)
    {
        Character* current_player = get_current_player();
        current_player->print_info();
        std::cout << std::endl;
        current_player->use_feature();
        attack();
        change_current_player();
        random_health();
    }
}

void HealthBattlefield::print_title()
{
    Character::change_font_colour(2);
    std::cout << R"(
                 ██░ ██ ▓█████ ▄▄▄       ██▓  ▄▄▄█████▓ ██░ ██     ▄▄▄▄    ▄▄▄     ▄▄▄█████▓▄▄▄█████▓ ██▓    ▓█████   █████▒██▓▓█████  ██▓    ▓█████▄    
                ▓██░ ██▒▓█   ▀▒████▄    ▓██▒  ▓  ██▒ ▓▒▓██░ ██▒   ▓█████▄ ▒████▄   ▓  ██▒ ▓▒▓  ██▒ ▓▒▓██▒    ▓█   ▀ ▓██   ▒▓██▒▓█   ▀ ▓██▒    ▒██▀ ██▌   
                ▒██▀▀██░▒███  ▒██  ▀█▄  ▒██░  ▒ ▓██░ ▒░▒██▀▀██░   ▒██▒ ▄██▒██  ▀█▄ ▒ ▓██░ ▒░▒ ▓██░ ▒░▒██░    ▒███   ▒████ ░▒██▒▒███   ▒██░    ░██   █▌   
                ░▓█ ░██ ▒▓█  ▄░██▄▄▄▄██ ▒██░  ░ ▓██▓ ░ ░▓█ ░██    ▒██░█▀  ░██▄▄▄▄██░ ▓██▓ ░ ░ ▓██▓ ░ ▒██░    ▒▓█  ▄ ░▓█▒  ░░██░▒▓█  ▄ ▒██░    ░▓█▄   ▌   
                ░▓█▒░██▓░▒████▒▓█   ▓██▒░██████▒▒██▒ ░ ░▓█▒░██▓   ░▓█  ▀█▓ ▓█   ▓██▒ ▒██▒ ░   ▒██▒ ░ ░██████▒░▒████▒░▒█░   ░██░░▒████▒░██████▒░▒████▓    
                ▒ ░░▒░▒░░ ▒░ ░▒▒   ▓▒█░░ ▒░▓  ░▒ ░░    ▒ ░░▒░▒   ░▒▓███▀▒ ▒▒   ▓▒█░ ▒ ░░     ▒ ░░   ░ ▒░▓  ░░░ ▒░ ░ ▒ ░   ░▓  ░░ ▒░ ░░ ▒░▓  ░ ▒▒▓  ▒    
                ▒ ░▒░ ░ ░ ░  ░ ▒   ▒▒ ░░ ░ ▒  ░  ░     ▒ ░▒░ ░   ▒░▒   ░   ▒   ▒▒ ░   ░        ░    ░ ░ ▒  ░ ░ ░  ░ ░      ▒ ░ ░ ░  ░░ ░ ▒  ░ ░ ▒  ▒    
                ░  ░░ ░   ░    ░   ▒     ░ ░   ░       ░  ░░ ░    ░    ░   ░   ▒    ░        ░        ░ ░      ░    ░ ░    ▒ ░   ░     ░ ░    ░ ░  ░    
                ░  ░  ░   ░  ░     ░  ░    ░  ░        ░  ░  ░    ░            ░  ░                     ░  ░   ░  ░        ░     ░  ░    ░  ░   ░       
                                                                        ░                                                                      ░       
    )" << std::endl << std::endl;
    Character::change_font_colour(7);
}

void HealthBattlefield::random_health()
{
    int* players_amount = get_players_amount();
    Character* current_player = nullptr;
    const int health = 5;
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
                current_player->health += health;
                Character::change_font_colour(2);
                std::cout << R"(
                     ██▀███   ▄▄▄       ███▄    █ ▓█████▄  ▒█████   ███▄ ▄███▓    ██░ ██ ▓█████ ▄▄▄       ██▓  ▄▄▄█████▓ ██░ ██  ▐██▌ 
                    ▓██ ▒ ██▒▒████▄     ██ ▀█   █ ▒██▀ ██▌▒██▒  ██▒▓██▒▀█▀ ██▒   ▓██░ ██▒▓█   ▀▒████▄    ▓██▒  ▓  ██▒ ▓▒▓██░ ██▒ ▐██▌ 
                    ▓██ ░▄█ ▒▒██  ▀█▄  ▓██  ▀█ ██▒░██   █▌▒██░  ██▒▓██    ▓██░   ▒██▀▀██░▒███  ▒██  ▀█▄  ▒██░  ▒ ▓██░ ▒░▒██▀▀██░ ▐██▌ 
                    ▒██▀▀█▄  ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█▄   ▌▒██   ██░▒██    ▒██    ░▓█ ░██ ▒▓█  ▄░██▄▄▄▄██ ▒██░  ░ ▓██▓ ░ ░▓█ ░██  ▓██▒ 
                    ░██▓ ▒██▒ ▓█   ▓██▒▒██░   ▓██░░▒████▓ ░ ████▓▒░▒██▒   ░██▒   ░▓█▒░██▓░▒████▒▓█   ▓██▒░██████▒▒██▒ ░ ░▓█▒░██▓ ▒▄▄  
                    ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ▒▒▓  ▒ ░ ▒░▒░▒░ ░ ▒░   ░  ░    ▒ ░░▒░▒░░ ▒░ ░▒▒   ▓▒█░░ ▒░▓  ░▒ ░░    ▒ ░░▒░▒ ░▀▀▒ 
                    ░▒ ░ ▒░  ▒   ▒▒ ░░ ░░   ░ ▒░ ░ ▒  ▒   ░ ▒ ▒░ ░  ░      ░    ▒ ░▒░ ░ ░ ░  ░ ▒   ▒▒ ░░ ░ ▒  ░  ░     ▒ ░▒░ ░ ░  ░ 
                    ░░   ░   ░   ▒      ░   ░ ░  ░ ░  ░ ░ ░ ░ ▒  ░      ░       ░  ░░ ░   ░    ░   ▒     ░ ░   ░       ░  ░░ ░    ░ 
                    ░           ░  ░         ░    ░        ░ ░         ░       ░  ░  ░   ░  ░     ░  ░    ░  ░        ░  ░  ░ ░    
                                                ░                                                                                                                                                                     
                )" << std::endl << std::endl;
                std::cout << current_player->get_type() << " " << current_player->get_name() << " + " << health << std::endl << std::endl; 
                Character::change_font_colour(7);
                break;
            }
            count++;
        }
    }
}