#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "======1.=======" << std::endl;
    ScavTrap a("Alpha");
    ScavTrap b("Bravo");

    std::cout << "======2.=======" << std::endl;
    a.attack("Bravo");
    b.takeDamage(20);

    std::cout << "======3.=======" << std::endl;
    b.beRepaired(15);

    std::cout << "======4.=======" << std::endl;
    a.guardGate();

    std::cout << "======5.=======" << std::endl;
    a.takeDamage(30);
    a.beRepaired(10);

    std::cout << "======6.=======" << std::endl;
    ClapTrap* poly = &a;
    poly->attack("Bravo");
    a.attack("Bravo");

    std::cout << "======7.=======" << std::endl;
    ScavTrap clone(a);

    std::cout << "======8.=======" << std::endl;
    ScavTrap charlie("Charlie");
    charlie = a;

    std::cout << "======9.=======" << std::endl;
    ScavTrap drain("Drain");
    for (int i = 0; i < 52; i++)
        drain.attack("dummy");

    std::cout << "======10.=======" << std::endl;
    ScavTrap glass("Glass");
    glass.takeDamage(9999);
    glass.attack("anyone");

    return (0);
}