#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        PhoneBook(const PhoneBook& other);
        PhoneBook& operator=(const PhoneBook& other);

        bool addContact(int index);
        void searchContact();
    private:
        Contact _contact[8];
};

#endif