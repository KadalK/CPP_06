#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <vector>

class ScalarConverter{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter& );
public:
	ScalarConverter& operator=(ScalarConverter& );

	static void	convert(std::string );

	~ScalarConverter();
};

#endif