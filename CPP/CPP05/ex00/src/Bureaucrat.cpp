#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(Bureaucrat::minGrade){}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat.getName())
{
	*this = bureaucrat;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < Bureaucrat::maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		_grade = bureaucrat.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade <= maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout << getName() << " is being promoted! Good job, " << getName() << ". We expect great things from you." << std::endl;
		_grade--;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade >= minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << getName() << " is being demoted. Shame on you, " << getName() << ". Your incompetence is showing." << std::endl;
		_grade++;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Invalid grade greater than 1.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Invalid grade lower than 150.");
}
