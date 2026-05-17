#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
    _name         = "default";
    _hitpoints    = 100;
    _energypoints = 100;
    _attackdamage = 30;
    std::cout << "FragTrap default construction mode called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) 
{
    _hitpoints    = 100;
    _energypoints = 100;
    _attackdamage = 30;
    std::cout << "FragTrap" << _name << " constructruction complete" << std::endl;
}


FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy construction complete" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment assigned" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destruction complete" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " gives a high five!" << std::endl;
}