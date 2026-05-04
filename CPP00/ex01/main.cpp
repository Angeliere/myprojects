#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook arch;
    std::string command;
    int index = 0;
    bool prog = true;
    while(prog)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (!command.empty() && command[command.size() - 1] == '\r')
            command.erase(command.size() - 1);
        if(command == "ADD")
        {
            if (arch.addContact(index % 8))
                index++;
        }
        else if(command == "SEARCH")
        {
            arch.searchContact();
        }
        else if(command == "EXIT")
        {
            prog = false;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
    return(0);

}