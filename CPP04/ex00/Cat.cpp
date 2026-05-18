#include "Cat.hpp"

Cat::Cat() : type("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : type(other.type) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat meows!" << std::endl;
}

