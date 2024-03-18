#include<iostream>
#include"Battelfield.hpp"
using namespace std;

Battlefield::Battlefield()
{

}

void Battlefield::set_players_amount()
{
    do
    {
        cout << "Enter amount of players(2-6): ";
        cin >> players_amount;
        if(players_amount < 2 || players_amount > 6)
        {
            cout << "Error: Amount of players is out of range." << endl;
        }
    } while (players_amount < 2 || players_amount > 6);
}

void Battlefield::set_characters()
{
    for(int i = 0; i < players_amount; i++)
    {
        int count = 0;
        for(auto character : characters)
        {
            cout << count++ << " - " << character << endl;
        }
    }
}



