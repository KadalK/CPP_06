#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>

#include "Data.hpp"

class Data;


//notion : reinterpret_cast

class Serializer{
public:
	Serializer();
	Serializer(Serializer& );
	Serializer& operator=(Serializer& );


	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	~Serializer();

};

#endif