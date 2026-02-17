#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>



int main()
{
	Data();
	Serializer();

	Data *data = new Data("prout", 42);

	uintptr_t ptr = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(ptr);
	std::cout << serialized->getString() << std::endl;
	std::cout << serialized->getNum() << std::endl;

}