/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:05:47 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/18 14:05:50 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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