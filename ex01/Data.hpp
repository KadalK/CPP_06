#ifndef DATA_HPP
#define DATA_HPP
#include <stdint.h>
#include <iostream>

class Data{
private:
	std::string	string;
	int			num;
public:
	Data();
	Data(std::string , int );
	Data(Data& );
	Data& operator=(Data& );

	std::string	getString();
	int	getNum();

	~Data();
};

#endif