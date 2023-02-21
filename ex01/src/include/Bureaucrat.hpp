#pragma once
#include <string>
#include <stdexcept>
#include "./Bureaucrat.hpp"

class Form;

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    Bureaucrat(const std::string& name, int grade);
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
	void signForm(Form& form);

private:
    const std::string m_name;
    int m_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);