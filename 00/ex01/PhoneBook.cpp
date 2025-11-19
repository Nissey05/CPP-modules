#include "PhoneBook.hpp"
#include <iostream>

Phonebook::Phonebook(void){
	// std::cout << "Constructor Called" << std::endl;
}

Phonebook::Phonebook(Contact contact){
	contacts[contact_count] = contact;
	std::cout << "My name is " << contact.getFirstName() << std::endl;
	return;
}

Phonebook::~Phonebook(void){
	// std::cout << "Destructor Called" << std::endl;
	return;
}

static std::string get_input(std::string type)
{
	std::string str;
	while (str.empty())
	{
		std::cout << type << ": ";
		std::cin >> str;
		if (std::cin.eof())
			return (NULL);
		if (!str.empty())
			return (str);
	}
	return (str);
}

void Phonebook::addContact(void)
{
	
	contacts[contact_count].setFirstName(get_input("FIRST NAME"));
	if (contacts[contact_count].getFirstName().empty())
		return ;
	contacts[contact_count].setLastName(get_input("LAST NAME"));
	if (contacts[contact_count].getLastName().empty())
		return ;
	contacts[contact_count].setAddress(get_input("ADDRESS"));
	if (contacts[contact_count].getAddress().empty())
		return ;
	contacts[contact_count].setSecret(get_input("Give me your darkest secret"));
	if (contacts[contact_count].getSecret().empty())
		return ;
	std::cout << "Contact entered into the phonebook" << std::endl;
	contact_count++;
}

static void print_name(std::string name)
{
	for (size_t j = 0; name.size() < 9 && j < 9 - name.size(); j++)
			std::cout << " ";
	std::string::iterator it;
	for (it = name.begin(); it < name.end(); it++)
	std::cout << name << "| ";
}

void Phonebook::printContact(void) const
{
	for (int i = 0; contact_count > i; i++)
	{
		for (int j = 0; j < 9; j++)
			std::cout << " ";
		std::cout << i << "| ";
		print_name(contacts[i].getFirstName());
		print_name(contacts[i].getLastName());
		std::cout << std::endl;
	}
}