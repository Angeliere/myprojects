
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    _name         = "default";
    _hitpoints    = 100;
    _energypoints = 50;
    _attackdamage = 20;
    std::cout << "ScavTrap default scavenged and constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
    _hitpoints    = 100;
    _energypoints = 50;
    _attackdamage = 20;
    std::cout << "ScavTrap" << _name << " scavenged and constructed" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy scavenged and constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment scavenged and constructed" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap scraping complete" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if(_energypoints == 0 || _hitpoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is tired or dead leave him alone!" << std::endl;
        return;
    }
    _energypoints--;
    std::cout << "ScavTrap " << this->_name << " bonks " << target << ", causing " << this->_attackdamage << " points of hitpoint reduction!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}