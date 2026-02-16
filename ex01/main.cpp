#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data();
	Serializer();

	uintptr_t ptr = 422;
	Serializer *serial = 0;
	Data *data = 0;

	std::cout << serial->serialize(data) << std::endl;
	std::cout << serial->deserialize(ptr) << std::endl;

}