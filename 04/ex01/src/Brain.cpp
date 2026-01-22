#include "../inc/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain& cpy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &cpy)
	{
		*this = cpy;
	}
}

Brain&	Brain::operator=(const Brain& cpy)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
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
