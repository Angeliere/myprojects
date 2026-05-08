#ifndef HUMANA.HPP
# define HUMANA.HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA(std::string const name, Weapon &wapon);
	~HumanA();
	void attack() const;

	private:
	std::string _name;
	Weapon &_weapon;
};

#endif
