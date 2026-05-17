#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(0);
    b.beRepaired(5);

    for (int i = 0; i < 12; i++)
        a.attack("B");

    a.beRepaired(10);

    ClapTrap c("C");
    c.takeDamage(9999);
    c.attack("X");

    return (0);
}