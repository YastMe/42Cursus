/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:38:34 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 18:22:48 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	private:
	public:
		Ice();
		Ice(const Ice &ice);
		~Ice();
		
		Ice & operator = (const Ice &ice);

		AMateria			*clone(void) const;
		void				use(ICharacter &target);
};

std::ostream & operator << (std::ostream &out, const Ice &ice);

#endif