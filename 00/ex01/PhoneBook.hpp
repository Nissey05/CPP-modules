#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP 

# include "Contact.hpp"
# include <iostream>

class Phonebook {
	private:
		Contact contacts[8];
		std::string name;
		int	contact_count = 0;
	public:
		Phonebook(void);
		Phonebook(Contact contact);
		~Phonebook(void);

		void addContact(void);
		void printContact(void) const;
};


#endif