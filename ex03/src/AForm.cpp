#include "./include/AForm.hpp"
#include <iostream>

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form not signed";
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}

const std::string& AForm::getName() const {
	return m_name;
}

bool AForm::getIsSigned() const {
	return m_isSigned;
}

int AForm::getGradeToSign() const {
	return m_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return m_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > m_gradeToSign) {
		throw AForm::GradeTooLowException();
	} else {
		m_isSigned = true;
	}
}

void AForm::signForm(const Bureaucrat& b) {
	try {
		beSigned(b);
		std::cout << b.getName() << " signs " << m_name << std::endl;
	} catch (const std::exception& e) {
		std::cout << b.getName() << " cannot sign " << m_name << " because " << e.what() << std::endl;
	}
}

AForm::~AForm() {
}