/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:59:01 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/11 13:57:26 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA
{
private:
	std::string	_name;
	Weapon		*_weapon;
	HumanA();

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack();
	void	setWeapon(Weapon &weapon);
};

#endif
