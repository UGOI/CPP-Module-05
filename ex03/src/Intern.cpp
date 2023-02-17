#include "./include/Intern.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include <iostream>
#include "./include/AForm.hpp"

Intern::Intern() {
	m_formNames[0] = "shrubbery creation";
	m_formNames[1] = "robotomy request";
	m_formNames[2] = "presidential pardon";
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	for (int i = 0; i < 3; i++) {
		if (formName == m_formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					return createShrubberyCreationForm(target);
				case 1:
					return createRobotomyRequestForm(target);
				case 2:
					return createPresidentialPardonForm(target);
			}
		}
	}
	std::cout << "Intern can't create " << formName << std::endl;
	return NULL;
}
