#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat b("Bob", 1);
	Form f("Form1", 1, 1);
	try
	{
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// try
	// {
	// 	Bureaucrat a("Anna", 0);
	// 	std::cout << a << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }


	return 0;

}