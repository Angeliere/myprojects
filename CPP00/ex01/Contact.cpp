#include "Contact.hpp"

Contact::Contact()
{
    this->_first_name = "";
    this->_last_name = "";
    this->_nickname = "";
    this->_phone_number = "";
    this->_secret = "";
}

Contact::Contact(const Contact& other)
{
    this->_first_name = other._first_name;
    this->_last_name = other._last_name;
    this->_nickname = other._nickname;
    this->_phone_number = other._phone_number;
    this->_secret = other._secret;
}

Contact::~Contact()
{
}

Contact& Contact::operator=(const Contact& other)
{
    if (this != &other)
    {
        this->_first_name = other._first_name;
        this->_last_name = other._last_name;
        this->_nickname = other._nickname;
        this->_phone_number = other._phone_number;
        this->_secret = other._secret;
    }
    return *this;
}

void Contact::setFirstName(std::string firstName)
{
    this->_first_name = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->_last_name = lastName;
}

void Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->_phone_number = phoneNumber;
}

void Contact::setSecret(std::string secret)
{
    this->_secret = secret;
}

std::string Contact::getFirstName() const
{
    return this->_first_name;
}

std::string Contact::getLastName() const
{
    return this->_last_name;
}

std::string Contact::getNickname() const
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->_phone_number;
}

std::string Contact::getSecret() const
{
    return this->_secret;
}

bool Contact::isEmpty() const
{
    if (this->_first_name.empty())
        return true;
    if (this->_last_name.empty())
        return true;
    if (this->_nickname.empty())
        return true;
    if (this->_phone_number.empty())
        return true;
    if (this->_secret.empty())
        return true;
    return false;
}