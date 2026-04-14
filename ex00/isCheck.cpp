#include "isCheck.hpp"

bool hasFloatSuffix(const std::string& str)
{
	if (str.length() > 0 && str[str.length() - 1] == 'f')
		return true;
	return false;
}

bool isNaNFloat(const std::string& str)
{
	return (str == "nanf");
}

bool isInfFloat(const std::string& str)
{
	return (str == "inff" || str == "+inff" || str == "-inff");
}

bool isSpecialFloat(const std::string& str)
{
	return isNaNFloat(str) || isInfFloat(str);
}

bool isNaN(const std::string& str)
{
	return (str == "nan" || isNaNFloat(str));
}

bool isInf(const std::string& str)
{
	return (str == "inf" || str == "+inf" || isInfFloat(str));
}

bool isSpecial(const std::string& str)
{
	return isNaN(str) || isInf(str);
}