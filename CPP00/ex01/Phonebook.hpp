#include "Contact.hpp"

class PhoneBook
{
    private:
            Contact     _contact[8];
            int         _i;
            int         _j;
            void        _fill_book(const std::string &str, size_t size);
            void        _header_contact(void);
            void        _read_contact(Contact &list, int index);
            void        _single_contact(Contact &list, int index);
            void        _error_msg(int index);
            int         _check_index(std::string str, int index);

    public:
                        PhoneBook(void);
                        ~PhoneBook(void);
            void        add_contact(void);
            void        search_contact(void);
};