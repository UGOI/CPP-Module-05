#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat recrute("Loser", 1);
	Bureaucrat Loser("Loser", 150);
	ShrubberyCreationForm shrubberyForm("Shrubbery Form");
	RobotomyRequestForm robotomyForm("Robotomy Form");
	PresidentialPardonForm presidentialForm("Presidential Form");

	std::cout << "Shrubbery Form" << std::endl;
	try
	{
		recrute.signForm(shrubberyForm);
		shrubberyForm.execute(recrute);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << "Robotomy Form" << std::endl;
	try
	{
		recrute.signForm(robotomyForm);
		robotomyForm.execute(recrute);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "Presidential Form" << std::endl;
	try
	{
		recrute.signForm(presidentialForm);
		presidentialForm.execute(recrute);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "Shrubbery Form" << std::endl;
	try
	{
		recrute.signForm(shrubberyForm);
		shrubberyForm.execute(Loser);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "Robotomy Form" << std::endl;
	try
	{
		recrute.signForm(robotomyForm);
		robotomyForm.execute(Loser);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "Presidential Form" << std::endl;
	try
	{
		recrute.signForm(presidentialForm);
		presidentialForm.execute(Loser);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	return 0;

}