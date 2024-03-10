#include<iostream>
#include"Wizard.hpp"
#include"Warrior.hpp"
#include"Golem.hpp"
#include"Archer.hpp"

int main()
{
    Wizard wz;
    wz.print_info();
    wz.print_super_powers();
    wz.scream();
    wz.use_super_power();
    wz.print_info();
    wz.print_super_powers();
    Warrior wr;
    wr.print_info();
    wr.scream();
    Golem g;
    g.print_info();
    g.scream();
    Archer a;
    a.print_info();
    a.scream();
}