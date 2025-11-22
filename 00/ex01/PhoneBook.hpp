#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP 

# include "Contact.hpp"
# include <iostream>

class Phonebook {
	private:
		Contact contacts[8];
		int	contact_count = 0;
	public:
		Phonebook(void);
		~Phonebook(void);

		void addContact(void);
		void printContact(void) const;
		void moveContacts(void);
		void test(void);
		void search(void) const;
		int get_index(void) const;
};


#endif