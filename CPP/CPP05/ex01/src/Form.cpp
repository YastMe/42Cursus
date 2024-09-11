#include "../include/Form.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(Bureaucrat::minGrade), _gradeToExecute(Bureaucrat::minGrade) {}

AForm::AForm(const AForm &form) : _name(form.getName())
{
	*this = form;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name)
{
	if (gradeToSign < Bureaucrat::maxGrade || gradeToExecute < Bureaucrat::maxGrade)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > Bureaucrat::minGrade || gradeToExecute > Bureaucrat::minGrade)
		throw AForm::GradeTooLowException();
	else
	{
		_signed = false;
		_gradeToSign = gradeToSign;
		_gradeToExecute = gradeToExecute;
	}
}

AForm::~AForm() {}

AForm & AForm::operator = (const AForm &form)
{
	if (this != &form)
	{
		_signed = form.getSigned();
		_gradeToSign = form.getGradeToSign();
		_gradeToExecute = form.getGradeToExecute();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << ". Signed: " << form.getSigned() << ". Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << ".";
	return (out);
}

std::string const	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
	{
		_signed = true;
		std::cout << bureaucrat.getName() << " has signed " << getName() << "." << std::endl;
	}
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}
