#include "dog.hpp"

Dog::Dog() : type("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : type(other.type) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog barks!" << std::endl;
}
