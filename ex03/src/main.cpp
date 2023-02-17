#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/Intern.hpp"
#include <iostream>

int main() {

    Intern someRandomIntern;
	Bureaucrat Bob("Bob", 1);
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf != NULL) {
        std::cout << "Intern creates " << rrf->getName() << " form" << std::endl;
        rrf->beSigned(Bob);
        rrf->execute(Bob);
        delete rrf;
    }
    else {
        std::cout << "Error: form doesn't exist" << std::endl;
    }
    return 0;
}

