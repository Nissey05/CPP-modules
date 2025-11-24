#include "Contact.hpp"

Contact::Contact(void){
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Contact::~Contact(void){
	// std::cout << "Default destructor called" << std::endl;
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

std::string	Contact::getNickname(void) const{
	return nickname;
}

void	Contact::setNickname(std::string name){
	nickname = name;
	return;
}

std::string	Contact::getNumber(void) const{
	return phone_number;
}

void	Contact::setNumber(std::string str){
	phone_number = str;
	return;
}

std::string	Contact::getSecret(void) const{
	return darkest_secret;
}

void	Contact::setSecret(std::string str){
	darkest_secret = str;
	return;
}