#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &serializer);
		~Serializer();
		Serializer & operator = (const Serializer &serializer);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream & operator << (std::ostream &out, const Serializer &serializer);

#endif