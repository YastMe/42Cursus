/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:05:40 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 12:37:06 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExecute;
	public:
		AForm();
		AForm(const AForm &form);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual	~AForm();
		AForm & operator = (const AForm &form);

		std::string const	&getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & bureaucrat) const = 0;
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream & operator << (std::ostream &out, const AForm &form);

#endif