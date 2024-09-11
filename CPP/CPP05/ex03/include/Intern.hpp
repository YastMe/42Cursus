/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:48:05 by abeltran          #+#    #+#             */
/*   Updated: 2024/07/08 18:10:22 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define PRESIDENTIAL_FORM_NBR 0
# define ROBOTOMY_FORM_NBR 1
# define SHRUBBERY_FORM_NBR 2

# define PRESIDENTIAL_FORM "presidential pardon"
# define ROBOTOMY_FORM "robotomy request"
# define SHRUBBERY_FORM "shrubbery creation"

# define RED "\033[1;31m"
# define DEFAULT "\033[0m"

class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		Intern & operator = (const Intern &intern);

		AForm *makeForm(std::string name, std::string target);

		class FormNotFound : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator << (std::ostream &out, const Intern &intern);

#endif
