#include <Zombie.hpp>

Zombie::~Zombie()
{
    std::cout << _name << " was destroyed" << std::endl;
} 
int main(int argc , char** argv)
{
    if(argc != 2)
    {
        std::cout << "invalide number of arguments";
        return(1);
    }
    int i = 0;
    std::string name = argv[2];
    int N = atoi(argv[1]);
    Zombie* horde = zombieHorde(N,name);
    while(i < N)
    {
        horde[i].announce();
        i++;
    }
    
    delete[] horde;
    return(0);
}