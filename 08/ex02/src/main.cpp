#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	std::cout << "MutantStack:" << std::endl;
	MutantStack<int> ms;

	ms.push(12);
	ms.push(21);
	ms.push(36);
	ms.push(-5);
	ms.push(69);

	std::cout << "regular iterator:" << std::endl;
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "\nreverse iterator:" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); rit++)
		std::cout << *rit << std::endl;

	std::cout << "\n\nList:" << std::endl;
	
	std::list<int> lst;

	lst.push_back(12);
	lst.push_back(21);
	lst.push_back(36);
	lst.push_back(-5);
	lst.push_back(69);

	std::cout << "regular iterator:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "\nreverse iterator:" << std::endl;
	for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); rit++)
		std::cout << *rit << std::endl;
}