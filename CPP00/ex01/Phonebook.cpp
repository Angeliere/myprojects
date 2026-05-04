#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
    for (int i = 0; i < 8; i++)
        this->_contact[i] = other._contact[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
    if (this != &other)
        for (int i = 0; i < 8; i++)
            this->_contact[i] = other._contact[i];
    return *this;
}

PhoneBook::~PhoneBook()
{
}

bool isValidInt(const std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

bool isBlank(const std::string &s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r')
            return false;
    return true;
}

bool isLettersOnly(const std::string &s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (!std::isalpha(s[i]))
            return false;
    return true;
}

bool isValidPhone(const std::string &s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (!std::isdigit(s[i]) && s[i] != '+')
            return false;
    return true;
}

bool PhoneBook::addContact(int index)
{
    std::string input;
    Contact temp;

    while (input.empty() || !isLettersOnly(input))
    {
        std::cout << "First name :";
        std::getline(std::cin, input);
        if (input == "EXIT")
            return false;
        if (input.empty())
            std::cout << "Error: field cannot be empty" << std::endl;
        else if (!isLettersOnly(input))
        {
            std::cout << "Error: only letters allowed" << std::endl;
            input.clear();
        }
    }
    temp.setFirstName(input);
    input.clear();

    while (input.empty() || !isLettersOnly(input))
    {
        std::cout << "Last Name :";
        std::getline(std::cin, input);
        if (input == "EXIT")
            return false;
        if (input.empty())
            std::cout << "Error: field cannot be empty" << std::endl;
        else if (!isLettersOnly(input))
        {
            std::cout << "Error: only letters allowed" << std::endl;
            input.clear();
        }
    }
    temp.setLastName(input);
    input.clear();

    while (input.empty() || !isLettersOnly(input))
    {
        std::cout << "Nickname :";
        std::getline(std::cin, input);
        if (input == "EXIT")
            return false;
        if (input.empty())
            std::cout << "Error: field cannot be empty" << std::endl;
        else if (!isLettersOnly(input))
        {
            std::cout << "Error: only letters allowed" << std::endl;
            input.clear();
        }
    }
    temp.setNickname(input);
    input.clear();

    while (input.empty() || !isValidPhone(input))
    {
        std::cout << "Phone number :";
        std::getline(std::cin, input);
        if (input == "EXIT")
            return false;
        if (input.empty())
            std::cout << "Error: field cannot be empty" << std::endl;
        else if (!isValidPhone(input))
        {
            std::cout << "Error: only digits and '+' allowed" << std::endl;
            input.clear();
        }
    }
    temp.setPhoneNumber(input);
    input.clear();

    while (input.empty() || isBlank(input))
    {
        std::cout << "Darkest Secret :";
        std::getline(std::cin, input);
        if (input == "EXIT")
            return false;
        if (input.empty() || isBlank(input))
        {
            std::cout << "Error: field cannot be empty" << std::endl;
            input.clear();
        }
    }
    temp.setSecret(input);
    this->_contact[index] = temp;
    return true;
}

void PhoneBook::searchContact()
{
    std::string line;
    int i;
    int index;

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    i = 0;
    while (i < 8)
    {
        if (this->_contact[i].isEmpty() == false)
        {
            std::cout << std::setw(10) << i << "|";

            if (this->_contact[i].getFirstName().length() > 10)
                std::cout << std::setw(10) << this->_contact[i].getFirstName().substr(0, 9) + "." << "|";
            else
                std::cout << std::setw(10) << this->_contact[i].getFirstName() << "|";
            
            if (this->_contact[i].getLastName().length() > 10)
                std::cout << std::setw(10) << this->_contact[i].getLastName().substr(0, 9) + "." << "|";
            else
                std::cout << std::setw(10) << this->_contact[i].getLastName() << "|";
            
            if (this->_contact[i].getNickname().length() > 10)
                std::cout << std::setw(10) << this->_contact[i].getNickname().substr(0, 9) + "." << std::endl;
            else
                std::cout << std::setw(10) << this->_contact[i].getNickname() << std::endl;
        }
        i++;
    }

    std::cout << "Enter index: ";
    std::getline(std::cin, line);
    
    if (!isValidInt(line))
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    index = std::atoi(line.c_str());
    
    if (index < 0 || index > 7)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    
    if (this->_contact[index].isEmpty())
    {
        std::cout << "No contact at this index" << std::endl;
        return;
    }

    std::cout << "First name: " << this->_contact[index].getFirstName() << std::endl;
    std::cout << "Last name: " << this->_contact[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->_contact[index].getNickname() << std::endl;
    std::cout << "Phone number: " << this->_contact[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->_contact[index].getSecret() << std::endl;
}