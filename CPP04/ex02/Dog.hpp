#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual ~Dog();

        virtual void makeSound() const;
        Brain* getBrain() const;

    private:
        std::string type;
        Brain* brain;
};

#endif