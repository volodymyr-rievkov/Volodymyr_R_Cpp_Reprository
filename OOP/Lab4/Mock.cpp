#include"Mock.hpp"
#include"sstream"

void Mock::set_battlefield(int number, Game &g)
{
    std::stringstream input;
    input << number << "\n";
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
    std::stringstream output;
    std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());
    g.set_battlefield();
    std::cout.rdbuf(orig_cout);
    std::cin.rdbuf(orig_cin); 
}

void Mock::set_players_amount(int number, Game &g)
{
    std::stringstream input;
    input << number << "\n";
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
    std::stringstream output;
    std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());
    g.set_players_amount();
    std::cout.rdbuf(orig_cout);
    std::cin.rdbuf(orig_cin); 
}