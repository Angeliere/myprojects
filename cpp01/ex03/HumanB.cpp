#include <HumanN.hpp>
HumanB::HumanB(std::string const name, Weapon *weapon)
{}

void HumanB::attack() const {
    if (this->_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon!" << std::endl;
}
