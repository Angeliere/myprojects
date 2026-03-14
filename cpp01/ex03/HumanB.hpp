#ifndef HUMANB.HPP
# define HUMANB.HPP

# include <iostream>

class HumanB {
private:
    std::string _name;
    Weapon *_weapon;
public:
    HumanB(std::string const name);
    void setWeapon(Weapon &weapon);
    void attack() const;
};
