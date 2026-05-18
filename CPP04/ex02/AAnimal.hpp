#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"


class Brain;

class AAnimal
{
    public:
        AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        std::string getType() const;

    protected:
        std::string type;
        Brain* getBrain() const;

};

#endif