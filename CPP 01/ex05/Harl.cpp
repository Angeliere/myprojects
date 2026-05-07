#include "Harl.hpp"
#include <iostream>


void Harl::debug () {std::cout << "DEBUG : This is a debug testing and implementation and im tired of this" << std::endl; }
void Harl::info () {std::cout << "INFO : This is simply an informative debug message and to tell you stop" << std::endl; }
void Harl::warning () {std::cout << "WARNING : WARNING ! WARNING ! WARNING! i dont know why" << std::endl; }
void Harl::error () {std::cout << "ERROR : There is an error somewhere find it or else" << std::endl; }

void Harl::complain(std::string level)
{
    void (Harl::*funcs[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error} ;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while(i < 4)
    {
        if (levels[i] == level)
            (this->*funcs[i])();
        i++;
    }
    return ;
}