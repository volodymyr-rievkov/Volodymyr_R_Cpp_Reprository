#pragma once
#include"Character.hpp"
class Archer : public Character
{
public:
    const static int r_size = 3;
    std::string replicas[r_size] = {"You can't dodge my arrows!", "My arrow is faster than you!", "You're as slow as a turtle!"};
    Archer();
    void scream();
};