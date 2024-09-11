/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:12:06 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 12:41:53 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <time.h>
# include <cstdlib>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string			_target;
		static const int	_gradeToSign = 145;
		static const int	_gradeToExecute = 137;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform);
		~ShrubberyCreationForm();
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm &shrubberycreationform);

		std::string const	getTarget(void) const;
		void				execute(Bureaucrat const & bureaucrat) const;
};

#endif