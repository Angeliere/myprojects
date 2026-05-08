#include "Zombie.hpp"
#include <cstdlib>

int main(int argc , char** argv)
{
    if(argc != 3)
    {
        std::cout << "invalid number of arguments ,valid input ./zombieHorde <N> <name>" << std::endl;
        return(1);
    }
    std::string name = argv[2];
    int N = atoi(argv[1]);
    if (N <= 0)
	{
		std::cout << "N must be a positive number" << std::endl;
		return (1);
	}
    Zombie* horde = zombieHorde(N,name);
    int i = 0;
    while(i < N)
    {
        horde[i].announce();
        i++;
    }
    
    delete[] horde;
    return(0);
}