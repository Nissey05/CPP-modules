#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	Phonebook	pb;
	
	while (1)
	{
		std::string str;
		std::cout << "Please ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, str);
		if (!str.compare("EXIT"))
			break;
		else if (!str.compare("ADD"))
			pb.addContact();
		else if (!str.compare("SEARCH"))
			pb.search();
		if (std::cin.eof())
			break;
	}
	return (0);
}