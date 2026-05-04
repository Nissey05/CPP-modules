#include "Serializer.hpp"

Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer &cpy) noexcept
{
	(void)cpy;
}

Serializer &Serializer::operator=(const Serializer &cpy) noexcept
{
	(void)cpy;
	return (*this);
}

Serializer::Serializer(Serializer&& other) noexcept
{
	(void)other;
}

Serializer &Serializer::operator=(Serializer&& other) noexcept
{
	(void)other;
	return (*this);
}

uintptr_t  Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}