#include "./include/Form.hpp"
#include "./include/Bureaucrat.hpp"
#include <iostream>

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
}

const std::string& Form::getName() const {
	return m_name;
}

bool Form::getIsSigned() const {
	return m_isSigned;
}

int Form::getGradeToSign() const {
	return m_gradeToSign;
}

int Form::getGradeToExecute() const {
	return m_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > m_gradeToSign) {
		throw Form::GradeTooLowException();
	} else {
		m_isSigned = true;
	}
}
