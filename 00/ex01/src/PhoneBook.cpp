#include "PhoneBook.hpp"
#include <iostream>

Phonebook::Phonebook(void){
	// std::cout << "Constructor Called" << std::endl;
}

Phonebook::~Phonebook(void){
	// std::cout << "Destructor Called" << std::endl;
	return;
}

static std::string get_input(std::string type)
{
	std::string str = "";
	while (str.empty())
	{
		std::cout << type << ": ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ("");
		}
		if (!str.empty())
			return (str);
	}
	return (str);
}

void Phonebook::moveContacts(void)
{
	for (int i = 0; i < 7; i++)
	{
		contacts[i].setFirstName(contacts[i + 1].getFirstName());
		contacts[i].setLastName(contacts[i + 1].getLastName());
		contacts[i].setNickname(contacts[i + 1].getNickname());
		contacts[i].setNumber(contacts[i + 1].getNumber());
		contacts[i].setSecret(contacts[i + 1].getSecret());
	}
}

void Phonebook::addContact(void)
{
	if (contact_count == 7)
		moveContacts();
	std::cout << contact_count << std::endl;
	contacts[contact_count].setFirstName(get_input("FIRST NAME"));
	if (contacts[contact_count].getFirstName().empty())
		return ;
	contacts[contact_count].setLastName(get_input("LAST NAME"));
	if (contacts[contact_count].getLastName().empty())
		return ;
	contacts[contact_count].setNickname(get_input("NICKNAME"));
	if (contacts[contact_count].getNickname().empty())
		return ;
	contacts[contact_count].setNumber(get_input("NUMBER"));
	if (contacts[contact_count].getNumber().empty())
		return ;
	contacts[contact_count].setSecret(get_input("Give me your darkest secret"));
	if (contacts[contact_count].getSecret().empty())
		return ;
	std::cout << "Contact entered into the phonebook" << std::endl;
	if (contact_count != 7)
		contact_count++;
}

static void print_name(std::string name)
{
	for (size_t j = 0; name.size() < 9 && j < 9 - name.size(); j++)
			std::cout << " ";
	std::string::iterator it;
	int i = 0;
	for (it = name.begin(); it < name.end() && i < 9; it++, i++)
		std::cout << *it;
	if (it != name.end())
		std::cout << ".";
}

void Phonebook::printContact(void) const
{
	for (int i = 0; i <= contact_count; i++)
	{
		for (int j = 0; j < 9; j++)
			std::cout << " ";
		std::cout << i + 1 << "|";
		print_name(contacts[i].getFirstName());
		std::cout << "|";
		print_name(contacts[i].getLastName());
		std::cout << "|";
		print_name(contacts[i].getNickname());
		std::cout << std::endl;
	}
}

int Phonebook::get_index(void) const
{
	int index = 0;
	while (1)
	{
		std::cout << "INDEX: ";
		std::string str;
		std::getline(std::cin, str);
		index = std::atoi(str.c_str());
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (-1);
		}
		if ((index <= 0 && index != -1) || index > contact_count + 1)
			std::cout << "Invalid index please try an index between " << 1 << " & " << contact_count + 1 << ", or -1 to cancel" << std::endl;
		else
			break;
	}
	return (index);
}

static void print_contact_info(Contact contact)
{
	std::cout << "FIRST NAME: " << contact.getFirstName() << std::endl;
	std::cout << "LAST NAME: " << contact.getLastName() << std::endl;
	std::cout << "NICKNAME: " << contact.getNickname() << std::endl;
	std::cout << "NUMBER: " << contact.getNumber() << std::endl;
	std::cout << "DEEPEST DARKEST SECRET: " << contact.getSecret() << std::endl;
}

void Phonebook::search(void) const
{
	if (contact_count == 0)
	{
		std::cout << "No entries in the phonebook" << std::endl;
		return ;
	}
	printContact();
	int index = get_index() - 1;
	if (index == -2)
		return ;
	print_contact_info(contacts[index]);
}
