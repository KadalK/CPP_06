#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter{
private:
	char _char;
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter& );
	ScalarConverter& operator=(ScalarConverter& );

	static void	convert(std::string );

	~ScalarConverter();
};

#endif