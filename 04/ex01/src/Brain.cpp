#include "../inc/Brain.hpp"
#include "colors.h"
#include <iostream>

Brain::Brain()
{
	std::cout << BOLD_BRIGHT_YELLOW << "Brain default constructor called" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << BOLD_BRIGHT_YELLOW << "Brain default destructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& cpy)
{
	std::cout << BOLD_BRIGHT_YELLOW << "Brain copy constructor called" << RESET << std::endl;
	if (this != &cpy)
	{
		*this = cpy;
	}
}

Brain&	Brain::operator=(const Brain& cpy)
{
	std::cout << BOLD_BRIGHT_YELLOW << "Brain copy assignment operator called" << RESET << std::endl;
	if (this != &cpy)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = cpy.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i > 99)
		return ;
	this->ideas[i] = idea;
}

std::string Brain::getIdea(int i)
{
	if (i < 100)
		return (ideas[i]);
	return ("No thoughts here");
}
