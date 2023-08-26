/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:25:06 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/11 13:40:36 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
public:
	Weapon(std::string type);
	~Weapon();
	void	setType(std::string type);
	std::string	getType() const;

private:
	std::string	_type;
};

#endif