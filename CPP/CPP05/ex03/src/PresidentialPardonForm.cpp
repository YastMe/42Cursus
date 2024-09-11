/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:58:32 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 13:00:50 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", _gradeToSign, _gradeToExecute)
{
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", _gradeToSign, _gradeToExecute)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform) : AForm(presidentialpardonform)
{
	*this = presidentialpardonform;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &presidentialpardonform)
{
	if (this != &presidentialpardonform)
		_target = presidentialpardonform.getTarget();
	return (*this);
}

std::string const PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::FormNotSignedException();
	else
		std::cout << _target << " has been pardoned by Zafod Beeblebrox. You're welcome." << std::endl;
}