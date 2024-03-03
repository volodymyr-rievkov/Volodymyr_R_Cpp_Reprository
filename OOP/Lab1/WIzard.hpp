#pragma once
#include"Character.hpp"
class Wizard : public Character
{
public:
    const static int r_size = 3;
    std::string replicas[r_size] = {"I will destroy everything, Inferno's Embrace!", "Let the earth tremble and skies roar!", "Rise, guardian of the arcane realm!"};
    Wizard();
    void scream();
};