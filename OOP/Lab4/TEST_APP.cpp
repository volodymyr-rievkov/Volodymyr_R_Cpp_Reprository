#include"TEST_APP.hpp"
#include<iostream>
#include<sstream>
#include"Game.hpp"

void TEST_APP::TEST_SET_DAMAGE_BATTLEFIELD()
{
    std::stringstream input("1\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
    std::stringstream output;
    std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());
    Game game;
    game.set_battlefield();
    std::cout.rdbuf(orig_cout);
    std::cin.rdbuf(orig_cin); 
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
    std::stringstream input("2\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
    std::stringstream output;
    std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());
    Game game;
    game.set_battlefield();
    std::cout.rdbuf(orig_cout);
    std::cin.rdbuf(orig_cin);
    if(game.get_battlefield() != nullptr) 
    {
        std::cout << "Test №2 'set_battlefield(health)' - " << "Passed." << std::endl;
    } 
    else 
    {
        std::cerr << "Test №2 'set_battlefield(health)' - " << "Failed." << std::endl;
    }
}

void TEST_APP::TEST_SET_PLAYERS_AMOUNT()
{

}
