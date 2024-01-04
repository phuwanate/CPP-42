#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{
    // std::cout << "constructor called" << '\n';
}

Contact::~Contact(void)
{
    // std::cout << "deconstructor called" << '\n';
}

std::string			Contact::get_first(void)
{
    return (this->first_name);
}

std::string				Contact::get_last(void)
{
    return (this->last_name);
}

std::string				Contact::get_nick(void)
{
    return (this->nick_name);
}

std::string				Contact::get_phone(void)
{
    return (this->phone_number);
}

std::string				Contact::get_darkest(void)
{
    return (this->darkest_secret);
}

std::string    Contact::_get_contact(std::string &str, std::string msg)
{
    std::cout << msg;
    while (std::getline(std::cin, str))
    {
        if (str != "\0")
            break;
        if (!std::cin.eof())
        {
            std::cout << "\033[31m" << "Contact can't have empty fields!!!" "\033[0m" << '\n';
            std::cout << msg;
        }
    }
    return str;
}

void Contact::add(void)
{
    std::cout << "---------------------------------------------" << '\n';
    if (_get_contact(first_name, "First Name:     ") == "\0")
        return ;
    if (_get_contact(last_name, "Last Name:      ") == "\0")
        return ;
    if (_get_contact(nick_name, "Nick Name:      ") == "\0")
        return ;
    if (_get_contact(phone_number, "Phone Number:   ") == "\0")
        return ;
    if (_get_contact(darkest_secret, "Darkest Secret: ") == "\0")
        return ;
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "\033[32m" << "---------------------------------------------" << '\n';
    std::cout << "$$$         SAVING A NEW CONTACT...       $$$" << '\n';
    std::cout << "---------------------------------------------" << "\033[0m" << '\n';
}