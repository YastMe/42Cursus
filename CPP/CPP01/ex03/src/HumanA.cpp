/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:03:39 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/23 11:40:07 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon){
	_name = name;
	_weapon = &weapon;
}

HumanA::~HumanA(void) {
	std::cout << _name << " sa morío." << std::endl;
}

void	HumanA::attack(void) {
	if (_weapon != NULL) 
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their bare hands." << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
