#include "dog.hpp"
#include "Brain.hpp"

Brain* Dog::getBrain() const {
    return this->brain;
}

Dog::Dog() : type("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : type(other.type) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    *this->brain = *other.brain;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
        *this->brain = *other.brain;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "Dog barks!" << std::endl;
}
