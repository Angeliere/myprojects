#ifndef HUMANA.HPP
# define HUMANA.HPP

# include <iostream>

class HumanA
{
	public:
	
	HumanA(std::string const name, Weapon &wapon);
	void attack() const;
	private:
	
	std::string _name;
	Weapon &_weapon;
}

#endif
