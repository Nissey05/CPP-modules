#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

Base *generate(void)
{
	int rand = std::rand();
	switch (rand % 3)
	{
		case (0):
			return (new A());
		case (1):
			return (new B());
		case (2):
			return (new C());
		default:
			return (nullptr);
	}
}

void identify(Base *p)
{
	Base *cpy;
	
	cpy = dynamic_cast<A *>(p);
	if (cpy != nullptr)
	{
		std::cout << "Type is A" << std::endl;
		return ;
	}
	cpy = dynamic_cast<B *>(p);
	if (cpy != nullptr)
	{
		std::cout << "Type is B" << std::endl;
		return ;
	}
	cpy = dynamic_cast<C *>(p);
	if (cpy != nullptr)
	{
		std::cout << "Type is C" << std::endl;
		return ;
	}
	std::cout << "Type not known" << std::endl;
}

void identify(Base &p)
{
	Base cpy;

	try
	{
		Base cpy = dynamic_cast<A &>(p);
		std::cout << "Type is A" << std::endl;
		return ;
	}
	catch(std::bad_cast)
	{}
	try
	{
		Base cpy = dynamic_cast<B &>(p);
		std::cout << "Type is B" << std::endl;
		return ;
	}
	catch(std::bad_cast)
	{}
	try
	{
		Base cpy = dynamic_cast<C &>(p);
		std::cout << "Type is C" << std::endl;
		return ;
	}
	catch(std::bad_cast)
	{}
	std::cout << "Type not known" << std::endl;
}

int main(void)
{
	Base *p = generate();

	identify(p);
	delete (p);
	B c;
	identify(c);
	p = generate();
	identify(p);
}