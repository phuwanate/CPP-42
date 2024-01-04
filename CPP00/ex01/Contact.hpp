#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
			std::string		first_name, last_name, nick_name,\
							phone_number, darkest_secret;
			std::string    _get_contact(std::string &str, std::string msg);
	public:
							Contact(void);
							~Contact(void);
			void			add(void);
			std::string		get_first(void);
			std::string		get_last(void);
			std::string		get_nick(void);
			std::string		get_phone(void);
			std::string		get_darkest(void);
};

#endif