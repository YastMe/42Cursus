/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:19:10 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 19:25:38 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		void	randGuardGateMessage(void);
		void	randStartMessage(void);
		void	randDeathMessage(void);
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &scavtrap);
		~ScavTrap();
		
		ScavTrap & operator = (const ScavTrap &scavtrap);
		
		void	attack(const std::string& target);
		void	guardGate(void);
};

std::ostream & operator << (std::ostream &out, const ScavTrap &scavtrap);

#endif