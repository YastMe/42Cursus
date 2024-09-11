/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:36:06 by abeltran          #+#    #+#             */
/*   Updated: 2024/07/08 18:09:44 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{
	Intern intern;
	AForm *presidential;
	AForm *robotomy;
	AForm *shrubbery;
	AForm *error;

	presidential = intern.makeForm(PRESIDENTIAL_FORM, "target");
	robotomy = intern.makeForm(ROBOTOMY_FORM, "target");
	shrubbery = intern.makeForm(SHRUBBERY_FORM, "target");
	error = intern.makeForm("random", "target");

	delete presidential;
	delete robotomy;
	delete shrubbery;
	delete error;

	return (0);
}

