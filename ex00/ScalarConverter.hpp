#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <vector>

class ScalarConverter{
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter& );
	ScalarConverter& operator=(ScalarConverter& );

	static void	convert(std::string );

	~ScalarConverter();
};

void	singleCharConvert(std:: string);

#endif