#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook(void)
{
    std::cout << "\033[32m" << "---------------------------------------------" << '\n';
    std::cout << "$$$    WELCOME TO THE PHONEBOOK PROGRAM   $$$" << '\n';
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "COMMAND GUIDE: " << '\n';
    std::cout << "$ ADD    -> For adding a new contact" << '\n';
    std::cout << "$ SEARCH -> For searching a contact" << '\n';
    std::cout << "$ EXIT   -> For exiting the program" << '\n';
    std::cout << "---------------------------------------------" << "\033[0m" << '\n';
    this->_i = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "\033[32m" << '\n' ;
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "$$$             LOGGING OUT...            $$$" << '\n';
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "See you next time..." << '\n' << "\033[0m";
}

void PhoneBook::_fill_book(const std::string &str, size_t size)
{
    if (size <= 10)
    {
        std::cout.width(10);
        std::cout << str;
    }
    else if (size > 10)
    {
        for (size_t i = 0; size > 0; size--, i++)
        {
            if (i == 9)
            {
                std::cout << ".";
                break ;
            }
            std::cout << str[i];
        }
    }
    std::cout << "|";
    return ;
}

void PhoneBook::_header_contact(void)
{
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "$$$             CONTACT LIST              $$$" << '\n';
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "|" << "     INDEX";
    std::cout << "|" << "FIRST NAME";
    std::cout << "|" << " LAST NAME";
    std::cout << "|" << " NICK NAME" << "|" << '\n';
    std::cout << "---------------------------------------------" << '\n';
}

void PhoneBook::_read_contact(Contact &list, int index)
{
    std::cout << "|" << "         " << index+1 << "|";
    _fill_book(list.get_first(), list.get_first().size());
    _fill_book(list.get_last(), list.get_last().size());
    _fill_book(list.get_nick(), list.get_nick().size());
    std::cout << '\n';
}

void PhoneBook::_single_contact(Contact &list, int index)
{ 
    std::cout << "\033[32m" << "---------------------------------------------" << '\n';
    std::cout << "$$$              INDEX   " << index << "                $$$" <<'\n';
    std::cout << "---------------------------------------------" << '\n';
    std::cout << "| " << "First Name:     " << list.get_first() << '\n';
    std::cout << "| " << "Last Name:      " << list.get_last() << '\n';
    std::cout << "| " << "Nick Name:      " << list.get_nick() << '\n';
    std::cout << "| " << "Phone Number:   " << list.get_phone() << '\n';
    std::cout << "| " << "Darkest Secret: " << list.get_darkest() << '\n';
    std::cout << "---------------------------------------------" << "\033[0m" << '\n';
    return ;
}

void PhoneBook::_error_msg(int index)
{
        std::cout << "\033[31m" << "You can search from : " << "1 - " << index << '\n';
        std::cout << "\033[0m";  
        std::cout << "Enter index for more information : ";
}

int PhoneBook::_check_index(std::string str, int index)
{
    for (int i = 0; str[i]; i++)
    {
        if (std::isalpha(str[i]) || str[i] == ' ')
        {
            _error_msg(index);
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}

void PhoneBook::search_contact(void)
{
    int             index;
    std::string     str;

    if (this->_i == 0)
    {
        std::cout << "\033[31m" << "You don't have any contact yet, Please 'ADD' some." << '\n' << "\033[0m";
        return ;
    }
    std::cout << "\033[32m";
    _header_contact();
    if (this->_i > 8)
        this->_j = 8;
    for (int index = 0; index < this->_j; index++)
        _read_contact(this->_contact[index], index);
    std::cout << "---------------------------------------------" << "\033[0m" << '\n';
    std::cout << "Enter index for more information : ";
    while (std::getline(std::cin, str))
    {
        if (str == "\0")
        {
            std::cout << "Enter index for more information : ";
            continue ;
        }
        if (_check_index(str, this->_j) == EXIT_FAILURE) 
            continue ;
        std::stringstream(str) >> index;
        if (index > 0 && index <= this->_j)
        {
            _single_contact(this->_contact[index - 1], index);
            break ;
        }
        if (index > this->_j || index <= 0)
            std::cout << "\033[31m" << "You can search from : " << "1 - " << _j << '\n' << "\033[0m";  
        std::cout << "Enter index for more information : ";
    }
    return ;
}

void PhoneBook::add_contact(void)
{
    if (this->_i > 7)
        this->_j = this->_i % 8;
    else
        this->_j = this->_i;
    this->_contact[this->_j].add();
    this->_i++;
    this->_j++;
}
