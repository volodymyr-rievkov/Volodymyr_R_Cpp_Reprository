#pragma once
#include"Character.hpp"
class Assasin : public Character
{
public:
    const static int r_size = 3;
    std::string replicas[r_size] = {"You better run from my blade!", "You'll never see me coming!", "Shadows consume you!"};
    Assasin();
    void scream();
};