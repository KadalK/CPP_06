#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() : _char('\0') {}

ScalarConverter::ScalarConverter(ScalarConverter& copy) : _char(copy._char) {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& rhs){
	if (this != &rhs)
		this->_char = rhs._char;
	return *this;
}

void	charConvert(std:: string type, int toInt){

		std::cout << "char: '" << type.c_str()[0] << "'" <<std::endl;
		std::cout << "int: " << toInt << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(toInt) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(toInt) << std::endl;
}


void	stringCharConvert(char *endPtr, double res)
{
	if (!*endPtr && (res >= std::numeric_limits<unsigned char>::min() && res <= std::numeric_limits<unsigned char>::max()))
	{
		if (res >= 32 && res < 127)
			std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
		else
			std::cout << "char: Non displayable " << std::endl;
	}
	else
		std::cout << "char: impossible " << std::endl;
}

void	stringIntConvert(char *endPtr, double res)
{
	if (!*endPtr && (res >= std::numeric_limits<int>::min() && res < std::numeric_limits<int>::max()))
		std::cout << "int: " << static_cast<int>(res) << std::endl;
	else
		std::cout << "int: impossible " << std::endl;
}

void	stringFloatConvert(char *endPtr, double res)
{
	if (!*endPtr && (res >= -std::numeric_limits<float>::max() && res < std::numeric_limits<float>::max()))
		std::cout << "float: " << static_cast<float>(res) << "f" << std::endl;
	else
		std::cout << "float: " << " impossible " << std::endl;

}
void	stringDoubleConvert(char *endPtr, double res)
{
	if (!*endPtr && (res >= std::numeric_limits<double>::min() && res < std::numeric_limits<double>::max()))
		std::cout << "double: " << static_cast<double>(res) << std::endl;
	else
		std::cout << "double: " << " impossible " << std::endl;
}

void	setFlag(char *endPtr, double res)
{
	bool precisionFlag = false;
	if (*endPtr == 'f' && !endPtr[1])
		*endPtr = 0;
	if (std::floor(res) == res)
		precisionFlag = true;
	if (precisionFlag)
		std::cout << std::fixed << std::setprecision(1);
}


void	stringConvert(std:: string type, double res)
{
	char *endPtr;


	res = std::strtod(type.c_str(), &endPtr);
	stringCharConvert(endPtr, res);
	stringIntConvert(endPtr, res);
	stringFloatConvert(endPtr, res);
	stringDoubleConvert(endPtr, res);
}

void	ScalarConverter::convert(std::string type){
	int		toInt = 0;
	double	res = 0;

	toInt = static_cast<int>(type.c_str()[0]);
	if (type.length() == 1)
		charConvert(type, toInt);
	else
		stringConvert(type, res);
}

ScalarConverter::~ScalarConverter(){}