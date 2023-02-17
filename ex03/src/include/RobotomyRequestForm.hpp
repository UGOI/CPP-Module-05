#pragma once
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string& target);
    virtual void execute(const Bureaucrat& executor) const;
private:
    const std::string m_target;
};