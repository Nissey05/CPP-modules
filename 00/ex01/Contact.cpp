#include "Contact.hpp"

Contact::Contact(void){
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Contact::~Contact(void){
	// std::cout << "Default destructor called" << std::endl;
	return;
}

Contact::Contact(std::string name){
	first_name = name;
	std::cout << "Default contact name is " << first_name << std::endl;
	return;
}

std::string	Contact::getFirstName(void) const{
	return first_name;
}

void	Contact::setFirstName(std::string name){
	first_name = name;
	return;
}

std::string	Contact::getLastName(void) const{
	return last_name;
}

void	Contact::setLastName(std::string name){
	last_name = name;
	return;
}

std::string	Contact::getAddress(void) const{
	return address;
}

void	Contact::setAddress(std::string str){
	address = str;
	return;
}

std::string	Contact::getSecret(void) const{
	return darkest_secret;
}

void	Contact::setSecret(std::string str){
	darkest_secret = str;
	return;
}