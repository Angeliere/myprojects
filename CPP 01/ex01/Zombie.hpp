#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    public:
        Zombie();                       
        Zombie(const Zombie& other); 
        ~Zombie(); 
        Zombie& operator=(const Zombie& other);

        void setName();

        std::string getName() const;

        void announce(void);
        void setName(std::string name);
        Zombie* newZombie( std::string name );

    private:
        std::string _name;
};

#endif