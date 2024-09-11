/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:48:11 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 13:59:40 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern(){}

Intern & Intern::operator = (const Intern &intern)
{
	(void)intern;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Intern &intern)
{
	(void)intern;
	out << "Interns don't have nor need a name. They are just interns. At least they are not unpaid interns.";
	return (out);
}

static int	nameToForm(std::string name)
{
	if (name == SHRUBBERY_FORM)
		return (SHRUBBERY_FORM_NBR);
	else if (name == ROBOTOMY_FORM)
		return (ROBOTOMY_FORM_NBR);
	else if (name == PRESIDENTIAL_FORM)
		return (PRESIDENTIAL_FORM_NBR);
	throw Intern::FormNotFound();
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int	form = -1;

	try
	{
		form = nameToForm(name);
	}
	catch(const std::exception &e)
	{
		std::cerr << Yellow << e.what() << DEFAULT << std::endl;
		return (NULL);
	}
	switch (form)
	{
		case 0:
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			return (NULL);
	}
}

const char *Intern::FormNotFound::what() const throw()
{
	return ("EXCEPTION: Form not found");
}
