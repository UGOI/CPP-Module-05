#include "./include/RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), m_target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "Some drilling noises..." << std::endl;

    if (std::rand() % 2 == 0) {
        std::cout << m_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << m_target << " failed." << std::endl;
    }
}
