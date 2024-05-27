#include"TEST_APP.hpp"
#include<iostream>
#include<sstream>
#include"Game.hpp"
#include"Mock.hpp"

void TEST_APP::TEST_SET_DAMAGE_BATTLEFIELD()
{
    Mock m;
    Game game;
    m.set_battlefield(1, game);
    if(game.get_battlefield() != nullptr) 
    {
        std::cout << "Test №1 'set_battlefield(damage)' - " << "Passed." << std::endl;
    } 
    else 
    {
        std::cerr << "Test №1 'set_battlefield(damage)' - " << "Failed." << std::endl;
    }
}

void TEST_APP::TEST_SET_HEALTH_BATTLEFIELD()
{
    Mock m;
    Game game;
    m.set_battlefield(2, game);
    if(game.get_battlefield() != nullptr) 
    {
        std::cout << "Test №2 'set_battlefield(health)' - Passed." << std::endl;
    } 
    else 
    {
        std::cerr << "Test №2 'set_battlefield(health)' - Failed." << std::endl;
    }
}

void TEST_APP::TEST_SET_PLAYERS_AMOUNT()
{
    Mock m;
    Game game;
    m.set_battlefield(1, game); 
    m.set_players_amount(3, game);
    int* players_amount = game.get_battlefield()->get_players_amount();
    if (players_amount != nullptr && *players_amount == 3) 
    {
        std::cout << "Test №3 'set_players_amount()' - Passed." << std::endl;
    } 
    else 
    {
        std::cerr << "Test №3 'set_players_amount()' - Failed." << std::endl;
    }
}

void TEST_APP::TEST_SET_PLAYERS()
{
    Mock m;
    Game game;
    m.set_battlefield(1, game); 
    m.set_players_amount(2, game);
    std::stringstream input_p("1\nPlayer1\n1\nPlayer2\n");
    std::streambuf* orig_cin_p = std::cin.rdbuf(input_p.rdbuf());
    std::stringstream output_p;
    std::streambuf* orig_cout_p = std::cout.rdbuf(output_p.rdbuf());
    game.set_players();
    std::cout.rdbuf(orig_cout_p);
    std::cin.rdbuf(orig_cin_p);
    if(game.get_battlefield()->players.search("Player1") && game.get_battlefield()->players.search("Player2"))
    {
        std::cout << "Test №4 'set_players()' - Passed." << std::endl;
    } 
    else 
    {
        std::cerr << "Test №4 'set_players' - Failed." << std::endl;
    }

}

void TEST_APP::RUN_ALL_TEST()
{
    TEST_SET_DAMAGE_BATTLEFIELD();
    TEST_SET_HEALTH_BATTLEFIELD();
    TEST_SET_PLAYERS_AMOUNT();
    TEST_SET_PLAYERS();
}