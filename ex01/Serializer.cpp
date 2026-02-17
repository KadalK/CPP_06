#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(Serializer& copy){
	*this = copy;
}

Serializer& Serializer::operator=(Serializer& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

Serializer::~Serializer(){}