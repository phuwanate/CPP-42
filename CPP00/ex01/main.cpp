#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string cmd;

    std::cout << "Enter the command: ";
    while (std::getline(std::cin, cmd))
    {
        if (cmd == "ADD")
            phonebook.add_contact();
        else if (cmd == "SEARCH")
            phonebook.search_contact();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "\033[31m" << "Command not found !!!" << '\n' << "\033[0m";
        if (!std::cin.eof())
            std::cout << "Enter the command: ";
    }
    return (EXIT_SUCCESS);
}