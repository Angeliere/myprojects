#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact
{
    public:
        Contact();
        Contact(const Contact& other);
        ~Contact();
        Contact& operator=(const Contact& other);

        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setNickname(std::string nickname);
        void setPhoneNumber(std::string phoneNumber);
        void setSecret(std::string secret);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getSecret() const;
        bool isEmpty() const;
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _secret;
};

#endif