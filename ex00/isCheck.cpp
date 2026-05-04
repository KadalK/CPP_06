#include "isCheck.hpp"
#include <cstdlib>

bool hasFloatSuffix(const std::string& str){
	if (str.length() > 0 && str[str.length() - 1] == 'f')
		return true;
	return false;
}

bool isNaNFloat(const std::string& str){
	return (str == "nanf");
}

bool isInfFloat(const std::string& str){
	return (str == "inff" || str == "+inff" || str == "-inff");
}

bool isSpecialFloat(const std::string& str){
	return isNaNFloat(str) || isInfFloat(str);
}

bool isNaN(const std::string& str){
	return (str == "nan" || isNaNFloat(str));
}

bool isInf(const std::string& str){
	return (str == "-inf" || str == "inf" || str == "+inf" || isInfFloat(str));
}

bool isSpecial(const std::string& str){
	if (isNaN(str) || isInf(str))
	{
		double d = std::atof(str.c_str());
		float f = static_cast<float>(d);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" <<std::endl;
		std::cout << "double: " << d << std::endl;
		return(true);
	}
	if (isNaNFloat(str) || isInfFloat(str))
	{
		float f = std::atof(str.c_str());
		double d = static_cast<double>(f);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return(true);
	}

	return(false);
}