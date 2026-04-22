#pragma once

#include "data.h"
#include <stdint.h>

class	Serializer
{
	private:
		Serializer() = delete;
	public:
		~Serializer();
		Serializer(const Serializer &cpy) noexcept;
		Serializer &operator=(const Serializer &cpy) noexcept;
		Serializer(Serializer&& other) noexcept;
		Serializer& operator=(Serializer&& other) noexcept;
		static uintptr_t  serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};