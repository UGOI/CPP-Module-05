#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include <iostream>

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : m_name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    m_grade = grade;
}

const std::string& Bureaucrat::getName() const {
    return m_name;
}

int Bureaucrat::getGrade() const {
    return m_grade;
}

void Bureaucrat::incrementGrade() {
    if (m_grade == 1) {
        throw GradeTooHighException();
    }
    m_grade--;
}

void Bureaucrat::decrementGrade() {
    if (m_grade == 150) {
        throw GradeTooLowException();
    }
    m_grade++;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}