#include <HumanA.hpp>
void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon << std::endl;
}

HumanA::HumanA(std::string const name , Weapon &weapon) : _name(name), _weapon(weapon) {};


