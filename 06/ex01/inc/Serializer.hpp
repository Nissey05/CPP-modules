#pragma once

#include "data.h"
#include <stdint.h>

class	Serializer
{
	private:
		Serializer() = delete;
	public:
		static uintptr_t  serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};