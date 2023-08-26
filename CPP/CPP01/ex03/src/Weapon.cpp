/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:25:10 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/23 11:40:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {
	std::cout << _type << " sa rompío." << std::endl;
}

void	Weapon::setType(std::string type) {
	_type = type;
}

std::string	Weapon::getType() const {
	return (_type);
}
