#ifndef DATA_HPP
#define DATA_HPP
#include <stdint.h>

class Data{
public:
	Data();
	Data(Data& );
	Data& operator=(Data& );

	~Data();
};

#endif