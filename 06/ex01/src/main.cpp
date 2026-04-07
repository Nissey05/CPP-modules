#include "data.h"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data d;
	d.data = (void *)"Hello World!";
	Data *ptr = &d;
	uintptr_t raw = Serializer::serialize(ptr);
	Data *new_ptr = Serializer::deserialize(raw);
	std::cout << (char *)new_ptr->data << std::endl;
	new_ptr->data = (void *)"Codam";
	std::cout << (char *)d.data << std::endl;
}