/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:58:29 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 12:58:30 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string			_target;
		static const int	_gradeToSign = 25;
		static const int	_gradeToExecute = 5;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator = (const PresidentialPardonForm &presidentialpardonform);

		std::string const	getTarget(void) const;
		void				execute(Bureaucrat const & bureaucrat) const;
};

std::ostream & operator << (std::ostream &out, const PresidentialPardonForm &presidentialpardonform);

#endif