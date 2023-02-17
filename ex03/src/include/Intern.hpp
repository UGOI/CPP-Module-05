#pragma once
#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    AForm* makeForm(const std::string& formName, const std::string& target) const;
private:
	std::string m_formNames[3];
    static AForm* createShrubberyCreationForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createPresidentialPardonForm(const std::string& target);
};
