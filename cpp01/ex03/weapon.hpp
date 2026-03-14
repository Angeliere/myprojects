#ifndef WEAPON.HPP
# define WEAPON.HPP

# include <iostream>

class Weapon
{
	public:
	
	Weapon(std::string const type);
	std::string const &getType() const;
	
	void setType(std::string const type);
	
	private:
	
	std::string _type;
}

#endif
