#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "---1.---" << std::endl;
    delete meta;
    delete j; 
    delete i; 
    return 0;

    std::cout << "---2.---" << std::endl;
const int size = 4;
Animal* animals[size];
for (int k = 0; k < size; k++)
{
    if (k % 2 == 0)
        animals[k] = new Dog();
    else
        animals[k] = new Cat();
}
for (int k = 0; k < size; k++)
    animals[k]->makeSound();
for (int k = 0; k < size; k++)
    delete animals[k];

std::cout << "\n---3.---" << std::endl;
Dog basic;
Dog copy(basic);
Dog assigned;
assigned = basic;
std::cout << copy.getType() << std::endl;
std::cout << assigned.getType() << std::endl;

std::cout << "---4.---" << std::endl;
{
    Cat stackCat;
    Dog stackDog;
    stackCat.makeSound();
    stackDog.makeSound();
}
}