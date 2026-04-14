#include "Data.hpp"

Data::Data() : _string(""), _num(0) {}

Data::Data(std::string str, int n): _string(str), _num(n) {}

Data::Data(Data& copy) {
	*this = copy;
}

Data& Data::operator=(const Data& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Data::getString()
{
	return (this->_string);
}

int	Data::getNum(){
	return (this->_num);
}

Data::~Data() {}