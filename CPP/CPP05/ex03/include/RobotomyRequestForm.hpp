/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:41:58 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 12:51:29 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <time.h>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string			_target;
		static const int	_gradeToSign = 72;
		static const int	_gradeToExecute = 45;
		static const int	_chance = 50;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator = (const RobotomyRequestForm &robotomyrequestform);

		std::string const	getTarget(void) const;
		void				execute(Bureaucrat const & bureaucrat) const;
};

#endif