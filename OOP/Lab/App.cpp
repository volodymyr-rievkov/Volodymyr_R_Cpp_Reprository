#include<iostream>
#include"Battelfield.hpp"
#include"Map.hpp"

int main()
{
    // Battlefield b;
    // b.launch_game();
    Map<std::string, int> my_map;
    my_map.add("apple", 1);
    my_map.add("cucmber", 2);
    my_map.add("orange", 3);
    my_map.print();
    if(my_map.search("apple") != nullptr)
    {
        my_map.remove("apple");
    }
    my_map.print();
    return 0;
}