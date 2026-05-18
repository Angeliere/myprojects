#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();

        virtual void makeSound() const;
        std::string getType() const;

    protected:
        std::string type;

};

std::ostream &operator<<(std::ostream &out, const WrongAnimal &wrongAnimal);

#endif