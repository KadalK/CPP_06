#include "Data.hpp"

Data::Data() {}

Data::Data(std::string str, int n): string(str), num(n) {}

Data::Data(Data& copy) {
	*this = copy;
}

Data& Data::operator=(Data& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Data::getString()
{
	return (this->string);
}

int	Data::getNum(){
	return (this->num);
}

Data::~Data() {}