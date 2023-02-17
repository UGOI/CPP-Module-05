#include "./include/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), m_target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
