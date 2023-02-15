#include "./include/Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat b("Bob", 1);
	std::cout << b << std::endl;
	try
	{
		b.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << b << std::endl;
	try
	{
		b.decrementGrade();
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << b << std::endl;
	return 0;
}