/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:24:31 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 19:44:38 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
		void	randHighFivesMessage(void);
		void	randStartMessage(void);
		void	randDeathMessage(void);
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap &fragtrap);
		~FragTrap();

		FragTrap & operator = (const FragTrap &fragtrap);

		void	highFivesGuys(void);
};

std::ostream & operator << (std::ostream &out, const FragTrap &fragtrap);

#endif