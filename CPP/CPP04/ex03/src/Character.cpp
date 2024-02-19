/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:46:53 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 18:29:13 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character()
{
	std::cout << "Default constructor called on " << this << std::endl;
	_name = "Generic character";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &character)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	_name = character._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = character._inventory[i];
}

Character::Character(std::string name)
{
	std::cout << "Name constructor called on " << this << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Destructor called on " << this << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character & Character::operator = (const Character &character)
{
	std::cout << "Copy operator called on " << this << std::endl;
	if (this != &character)
	{
		_name = character._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (character._inventory[i])
				_inventory[i] = character._inventory[i];
		}
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;
	do
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
		i++;
	}	while (i < 4);
	if (i == 4)
		std::cout << "Your inventory is full! Try unequiping some materias." << std::endl;
}
void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Index out of bounds, try again." << std::endl;
	else
		_inventory[idx] = NULL;
}
void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Index out of bounds, try again." << std::endl;
	else if (!_inventory[idx])
		std::cout << "Empty slot!" << std::endl;
	else
		_inventory[idx]->use(target);
}

AMateria	*Character::getMateria(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index out of bounds, try again." << std::endl;
		return (NULL);
	}
	else
		return (_inventory[idx]);
}

std::ostream &operator<<(std::ostream &out, const Character &character)
{
	out << "Character [" << character.getName() << "]";
	return (out);
}