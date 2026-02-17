#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>


Base * generate(void){
	int i;
	srand(time(0));
	i = rand()%3;
	if (i == 0)
		return	new A();
	else if (i == 1)
		return	new B();
	else
		return	new C();
}

void identify(Base& p){
	try
	{
		Base &Aa = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)Aa;
	} catch (std::exception e) {}

	try
	{
		Base &Bb = dynamic_cast<B&>(p);
		(void)Bb;
		std::cout << "B" << std::endl;
	} catch (std::exception e) {}
	try
	{
		Base &Cc = dynamic_cast<C&>(p);
		(void)Cc;
		std::cout << "C" << std::endl;
	} catch (std::exception e) {}
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

int main() {
	Base* base = generate();
	Base& base1 = *base;
	identify(base);
	identify(base1);
	delete base;
	return 0;
}