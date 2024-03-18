#include"Wizard.hpp"
#include<iostream>

Wizard::Wizard()
{
    set_type("Wizard❂");
    set_name();
    set_health(40);
    set_damage(15);
    set_speed(1);
    init_funcs_vector();
    set_replicas({"Magic is my ally.",
                "My spells shall vanquish all foes.",
                "Knowledge is power."});
}

void Wizard::regeneration()
{
    health += health_reg;
    std::cout << "Health +" << health_reg << std::endl;
}

void Wizard::fire_aspect()
{
    damage += fire_a;
    std::cout << "Damage +" << fire_a << std::endl;
}

void Wizard::wrath_of_heaven()
{
    damage += wrath_o_h;
    health -= wrath_o_h;
    std::cout << "Health +" << wrath_o_h << std::endl;
    std::cout << "Damage +" << wrath_o_h << std::endl;
}

void Wizard::init_funcs_vector()
{
    super_powers_funcs.push_back(std::bind(&Wizard::regeneration, this));
    super_powers.push_back("Regeneration");
    super_powers_funcs.push_back(std::bind(&Wizard::fire_aspect, this));
    super_powers.push_back("Fire Aspect");
    super_powers_funcs.push_back(std::bind(&Wizard::wrath_of_heaven, this));
    super_powers.push_back("Wrath Of Heaven");
}

void Wizard::print_super_powers()
{
    std::cout << "Super powers: " << std::endl;
    for(int i = 0; i < super_powers.size(); i++)
    {
        std::cout << "(" << i + 1 << ") - " << super_powers[i] << std::endl;
    }
}

void Wizard::print_info()
{
    std::cout << get_type() << " " << get_name()  << std::endl;
    Character::print_info();
    std::cout << " - Feature: " << super_powers.size() << " " << feature << std::endl;
}

void Wizard::use_super_power()
{
    int super_power = 0;
    if(super_powers.size() != 0)
    {
        do
        {
            print_super_powers();
            std::cout << "Enter super power number: ";
            std::cin >> super_power;
            if(super_power < 1 || super_power > super_powers.size())
            {
                std::cout << "Error: Super power number is out of range." << std::endl;
            }
        } while (super_power < 1 || super_power > super_powers.size());
        super_powers_funcs[super_power - 1]();
        std::cout << super_powers[super_power - 1] << " has been used." << std::endl;
        super_powers.erase(super_powers.begin() + (super_power - 1));
    }
    else
    {
        std::cout << "Super powers are not availible" << std::endl;
    }
}

void Wizard::scream()
{
    std::cout << get_type() << " " << get_name() << " screamed: ";
    Character::scream();
}