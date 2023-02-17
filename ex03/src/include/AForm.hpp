#pragma once
#include <string>
#include <stdexcept>
#include "./Bureaucrat.hpp"

class AForm {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class NotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    virtual ~AForm() = 0;
    virtual const std::string& getName() const;
    virtual bool getIsSigned() const;
    virtual int getGradeToSign() const;
    virtual int getGradeToExecute() const;
	virtual void signForm(const Bureaucrat& b);
    virtual void beSigned(const Bureaucrat& b);
    virtual void execute(const Bureaucrat& executor) const = 0;
private:
    const std::string m_name;
    bool m_isSigned;
    const int m_gradeToSign;
    const int m_gradeToExecute;
};
