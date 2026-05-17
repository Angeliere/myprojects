#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "======1.=======" << std::endl;
    FragTrap a("Alpha");
    FragTrap b("Bravo");

    std::cout << "======2.=======" << std::endl;
    a.attack("Bravo");
    b.takeDamage(30);

    std::cout << "======3.=======" << std::endl;
    b.beRepaired(15);

    std::cout << "======4.=======" << std::endl;
    a.highFivesGuys();

    std::cout << "======5.=======" << std::endl;
    a.takeDamage(40);
    a.beRepaired(10);

    std::cout << "======6.=======" << std::endl;
    ClapTrap* poly = &a;
    poly->attack("Bravo");
    a.attack("Bravo");

    std::cout << "======7.=======" << std::endl;
    FragTrap clone(a);

    std::cout << "======8.=======" << std::endl;
    FragTrap charlie("Charlie");
    charlie = a;

    std::cout << "======9.=======" << std::endl;
    FragTrap drain("Drain");
    for (int i = 0; i < 102; i++)
        drain.attack("dummy");

    std::cout << "======10.=======" << std::endl;
    FragTrap glass("Glass");
    glass.takeDamage(9999);
    glass.attack("anyone");

    return (0);
}