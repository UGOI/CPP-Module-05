#pragma once
#include <string>
#include <stdexcept>
#include "./Bureaucrat.hpp"

class Form {
public:
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& b);
	void signForm(const Bureaucrat& b);

private:
	const std::string m_name;
	bool m_isSigned;
	const int m_gradeToSign;
	const int m_gradeToExecute;
};

