#include "ScalarConverter.hpp"
#include "isCheck.hpp"
#include <iostream>
#include <iomanip>

bool hasFloatSuffix(const std::string& str);
bool isSpecial(const std::string& str);

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs){
	(void)rhs;
	return *this;
}

static void printer(const char& c, const int& n, const float& f, const double& d){
	if (isdigit(c) || c < 0 || c > 127 )
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << n << std::endl;
	if (n - d == 0 && d >= -100000 && d <= 100000)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

static bool isChar(const std::string& str){
	const char c = str[0];

	if (str.length() > 1 || isdigit(c) || c < 0 || c > 127 )
		return (false);

	const int n = static_cast<int>(c);
	const float f = static_cast<float>(c);
	const double d = static_cast<double>(c);
	printer(c, n, f, d);
	return (true);
}

static bool isInt(const std::string& str){
	std::stringstream ss(str);
	int n;

	ss >> n;
	if (ss.fail() || !ss.eof())
		return (false);
	const char c = static_cast<char>(n);
	const float f = static_cast<float>(n);
	const double d = static_cast<double>(n);
	printer(c, n, f, d);

	return (true);
}

static bool isFloat(const std::string& str){
	if (!hasFloatSuffix(str))
		return (false);
	std::stringstream ss(str.substr(0, str.length() - 1));
	float f;

	ss >> f;
	if (ss.fail() || !ss.eof())
		return (false);
	const char c = static_cast<char>(f);
	const int n = static_cast<int>(f);
	const double d = static_cast<double>(f);
	printer(c, n, f, d);

	return (true);
}

static bool isDouble(const std::string& str){
	std::stringstream ss(str);
	double d;

	ss >> d;
	if (ss.fail() || !ss.eof())
		return (false);
	const char c = static_cast<char>(d);
	const int n = static_cast<int>(d);
	const float f = static_cast<float>(d);
	printer(c, n, f, d);

	return (true);
}

void ScalarConverter::convert(const std::string& str){
	isChar(str)|| isInt(str) || isFloat(str) || isDouble(str) || isSpecial(str);
}

ScalarConverter::~ScalarConverter(){}