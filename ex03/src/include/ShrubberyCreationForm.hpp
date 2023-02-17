#pragma once
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string& target);
    virtual void execute(const Bureaucrat& executor) const;
private:
    const std::string m_target;
};