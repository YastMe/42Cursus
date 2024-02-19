/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:38:29 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 18:22:45 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	private:
	public:
		Cure();
		Cure(const Cure &cure);
		~Cure();

		Cure & operator = (const Cure &cure);

		AMateria			*clone(void) const;
		void				use(ICharacter &target);
};

std::ostream & operator << (std::ostream &out, const Cure &cure);

#endif