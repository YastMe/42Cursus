/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:43:24 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 12:59:20 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", RobotomyRequestForm::_gradeToSign, RobotomyRequestForm::_gradeToExecute)
{
	_target = "default_file";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", RobotomyRequestForm::_gradeToSign, RobotomyRequestForm::_gradeToExecute)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform) : AForm(robotomyrequestform)
{
	*this = robotomyrequestform;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &robotomyrequestform)
{
	if (this != &robotomyrequestform)
		_target = robotomyrequestform._target;
	return (*this);
}

std::string const RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::FormNotSignedException();
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 100 < RobotomyRequestForm::_chance)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << "'s robotomization failed. " << _target << " will be missed. Maybe. Probably not." << std::endl;
}
