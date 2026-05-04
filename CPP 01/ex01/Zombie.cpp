#include <Zombie.hpp>

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...";
}
void Zombie::setName(std::string name)
{
    this->_name = name;
}