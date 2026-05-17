#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitpoints(10), _energypoints(10), _attackdamage(0) {
    std::cout << "Claptrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0) {
    std::cout << "ClapTrap" << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :  _name(other._name), _hitpoints(other._hitpoints), _energypoints(other._energypoints), _attackdamage(other._attackdamage) { 
    std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_attackdamage = other._attackdamage;
        this->_hitpoints = other._hitpoints;
        this->_energypoints = other._energypoints;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if(_energypoints == 0 || _hitpoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    _energypoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if(_energypoints == 0 || _hitpoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy or hit points left to take damage!" << std::endl;
        return;
    }
    _hitpoints -= amount;
    if(_hitpoints < 0)
        _hitpoints = 0;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(_energypoints == 0 || _hitpoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy or hit points left to be repaired!" << std::endl;
        return;
    }
    _energypoints--;
    _hitpoints += amount;
    if(_hitpoints > 10)
        _hitpoints = 10;
    std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points!" << std::endl;
}
