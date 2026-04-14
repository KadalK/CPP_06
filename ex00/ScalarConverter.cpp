#include "ScalarConverter.hpp"
#include "isCheck.hpp"
#include <iostream>
#include <iomanip>
#include <limits.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs){
	(void)rhs;
	return *this;
}


bool hasFloatSuffix(const std::string& str);
bool isSpecial(const std::string& str);


//CHAR
void charConvert(std::string str)
{
	char c;

	if (str.length() == 1 && !isdigit(str[0]))
		c = str[0];
	else
	{
		int value;
		std::stringstream ss(str);

		ss >> value;

		if (ss.fail() || !ss.eof())
		{
			std::cout << "char: impossible" << std::endl;
			return;
		}

		if (value < 0 || value > 127)
		{
			std::cout << "char: impossible" << std::endl;
			return;
		}
		c = static_cast<char>(value);
	}

	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

//INT
void intConvert(std::string str)
{
	if (isSpecial(str))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}

	std::string clean = str;

	if (hasFloatSuffix(clean))
		clean = clean.substr(0, clean.length() - 1);

	std::stringstream ss(clean);
	double value;

	ss >> value;

	if (ss.fail() || !ss.eof())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}

	if (value > INT_MAX || value < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}

	if (value != static_cast<int>(value))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}

	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

//FLOAT
void floatConvert(std::string str)
{

	if (isSpecial(str))
	{
		if (isSpecialFloat(str))
		{
			std::cout << "float: " << str << std::endl;
		}
		else
		{
			std::cout << "float: " << str << "f" <<std::endl;
		}
		return;
	}

	if (hasFloatSuffix(str))
		str = str.substr(0, str.length() - 1);

	std::stringstream ss(str);
	float value;

	ss >> value;

	if (ss.fail() || !ss.eof())
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}

	std::cout << "float: " << value;

	if (value == static_cast<int>(value))
		std::cout << ".0";

	std::cout << "f" << std::endl;
}

//DOUBLE
void	doubleConvert(std::string str){
	if (isSpecial(str))
	{
		if (!isSpecialFloat(str))
		{
			std::cout << "double: " << str << std::endl;
		}
		else
		{
			std::string clean = str;
			clean = clean.substr(0, str.length() - 1);
			std::cout << "double: " << clean << std::endl;
		}
		return;
	}

	std::stringstream ss(str);
	double value;
	long long n;

	ss >> value;
	n = value;

	if (ss.fail() || !ss.eof())
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (value -  n < 0.09f)
	{
		std::cout << "double: " << value << ".0" << std::endl;
		return;
	}
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string str){
	charConvert(str);
	intConvert(str);
	floatConvert(str);
	doubleConvert(str);
}

ScalarConverter::~ScalarConverter(){}