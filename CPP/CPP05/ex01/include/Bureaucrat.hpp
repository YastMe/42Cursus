/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:05:42 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 12:08:52 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat & operator = (const Bureaucrat &bureaucrat);

		std::string const	&getName(void) const;
		int					getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(AForm &form);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		static int const	maxGrade = 1;
		static int const	minGrade = 150;
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif