#ifndef DATA_HPP
#define DATA_HPP
#include <stdint.h>
#include <iostream>

class Data{
private:
	std::string	_string;
	int			_num;
public:
	Data();
	Data(std::string , int );
	Data(Data& );
	Data& operator=(const Data& );

	std::string	getString();
	int			getNum();

	~Data();
};

#endif