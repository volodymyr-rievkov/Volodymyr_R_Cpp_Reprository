#include<iostream>
#include"Assasin.hpp"
#include"Archer.hpp"
#include"Wizard.hpp"

int main()
{
    Assasin as1;
    Archer ar1;
    Wizard w1;

    std::cout << "Assasin: " << std::endl;
    as1.set_health();
    as1.set_damage();
    as1.set_speed();
    as1.set_name();
    as1.set_super_power();
    as1.scream();

    std::cout << "Archer: " << std::endl;
    ar1.set_health();
    ar1.set_damage();
    ar1.set_speed();
    ar1.set_name();
    ar1.set_super_power();
    ar1.scream();

    std::cout << "Wizard: " << std::endl;
    w1.set_health();
    w1.set_damage();
    w1.set_speed();
    w1.set_name();
    w1.set_super_power();
    w1.scream();

    as1.print_info();
    ar1.print_info();
    w1.print_info();

    // Assasin as2;
    // Archer ar2;
    // Wizard w2;

    // as2.set_health(20);
    // as2.set_damage(50);
    // as2.set_speed(30);
    // as2.set_name("Gregory");
    // as2.set_super_power(0);
    // as2.scream();

    // ar2.set_health(20);
    // ar2.set_damage(30);
    // ar2.set_speed(50);
    // ar2.set_name("Sam");
    // ar2.set_super_power(1);
    // ar2.scream();

    // w2.set_health(20);
    // w2.set_damage(60);
    // w2.set_speed(20);
    // w2.set_name("Tom");
    // w2.set_super_power(2);
    // w2.scream();

    // as2.print_info();
    // ar2.print_info();
    // w2.print_info();
}