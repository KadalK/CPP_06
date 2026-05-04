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
	ScalarConverter& operator=(const ScalarConverter& );
public:
	static void	convert(const std::string& );
	~ScalarConverter();
};

#endif