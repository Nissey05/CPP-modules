#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string address;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string name);
		std::string	getFirstName(void) const;
		void		setFirstName(std::string name);
		std::string	getLastName(void) const;
		void		setLastName(std::string name);
		std::string	getAddress(void) const;
		void		setAddress(std::string name);
		std::string	getSecret(void) const;
		void		setSecret(std::string name);
};

#endif