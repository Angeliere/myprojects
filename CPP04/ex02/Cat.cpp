#include "Cat.hpp"
#include "Brain.hpp"

Brain* Cat::getBrain() const {
    return this->brain;
}
Cat::Cat() : type("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : type(other.type) {
    this->brain = new Brain();
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
        *this->brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat meows!" << std::endl;
}

