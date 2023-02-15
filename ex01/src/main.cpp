#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat b("Bob", 1);
	Form f("Form1", 1, 1);
	f.signForm(b);
	return 0;

}